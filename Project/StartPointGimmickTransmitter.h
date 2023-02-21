#pragma once
#include "ISendablePower.h"

class StartPointGimmickTransmitter : public ISendablePower {
public:
	explicit StartPointGimmickTransmitter(class StartPointGimmickActor* actor):actor_(actor)
	{
	}
	bool CanSending() override;
	const ISendablePower* GetPrevious() override { return previous_; }
	void SetPrevious(ISendablePower* previous) override { previous_ = previous; }
	[[nodiscard]] base_engine::Vector2 GetPosition() const override;
private:
	base_engine::Vector2 position_;
	ISendablePower* previous_ = nullptr;
	class StartPointGimmickActor* actor_ = nullptr;
};