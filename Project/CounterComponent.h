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
	explicit CounterComponent(class Actor* owner);
	explicit CounterComponent(Actor* owner, const std::string& prefix);
	void Update() override;
	void Start() override{}
	void SetNumber(int number);

	//TODO 外部に公開する必要のないメソッドはprivateにする
	void SetPosition();
	void SetPositionLeft();
	void SetSpace(const float space) { space_ = space; }
	void SetIsRight(bool is_right)
	{
		is_right_ = is_right;
	}
  void SetEnable(bool enable);
  void SetOffset(Vector2 offset);

private:
	base_engine::ImageComponent* third_digit;
	base_engine::ImageComponent* second_digit;
	base_engine::ImageComponent* first_digit;
	base_engine::TexturePtr numbers[10];
	int number_;
	float space_ = 0;

  bool enable_ = true;
	bool m_bThirdShow = false;
	bool m_bSecondShow = false;
	
	bool is_right_ = true;

  Vector2 offset_ = {0,0};
};
}
