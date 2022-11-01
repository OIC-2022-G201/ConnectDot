#include "PhysicsBlockAllocator.h"

#include <array>
#include <memory>
#include <span>

namespace base_engine::physics {
constexpr int32_t kPhysicsChunkSize = 16 * 1024;
constexpr int32_t kPhysicsMaxBlockSize = 640;
constexpr int32_t kPhysicsChunkArrayIncrement = 128;

constexpr std::array kPhysicsBlockSizes = {
    static_cast<int32_t>(16),  // 0
    32,                        // 1
    64,                        // 2
    96,                        // 3
    128,                       // 4
    160,                       // 5
    192,                       // 6
    224,                       // 7
    256,                       // 8
    320,                       // 9
    384,                       // 10
    448,                       // 11
    512,                       // 12
    640,                       // 13
};

consteval std::array<uint8_t, kPhysicsMaxBlockSize + 1> SizeMap() {
  std::array<uint8_t, kPhysicsMaxBlockSize + 1> values{};
  int32_t j = 0;
  values[0] = 0;
  for (int32_t i = 1; i <= kPhysicsMaxBlockSize; ++i) {
    if (i <= kPhysicsBlockSizes[j]) {
      values[i] = static_cast<uint8_t>(j);
    } else {
      ++j;
      values[i] = static_cast<uint8_t>(j);
    }
  }
  return values;
}
constexpr std::array<uint8_t, 641U> kPhysicsSizeMap = SizeMap();

struct PhysicsChunk {
  int32_t block_size;
  PhysicsBlock* blocks;
};

struct PhysicsBlock {
  PhysicsBlock* next;
};

PhysicsBlockAllocator::PhysicsBlockAllocator() {
  m_chunkSpace = kPhysicsChunkArrayIncrement;
  m_chunkCount = 0;
  m_chunks = static_cast<PhysicsChunk*>(malloc(m_chunkSpace * sizeof(PhysicsChunk)));

  memset(m_chunks, 0, m_chunkSpace * sizeof(PhysicsChunk));
  memset(m_freeLists, 0, sizeof(m_freeLists));
}

PhysicsBlockAllocator::~PhysicsBlockAllocator() {
  for (int32_t i = 0; i < m_chunkCount; ++i) {
    free(m_chunks[i].blocks);
  }

  free(m_chunks);
}

void* PhysicsBlockAllocator::Allocate(int32_t size) {
  if (size == 0) {
    return nullptr;
  }

  if (size > kPhysicsMaxBlockSize) {
    return malloc(size);
  }

  if (const int32_t index = kPhysicsSizeMap[size]; m_freeLists[index]) {
    PhysicsBlock* block = m_freeLists[index];
    m_freeLists[index] = block->next;
    return block;
  } else {
    if (m_chunkCount == m_chunkSpace) {
      PhysicsChunk* oldChunks = m_chunks;
      m_chunkSpace += kPhysicsChunkArrayIncrement;
      m_chunks = static_cast<PhysicsChunk*>(malloc(m_chunkSpace * sizeof(PhysicsChunk)));
      memcpy(m_chunks, oldChunks, m_chunkCount * sizeof(PhysicsChunk));
      memset(m_chunks + m_chunkCount, 0,
             kPhysicsChunkArrayIncrement * sizeof(PhysicsChunk));
      free(oldChunks);
    }

    PhysicsChunk* chunk = m_chunks + m_chunkCount;
    chunk->blocks = static_cast<PhysicsBlock*>(malloc(kPhysicsChunkSize));

#if defined(_DEBUG)
    memset(chunk->blocks, 0xcd, kPhysicsChunkSize);
#endif

    const int32_t block_size = kPhysicsBlockSizes[index];
    chunk->block_size = block_size;
    const int32_t block_count = kPhysicsChunkSize / block_size;
    for (int32_t i = 0; i < block_count - 1; ++i) {
      const auto block = reinterpret_cast<PhysicsBlock*>(
          reinterpret_cast<int8_t*>(chunk->blocks) + block_size * i);
      const auto next = reinterpret_cast<PhysicsBlock*>(
          reinterpret_cast<int8_t*>(chunk->blocks) + block_size * (i + 1));
      block->next = next;
    }
    const auto last =
        reinterpret_cast<PhysicsBlock*>(reinterpret_cast<int8_t*>(chunk->blocks) +
                                   block_size * (block_count - 1));
    last->next = nullptr;

    m_freeLists[index] = chunk->blocks->next;
    ++m_chunkCount;

    return chunk->blocks;
  }
}

void PhysicsBlockAllocator::Free(void* p, const int32_t size) {
  if (size == 0) {
    return;
  }

  if (size > kPhysicsMaxBlockSize) {
    free(p);
    return;
  }

  const int32_t index = kPhysicsSizeMap[size];

#if defined(_DEBUG)
  // Verify the memory address and size is valid.
  const int32_t block_size = kPhysicsBlockSizes[index];
  bool found = false;
  for (int32_t i = 0; i < m_chunkCount; ++i) {
    PhysicsChunk* chunk = m_chunks + i;
    if (chunk->block_size == block_size) {
      if (chunk->blocks <= p &&
          static_cast<int8_t*>(p) + block_size <=
              reinterpret_cast<int8_t*>(chunk->blocks) + kPhysicsChunkSize) {
        found = true;
      }
    } else {
      // TODO エラー処理
    }
  }

  memset(p, 0xfd, block_size);
#endif

  const auto block = static_cast<PhysicsBlock*>(p);
  block->next = m_freeLists[index];
  m_freeLists[index] = block;
}

void PhysicsBlockAllocator::Clear() {
  for (int32_t i = 0; i < m_chunkCount; ++i) {
    free(m_chunks[i].blocks);
  }

  m_chunkCount = 0;
  memset(m_chunks, 0, m_chunkSpace * sizeof(PhysicsChunk));
  memset(m_freeLists, 0, sizeof(m_freeLists));
}
}  // namespace base_engine::physics
