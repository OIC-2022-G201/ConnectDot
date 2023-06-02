// @PhysicsDynamicTree.h
// @brief
// @author かき氷氷味
// @date 2022/10/16
//
// @details

#pragma once
#include <cstdint>
#include <stack>

#include "PhysicsCollision.h"
#include "PhysicsCommon.h"
#include "PhysicsComponentData.h"
namespace base_engine::physics {
template <class T>
concept HasQueryCallback = requires(T* x, int32_t id) {
  x->QueryCallback(id);
};
template <class T>
concept HasRayCastCallback = requires(T& x, int32_t id,
                                      PhysicsRayCastInput input) {
  x.RayCastCallback(input, id);
};
constexpr int32_t Physics_nullNode = -1;
struct PhysicsTreeNode {
  [[nodiscard]] bool IsLeaf() const noexcept { return child1 == Physics_nullNode; }

  /// Enlarged AABB
  PhysicsAABB aabb;

  void* userData;

  union {
    int32_t parent;
    int32_t next;
  };

  int32_t child1;
  int32_t child2;

  // leaf = 0, free node = -1
  int32_t height;

  bool moved;
};
class PhysicsDynamicTree {
 public:
  /// Constructing the tree initializes the node pool.
  PhysicsDynamicTree() {
    m_root = Physics_nullNode;

    m_nodeCapacity = 16;
    m_nodeCount = 0;
    m_nodes =
        static_cast<PhysicsTreeNode*>(malloc(m_nodeCapacity * sizeof(PhysicsTreeNode)));
    memset(m_nodes, 0, m_nodeCapacity * sizeof(PhysicsTreeNode));

    // Build a linked list for the free list.
    for (int32_t i = 0; i < m_nodeCapacity - 1; ++i) {
      m_nodes[i].next = i + 1;
      m_nodes[i].height = -1;
    }
    m_nodes[m_nodeCapacity - 1].next = Physics_nullNode;
    m_nodes[m_nodeCapacity - 1].height = -1;
    m_freeList = 0;

    m_insertionCount = 0;
  }

  /// Destroy the tree, freeing the node pool.
  ~PhysicsDynamicTree() { free(m_nodes); }

  /// Create a proxy. Provide a tight fitting AABB and a userData pointer.
  int32_t CreateProxy(const PhysicsAABB& aabb, void* userData) {
    int32_t proxyId = AllocateNode();

    // Fatten the aabb.
    PVec2 r(kAABBExtension, kAABBExtension);
    m_nodes[proxyId].aabb.lowerBound = aabb.lowerBound - r;
    m_nodes[proxyId].aabb.upperBound = aabb.upperBound + r;
    m_nodes[proxyId].userData = userData;
    m_nodes[proxyId].height = 0;
    m_nodes[proxyId].moved = true;

    InsertLeaf(proxyId);

    return proxyId;
  }

  /// Destroy a proxy. This asserts if the id is invalid.
  void DestroyProxy(int32_t proxyId) {
    RemoveLeaf(proxyId);
    FreeNode(proxyId);
  }

  /// Move a proxy with a swepted AABB. If the proxy has moved outside of its
  /// fattened AABB, then the proxy is removed from the tree and re-inserted.
  /// Otherwise the function returns immediately.
  /// @return true if the proxy was re-inserted.
  bool MoveProxy(int32_t proxyId, const PhysicsAABB& aabb,
                 const PVec2& displacement) {
    // Extend AABB
    PhysicsAABB fatAABB;
    constexpr PVec2 r(kAABBExtension, kAABBExtension);
    fatAABB.lowerBound = aabb.lowerBound - r;
    fatAABB.upperBound = aabb.upperBound + r;

    // Predict AABB movement
    PVec2 d = kAABBMultiplier * displacement;

    if (d.x < 0.0f) {
      fatAABB.lowerBound.x += d.x;
    } else {
      fatAABB.upperBound.x += d.x;
    }

    if (d.y < 0.0f) {
      fatAABB.lowerBound.y += d.y;
    } else {
      fatAABB.upperBound.y += d.y;
    }

    if (const PhysicsAABB& tree_aabb = m_nodes[proxyId].aabb;
        tree_aabb.Contains(aabb)) {
      // The tree AABB still contains the object, but it might be too large.
      // Perhaps the object was moving fast but has since gone to sleep.
      // The huge AABB is larger than the new fat AABB.
      PhysicsAABB huge_aabb{};
      huge_aabb.lowerBound = fatAABB.lowerBound - 4.0f * r;
      huge_aabb.upperBound = fatAABB.upperBound + 4.0f * r;

      if (huge_aabb.Contains(tree_aabb)) {
        // The tree AABB contains the object AABB and the tree AABB is
        // not too large. No tree update needed.
        return false;
      }

      // Otherwise the tree AABB is huge and needs to be shrunk
    }

    RemoveLeaf(proxyId);

    m_nodes[proxyId].aabb = fatAABB;

    InsertLeaf(proxyId);

    m_nodes[proxyId].moved = true;

    return true;
  }

