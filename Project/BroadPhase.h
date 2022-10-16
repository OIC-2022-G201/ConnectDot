// @BroadPhase.h
// @brief
// @author かき氷氷味
// @date 2022/10/11
//
// @details

#pragma once
#include <cstdint>
#include <utility>

#include "PhysicsCollision.h"
#include "PhysicsDynamicTree.h"

namespace base_engine::physics::bp {
using b2Pair = std::pair<int32_t, int32_t>;
constexpr int32_t kNullProxy = -1;
using int32 = int32_t;
template <class T>
concept HasAddPairs = requires(T& x, void* a, void* b) {
  x.AddPair(a, b);
};
class BroadPhase {
  BroadPhase() {
    m_proxyCount = 0;

    m_pairCapacity = 16;
    m_pairCount = 0;
    m_pairBuffer =
        static_cast<b2Pair*>(malloc(m_pairCapacity * sizeof(b2Pair)));

    m_moveCapacity = 16;
    m_moveCount = 0;
    m_moveBuffer =
        static_cast<int32_t*>(malloc(m_moveCapacity * sizeof(int32_t)));
  }
  ~BroadPhase() {
    free(m_moveBuffer);
    free(m_pairBuffer);
  }

  /// Create a proxy with an initial AABB. Pairs are not reported until
  /// UpdatePairs is called.
  int32_t CreateProxy(const PhysicsAABB& aabb, void* userData) {
    int32 proxyId = m_tree.CreateProxy(aabb, userData);
    ++m_proxyCount;
    BufferMove(proxyId);
    return proxyId;
  }

  /// Destroy a proxy. It is up to the client to remove any pairs.
  void DestroyProxy(int32_t proxyId) {
    UnBufferMove(proxyId);
    --m_proxyCount;
    m_tree.DestroyProxy(proxyId);
  }

  /// Call MoveProxy as many times as you like, then when you are done
  /// call UpdatePairs to finalized the proxy pairs (for your time step).
  void MoveProxy(int32_t proxyId, const PhysicsAABB& aabb,
                 const PVec2& displacement) {
    bool buffer = m_tree.MoveProxy(proxyId, aabb, displacement);
    if (buffer) {
      BufferMove(proxyId);
    }
  }

  /// Call to trigger a re-processing of it's pairs on the next call to
  /// UpdatePairs.
  void TouchProxy(int32_t proxyId) { BufferMove(proxyId); }

  /// Get the fat AABB for a proxy.
  const PhysicsAABB& GetFatAABB(int32_t proxyId) const {
    return m_tree.GetFatAABB(proxyId);
  }

  /// Get user data from a proxy. Returns nullptr if the id is invalid.
  void* GetUserData(int32_t proxyId) const {
    return m_tree.GetUserData(proxyId);
  }

  /// Test overlap of fat AABBs.
  [[nodiscard]] bool TestOverlap(int32_t proxyIdA, int32_t proxyIdB) const {
    return b2TestOverlap(m_tree.GetFatAABB(proxyIdA),
                         m_tree.GetFatAABB(proxyIdB));
  }

  /// Get the number of proxies.
  int32_t GetProxyCount() const { return m_proxyCount; }

  /// Update the pairs. This results in pair callbacks. This can only add pairs.
  template <HasAddPairs T>
  void UpdatePairs(T* callback) {
    // Reset pair buffer
    m_pairCount = 0;

    // Perform tree queries for all moving proxies.
    for (int32 i = 0; i < m_moveCount; ++i) {
      m_queryProxyId = m_moveBuffer[i];
      if (m_queryProxyId == kNullProxy) {
        continue;
      }

      // We have to query the tree with the fat AABB so that
      // we don't fail to create a pair that may touch later.
      const PhysicsAABB& fatAABB = m_tree.GetFatAABB(m_queryProxyId);

      // Query tree, create pairs and add them pair buffer.
      m_tree.Query(this, fatAABB);
    }

    // Send pairs to caller
    for (int32 i = 0; i < m_pairCount; ++i) {
      const b2Pair* primaryPair = m_pairBuffer + i;
      void* userDataA = m_tree.GetUserData(primaryPair->first);
      void* userDataB = m_tree.GetUserData(primaryPair->second);

      callback->AddPair(userDataA, userDataB);
    }

    // Clear move flags
    for (int32 i = 0; i < m_moveCount; ++i) {
      int32 proxyId = m_moveBuffer[i];
      if (proxyId == kNullProxy) {
        continue;
      }

      m_tree.ClearMoved(proxyId);
    }

    // Reset move buffer
    m_moveCount = 0;
  }

