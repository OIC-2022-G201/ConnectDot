#include "StartPointGimmickTransmitter.h"

bool StartPointGimmickTransmitter::CanSending() {
	return true;
}

base_engine::Vector2 StartPointGimmickTransmitter::GetPosition() const {
	return { 1,1 };
}