  /// Get proxy user data.
  /// @return the proxy user data or 0 if the id is invalid.
  [[nodiscard]] void* GetUserData(int32_t proxyId) const {
    return m_nodes[proxyId].userData;
  }

  bool WasMoved(int32_t proxyId) const noexcept {
    return m_nodes[proxyId].moved;
  }
  void ClearMoved(int32_t proxyId) const noexcept {
    m_nodes[proxyId].moved = false;
  }

  /// Get the fat AABB for a proxy.
  const PhysicsAABB& GetFatAABB(int32_t proxyId) const noexcept {
    return m_nodes[proxyId].aabb;
  }

  /// Query an AABB for overlapping proxies. The callback class
  /// is called for each proxy that overlaps the supplied AABB.
  template <HasQueryCallback T>
  void Query(T* callback, const PhysicsAABB& aabb) const {
    std::stack<int32_t> stack;
    stack.push(m_root);

    while (!stack.empty()) {
      int32_t node_id = stack.top();
      stack.pop();
      if (node_id == Physics_nullNode) {
        continue;
      }

      const PhysicsTreeNode* node = m_nodes + node_id;

      if (!PhysicsTestOverlap(node->aabb, aabb)) continue;
      if (node->IsLeaf()) {
        if (const bool proceed = callback->QueryCallback(node_id);
            proceed == false) {
          return;
        }
      } else {
        stack.push(node->child1);
        stack.push(node->child2);
      }
    }
  }

  /// Ray-cast against the proxies in the tree. This relies on the callback
  /// to perform a exact ray-cast in the case were the proxy contains a shape.
  /// The callback also performs the any collision filtering. This has
  /// performance roughly equal to k * log(n), where k is the number of
  /// collisions and n is the number of proxies in the tree.
  /// @param input the ray-cast input data. The ray extends from p1 to p1 +
  /// maxFraction * (p2 - p1).
  /// @param callback a callback class that is called for each proxy that is hit
  /// by the ray.
  template <HasRayCastCallback T>
  void RayCast(T* callback, const PhysicsRayCastInput& input) const {
    const PVec2 p1 = input.p1;
    const PVec2 p2 = input.p2;
    PVec2 r = p2 - p1;
    r.Normalize();

    // v is perpendicular to the segment.
    const PVec2 v = PhysicsCross(1.0f, r);
    const PVec2 abs_v = PhysicsAbs(v);

    // Separating axis for segment (Gino, p80).
    // |dot(v, p1 - c)| > dot(|v|, h)

    float max_fraction = input.maxFraction;

    // Build a bounding box for the segment.
    PhysicsAABB segmentAABB;
    {
      const PVec2 t = p1 + max_fraction * (p2 - p1);
      segmentAABB.lowerBound = PhysicsMin(p1, t);
      segmentAABB.upperBound = PhysicsMax(p1, t);
    }

    std::stack<int32_t> stack;
    stack.push(m_root);

    while (!stack.empty()) {
      int32_t nodeId = stack.top();
      stack.pop();
      if (nodeId == Physics_nullNode) {
        continue;
      }

      const PhysicsTreeNode* node = m_nodes + nodeId;

      if (PhysicsTestOverlap(node->aabb, segmentAABB) == false) {
        continue;
      }

      // Separating axis for segment (Gino, p80).
      // |dot(v, p1 - c)| > dot(|v|, h)
      PVec2 c = node->aabb.GetCenter();
      PVec2 h = node->aabb.GetExtents();
      if (const float separation =
              PhysicsAbs(PhysicsDot(v, p1 - c)) - PhysicsDot(abs_v, h);
          separation > 0.0f) {
        continue;
      }

      if (node->IsLeaf()) {
        PhysicsRayCastInput sub_input;
        sub_input.p1 = input.p1;
        sub_input.p2 = input.p2;
        sub_input.maxFraction = max_fraction;

        const float value = callback->RayCastCallback(sub_input, nodeId);

        if (value == 0.0f) {
          // The client has terminated the ray cast.
          return;
        }

        if (value > 0.0f) {
          // Update segment bounding box.
          max_fraction = value;
          PVec2 t = p1 + max_fraction * (p2 - p1);
          segmentAABB.lowerBound = PhysicsMin(p1, t);
          segmentAABB.upperBound = PhysicsMax(p1, t);
        }
      } else {
        stack.push(node->child1);
        stack.push(node->child2);
      }
    }
  }

