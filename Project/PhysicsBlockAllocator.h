// @PhysicsBlockAllocator.h
// @brief
// @author ICE
// @date 2022/10/16
//
// @details

#pragma once
#include <cstdint>

namespace base_engine::physics {
constexpr int32_t b2_blockSizeCount = 14;

struct PhysicsBlock;
struct PhysicsChunk;

class PhysicsBlockAllocator {
 public:
  PhysicsBlockAllocator();
  ~PhysicsBlockAllocator();

  /// Allocate memory. This will use b2Alloc if the size is larger than
  /// b2_maxBlockSize.
  void* Allocate(int32_t size);

  /// Free memory. This will use b2Free if the size is larger than
  /// b2_maxBlockSize.
  void Free(void* p, int32_t size);

  void Clear();

private:
  PhysicsChunk* m_chunks;
  int32_t m_chunkCount;
  int32_t m_chunkSpace;

  PhysicsBlock* m_freeLists[b2_blockSizeCount];
};
}  // namespace base_engine::physics