  /// Query an AABB for overlapping proxies. The callback class
  /// is called for each proxy that overlaps the supplied AABB.
  template <HasQueryCallback T>
  void Query(T* callback, const PhysicsAABB& aabb) const {
    m_tree.Query(callback, aabb);
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
    m_tree.RayCast(callback, input);
  }

  /// Get the height of the embedded tree.
  int32_t GetTreeHeight() const { return m_tree.GetHeight(); }

  /// Get the balance of the embedded tree.
  int32_t GetTreeBalance() const { return m_tree.GetMaxBalance(); }

  /// Get the quality metric of the embedded tree.
  float GetTreeQuality() const { return m_tree.GetAreaRatio(); }

  /// Shift the world origin. Useful for large worlds.
  /// The shift formula is: position -= newOrigin
  /// @param newOrigin the new origin with respect to the old origin
  void ShiftOrigin(const PVec2& newOrigin) { m_tree.ShiftOrigin(newOrigin); }

 private:
  friend class b2DynamicTree;

  void BufferMove(int32_t proxyId) {
    if (m_moveCount == m_moveCapacity) {
      int32* oldBuffer = m_moveBuffer;
      m_moveCapacity *= 2;
      m_moveBuffer =
          static_cast<int32*>(malloc(m_moveCapacity * sizeof(int32)));
      memcpy(m_moveBuffer, oldBuffer, m_moveCount * sizeof(int32));
      free(oldBuffer);
    }

    m_moveBuffer[m_moveCount] = proxyId;
    ++m_moveCount;
  }
  void UnBufferMove(int32_t proxyId) {
    for (int32 i = 0; i < m_moveCount; ++i) {
      if (m_moveBuffer[i] == proxyId) {
        m_moveBuffer[i] = kNullProxy;
      }
    }
  }

  bool QueryCallback(int32_t proxyId) {
    // A proxy cannot form a pair with itself.
    if (proxyId == m_queryProxyId) {
      return true;
    }

    const bool moved = m_tree.WasMoved(proxyId);
    if (moved && proxyId > m_queryProxyId) {
      // Both proxies are moving. Avoid duplicate pairs.
      return true;
    }

    // Grow the pair buffer as needed.
    if (m_pairCount == m_pairCapacity) {
      b2Pair* oldBuffer = m_pairBuffer;
      m_pairCapacity = m_pairCapacity + (m_pairCapacity >> 1);
      m_pairBuffer =
          static_cast<b2Pair*>(malloc(m_pairCapacity * sizeof(b2Pair)));
      memcpy(m_pairBuffer, oldBuffer, m_pairCount * sizeof(b2Pair));
      free(oldBuffer);
    }

    m_pairBuffer[m_pairCount].first = PhysicsMin(proxyId, m_queryProxyId);
    m_pairBuffer[m_pairCount].second = PhysicsMax(proxyId, m_queryProxyId);
    ++m_pairCount;

    return true;
  }

  b2DynamicTree m_tree;

  int32_t m_proxyCount;

  int32_t* m_moveBuffer;
  int32_t m_moveCapacity;
  int32_t m_moveCount;

  b2Pair* m_pairBuffer;
  int32_t m_pairCapacity;
  int32_t m_pairCount;

  int32_t m_queryProxyId;
};
}  // namespace base_engine::physics::bp