  /// Compute the height of the binary tree in O(N) time. Should not be
  /// called often.
  int32_t GetHeight() const {
    if (m_root == Physics_nullNode) {
      return 0;
    }

    return m_nodes[m_root].height;
  }

  /// Get the maximum balance of an node in the tree. The balance is the
  /// difference in height of the two children of a node.
  int32_t GetMaxBalance() const {
    int32_t maxBalance = 0;
    for (int32_t i = 0; i < m_nodeCapacity; ++i) {
      const PhysicsTreeNode* node = m_nodes + i;
      if (node->height <= 1) {
        continue;
      }

      int32_t child1 = node->child1;
      int32_t child2 = node->child2;
      int32_t balance =
          PhysicsAbs(m_nodes[child2].height - m_nodes[child1].height);
      maxBalance = PhysicsMax(maxBalance, balance);
    }

    return maxBalance;
  }

  /// Get the ratio of the sum of the node areas to the root area.
  [[nodiscard]] float GetAreaRatio() const {
    if (m_root == Physics_nullNode) {
      return 0.0f;
    }

    const PhysicsTreeNode* root = m_nodes + m_root;
    float rootArea = root->aabb.GetPerimeter();

    float totalArea = 0.0f;
    for (int32_t i = 0; i < m_nodeCapacity; ++i) {
      const PhysicsTreeNode* node = m_nodes + i;
      if (node->height < 0) {
        // Free node in pool
        continue;
      }

      totalArea += node->aabb.GetPerimeter();
    }

    return totalArea / rootArea;
  }

  void RebuildBottomUp() {
    int32_t* nodes = (int32_t*)malloc(m_nodeCount * sizeof(int32_t));
    int32_t count = 0;

    // Build array of leaves. Free the rest.
    for (int32_t i = 0; i < m_nodeCapacity; ++i) {
      if (m_nodes[i].height < 0) {
        // free node in pool
        continue;
      }

      if (m_nodes[i].IsLeaf()) {
        m_nodes[i].parent = Physics_nullNode;
        nodes[count] = i;
        ++count;
      } else {
        FreeNode(i);
      }
    }

    while (count > 1) {
      float minCost = std::numeric_limits<float>::max();
      int32_t iMin = -1, jMin = -1;
      for (int32_t i = 0; i < count; ++i) {
        PhysicsAABB aabbi = m_nodes[nodes[i]].aabb;

        for (int32_t j = i + 1; j < count; ++j) {
          PhysicsAABB aabbj = m_nodes[nodes[j]].aabb;
          PhysicsAABB b;
          b.Combine(aabbi, aabbj);
          float cost = b.GetPerimeter();
          if (cost < minCost) {
            iMin = i;
            jMin = j;
            minCost = cost;
          }
        }
      }

      int32_t index1 = nodes[iMin];
      int32_t index2 = nodes[jMin];
      PhysicsTreeNode* child1 = m_nodes + index1;
      PhysicsTreeNode* child2 = m_nodes + index2;

      int32_t parentIndex = AllocateNode();
      PhysicsTreeNode* parent = m_nodes + parentIndex;
      parent->child1 = index1;
      parent->child2 = index2;
      parent->height = 1 + PhysicsMax(child1->height, child2->height);
      parent->aabb.Combine(child1->aabb, child2->aabb);
      parent->parent = Physics_nullNode;

      child1->parent = parentIndex;
      child2->parent = parentIndex;

      nodes[jMin] = nodes[count - 1];
      nodes[iMin] = parentIndex;
      --count;
    }

    m_root = nodes[0];
    free(nodes);
  }

