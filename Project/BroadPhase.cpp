#include "BroadPhase.h"

base_engine::physics::bp::BroadPhase::BroadPhase() {
  m_proxyCount = 0;

  m_pairCapacity = 16;
  m_pairCount = 0;
  m_pairBuffer = static_cast<b2Pair*>(malloc(m_pairCapacity * sizeof(b2Pair)));

  m_moveCapacity = 16;
  m_moveCount = 0;
  m_moveBuffer =
      static_cast<int32_t*>(malloc(m_moveCapacity * sizeof(int32_t)));
}
