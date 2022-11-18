#pragma once

#include  "Actor.h"
#include  "Component.h"
#include  "BaseEngineCore.h"
#include  "IBaseEngineTexture.h"
#include "ImageComponent.h"
#include  "TexturePaths.h"

namespace base_engine{
class CounterComponent:public Component{
public:
	CounterComponent(class Actor* owner);
	~CounterComponent() override{}

	void Update() override;
	void Start() override{}
	void SetNumber(int number);
	void SetPosition();
	void SetPositionLeft();

	void SetIsRight(bool is_right)
	{
		is_right_ = is_right;
	}

private:
	base_engine::ImageComponent* third_digit;
	base_engine::ImageComponent* second_digit;
	base_engine::ImageComponent* first_digit;
	base_engine::TexturePtr numbers[10];
	int number_;
	bool m_bThirdShow = false;
	bool m_bSecondShow = false;

	bool is_right_ = true;
};
}