  void Validate() {
#if defined(PHYSICS_DEBUG)
    ValidateStructure(m_root);
    ValidateMetrics(m_root);

    int32_t freeCount = 0;
    int32_t freeIndex = m_freeList;
    while (freeIndex != Physics_nullNode) {
      freeIndex = m_nodes[freeIndex].next;
      ++freeCount;
    }

#endif
  }

  void ShiftOrigin(const PVec2& newOrigin) {
    // Build array of leaves. Free the rest.
    for (int32_t i = 0; i < m_nodeCapacity; ++i) {
      m_nodes[i].aabb.lowerBound -= newOrigin;
      m_nodes[i].aabb.upperBound -= newOrigin;
    }
  }

 private:
  int32_t AllocateNode() {
    // Expand the node pool as needed.
    if (m_freeList == Physics_nullNode) {
      // The free list is empty. Rebuild a bigger pool.
      PhysicsTreeNode* oldNodes = m_nodes;
      m_nodeCapacity *= 2;
      m_nodes =
          static_cast<PhysicsTreeNode*>(malloc(m_nodeCapacity * sizeof(PhysicsTreeNode)));
      memcpy(m_nodes, oldNodes, m_nodeCount * sizeof(PhysicsTreeNode));
      free(oldNodes);

      // Build a linked list for the free list. The parent
      // pointer becomes the "next" pointer.
      for (int32_t i = m_nodeCount; i < m_nodeCapacity - 1; ++i) {
        m_nodes[i].next = i + 1;
        m_nodes[i].height = -1;
      }
      m_nodes[m_nodeCapacity - 1].next = Physics_nullNode;
      m_nodes[m_nodeCapacity - 1].height = -1;
      m_freeList = m_nodeCount;
    }

    // Peel a node off the free list.
    const int32_t nodeId = m_freeList;
    m_freeList = m_nodes[nodeId].next;
    m_nodes[nodeId].parent = Physics_nullNode;
    m_nodes[nodeId].child1 = Physics_nullNode;
    m_nodes[nodeId].child2 = Physics_nullNode;
    m_nodes[nodeId].height = 0;
    m_nodes[nodeId].userData = nullptr;
    m_nodes[nodeId].moved = false;
    ++m_nodeCount;
    return nodeId;
  }
  void FreeNode(int32_t nodeId) {
    m_nodes[nodeId].next = m_freeList;
    m_nodes[nodeId].height = -1;
    m_freeList = nodeId;
    --m_nodeCount;
  }

