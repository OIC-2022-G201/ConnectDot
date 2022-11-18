#pragma once
#include "ISendablePower.h"
#include "IPlayerAction.h"
#include "TransmitterComponent.h"
class LeverTransmitter:public ISendablePower
{
public:
	explicit LeverTransmitter(class LeverActor* actor) :actor_(actor)
	{

	}
	const ISendablePower* GetPrevious() override { return previous_; }
	void SetPrevious(ISendablePower* previous) override { previous_ = previous; }
	bool CanSending()override;
	[[nodiscard]] base_engine::Vector2 GetPosition() const override;
	int Sequential()override;
        
        

       private:
	base_engine::Vector2 position_;
	ISendablePower* previous_ = nullptr;
	class LeverActor* actor_ = nullptr;
       
};