  void InsertLeaf(int32_t leaf) {
    ++m_insertionCount;

    if (m_root == Physics_nullNode) {
      m_root = leaf;
      m_nodes[m_root].parent = Physics_nullNode;
      return;
    }

    // Find the best sibling for this node
    PhysicsAABB leafAABB = m_nodes[leaf].aabb;
    int32_t index = m_root;
    while (m_nodes[index].IsLeaf() == false) {
      int32_t child1 = m_nodes[index].child1;
      int32_t child2 = m_nodes[index].child2;

      float area = m_nodes[index].aabb.GetPerimeter();

      PhysicsAABB combinedAABB;
      combinedAABB.Combine(m_nodes[index].aabb, leafAABB);
      float combinedArea = combinedAABB.GetPerimeter();

      // Cost of creating a new parent for this node and the new leaf
      float cost = 2.0f * combinedArea;

      // Minimum cost of pushing the leaf further down the tree
      float inheritanceCost = 2.0f * (combinedArea - area);

      // Cost of descending into child1
      float cost1;
      if (m_nodes[child1].IsLeaf()) {
        PhysicsAABB aabb;
        aabb.Combine(leafAABB, m_nodes[child1].aabb);
        cost1 = aabb.GetPerimeter() + inheritanceCost;
      } else {
        PhysicsAABB aabb;
        aabb.Combine(leafAABB, m_nodes[child1].aabb);
        float oldArea = m_nodes[child1].aabb.GetPerimeter();
        float newArea = aabb.GetPerimeter();
        cost1 = (newArea - oldArea) + inheritanceCost;
      }

      // Cost of descending into child2
      float cost2;
      if (m_nodes[child2].IsLeaf()) {
        PhysicsAABB aabb;
        aabb.Combine(leafAABB, m_nodes[child2].aabb);
        cost2 = aabb.GetPerimeter() + inheritanceCost;
      } else {
        PhysicsAABB aabb;
        aabb.Combine(leafAABB, m_nodes[child2].aabb);
        float oldArea = m_nodes[child2].aabb.GetPerimeter();
        float newArea = aabb.GetPerimeter();
        cost2 = newArea - oldArea + inheritanceCost;
      }

      // Descend according to the minimum cost.
      if (cost < cost1 && cost < cost2) {
        break;
      }

      // Descend
      if (cost1 < cost2) {
        index = child1;
      } else {
        index = child2;
      }
    }

    int32_t sibling = index;

    // Create a new parent.
    int32_t oldParent = m_nodes[sibling].parent;
    int32_t newParent = AllocateNode();
    m_nodes[newParent].parent = oldParent;
    m_nodes[newParent].userData = nullptr;
    m_nodes[newParent].aabb.Combine(leafAABB, m_nodes[sibling].aabb);
    m_nodes[newParent].height = m_nodes[sibling].height + 1;

    if (oldParent != Physics_nullNode) {
      // The sibling was not the root.
      if (m_nodes[oldParent].child1 == sibling) {
        m_nodes[oldParent].child1 = newParent;
      } else {
        m_nodes[oldParent].child2 = newParent;
      }

      m_nodes[newParent].child1 = sibling;
      m_nodes[newParent].child2 = leaf;
      m_nodes[sibling].parent = newParent;
      m_nodes[leaf].parent = newParent;
    } else {
      // The sibling was the root.
      m_nodes[newParent].child1 = sibling;
      m_nodes[newParent].child2 = leaf;
      m_nodes[sibling].parent = newParent;
      m_nodes[leaf].parent = newParent;
      m_root = newParent;
    }

    // Walk back up the tree fixing heights and AABBs
    index = m_nodes[leaf].parent;
    while (index != Physics_nullNode) {
      index = Balance(index);

      int32_t child1 = m_nodes[index].child1;
      int32_t child2 = m_nodes[index].child2;

      m_nodes[index].height =
          1 + PhysicsMax(m_nodes[child1].height, m_nodes[child2].height);
      m_nodes[index].aabb.Combine(m_nodes[child1].aabb, m_nodes[child2].aabb);

      index = m_nodes[index].parent;
    }
  }
  void RemoveLeaf(int32_t leaf) {
    if (leaf == m_root) {
      m_root = Physics_nullNode;
      return;
    }

    int32_t parent = m_nodes[leaf].parent;
    int32_t grandParent = m_nodes[parent].parent;
    int32_t sibling;
    if (m_nodes[parent].child1 == leaf) {
      sibling = m_nodes[parent].child2;
    } else {
      sibling = m_nodes[parent].child1;
    }

    if (grandParent != Physics_nullNode) {
      // Destroy parent and connect sibling to grandParent.
      if (m_nodes[grandParent].child1 == parent) {
        m_nodes[grandParent].child1 = sibling;
      } else {
        m_nodes[grandParent].child2 = sibling;
      }
      m_nodes[sibling].parent = grandParent;
      FreeNode(parent);

      // Adjust ancestor bounds.
      int32_t index = grandParent;
      while (index != Physics_nullNode) {
        index = Balance(index);

        int32_t child1 = m_nodes[index].child1;
        int32_t child2 = m_nodes[index].child2;

        m_nodes[index].aabb.Combine(m_nodes[child1].aabb, m_nodes[child2].aabb);
        m_nodes[index].height =
            1 + PhysicsMax(m_nodes[child1].height, m_nodes[child2].height);

        index = m_nodes[index].parent;
      }
    } else {
      m_root = sibling;
      m_nodes[sibling].parent = Physics_nullNode;
      FreeNode(parent);
    }
  }

  int32_t Balance(int32_t iA) {
    PhysicsTreeNode* A = m_nodes + iA;
    if (A->IsLeaf() || A->height < 2) {
      return iA;
    }

    int32_t iB = A->child1;
    int32_t iC = A->child2;

    PhysicsTreeNode* B = m_nodes + iB;
    PhysicsTreeNode* C = m_nodes + iC;

    int32_t balance = C->height - B->height;

    // Rotate C up
    if (balance > 1) {
      int32_t iF = C->child1;
      int32_t iG = C->child2;
      PhysicsTreeNode* F = m_nodes + iF;
      PhysicsTreeNode* G = m_nodes + iG;

      // Swap A and C
      C->child1 = iA;
      C->parent = A->parent;
      A->parent = iC;

      // A's old parent should point to C
      if (C->parent != Physics_nullNode) {
        if (m_nodes[C->parent].child1 == iA) {
          m_nodes[C->parent].child1 = iC;
        } else {
          m_nodes[C->parent].child2 = iC;
        }
      } else {
        m_root = iC;
      }

      // Rotate
      if (F->height > G->height) {
        C->child2 = iF;
        A->child2 = iG;
        G->parent = iA;
        A->aabb.Combine(B->aabb, G->aabb);
        C->aabb.Combine(A->aabb, F->aabb);

        A->height = 1 + PhysicsMax(B->height, G->height);
        C->height = 1 + PhysicsMax(A->height, F->height);
      } else {
        C->child2 = iG;
        A->child2 = iF;
        F->parent = iA;
        A->aabb.Combine(B->aabb, F->aabb);
        C->aabb.Combine(A->aabb, G->aabb);

        A->height = 1 + PhysicsMax(B->height, F->height);
        C->height = 1 + PhysicsMax(A->height, G->height);
      }

      return iC;
    }

    // Rotate B up
    if (balance < -1) {
      int32_t iD = B->child1;
      int32_t iE = B->child2;
      PhysicsTreeNode* D = m_nodes + iD;
      PhysicsTreeNode* E = m_nodes + iE;

      // Swap A and B
      B->child1 = iA;
      B->parent = A->parent;
      A->parent = iB;

      // A's old parent should point to B
      if (B->parent != Physics_nullNode) {
        if (m_nodes[B->parent].child1 == iA) {
          m_nodes[B->parent].child1 = iB;
        } else {
          m_nodes[B->parent].child2 = iB;
        }
      } else {
        m_root = iB;
      }

      // Rotate
      if (D->height > E->height) {
        B->child2 = iD;
        A->child1 = iE;
        E->parent = iA;
        A->aabb.Combine(C->aabb, E->aabb);
        B->aabb.Combine(A->aabb, D->aabb);

        A->height = 1 + PhysicsMax(C->height, E->height);
        B->height = 1 + PhysicsMax(A->height, D->height);
      } else {
        B->child2 = iE;
        A->child1 = iD;
        D->parent = iA;
        A->aabb.Combine(C->aabb, D->aabb);
        B->aabb.Combine(A->aabb, E->aabb);

        A->height = 1 + PhysicsMax(C->height, D->height);
        B->height = 1 + PhysicsMax(A->height, E->height);
      }

      return iB;
    }

    return iA;
  }

  int32_t ComputeHeight() const {
    const int32_t height = ComputeHeight(m_root);
    return height;
  }
  int32_t ComputeHeight(int32_t nodeId) const {
    PhysicsTreeNode* node = m_nodes + nodeId;

    if (node->IsLeaf()) {
      return 0;
    }

    int32_t height1 = ComputeHeight(node->child1);
    int32_t height2 = ComputeHeight(node->child2);
    return 1 + PhysicsMax(height1, height2);
  }

  void ValidateStructure(int32_t index) const;
  void ValidateMetrics(int32_t index) const;

  int32_t m_root;

  PhysicsTreeNode* m_nodes;
  int32_t m_nodeCount;
  int32_t m_nodeCapacity;

  int32_t m_freeList;

  int32_t m_insertionCount;
};
}  // namespace base_engine::physics
