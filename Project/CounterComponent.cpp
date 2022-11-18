#include "CounterComponent.h"

#include "Actor.h"


base_engine::CounterComponent::CounterComponent(Actor* owner):Component(owner)
{
	numbers[0] = (BASE_ENGINE(Texture)->Get(texture::kZeroTextureKey));
	numbers[1] = (BASE_ENGINE(Texture)->Get(texture::kOneTextureKey));
	numbers[2] = (BASE_ENGINE(Texture)->Get(texture::kTwoTextureKey));
	numbers[3] = (BASE_ENGINE(Texture)->Get(texture::kThreeTextureKey));
	numbers[4] = (BASE_ENGINE(Texture)->Get(texture::kFourTextureKey));
	numbers[5] = (BASE_ENGINE(Texture)->Get(texture::kFiveTextureKey));
	numbers[6] = (BASE_ENGINE(Texture)->Get(texture::kSixTextureKey));
	numbers[7] = (BASE_ENGINE(Texture)->Get(texture::kSevenTextureKey));
	numbers[8] = (BASE_ENGINE(Texture)->Get(texture::kEightTextureKey));
	numbers[9] = (BASE_ENGINE(Texture)->Get(texture::kNineTextureKey));

	third_digit = new ImageComponent(owner_);
	second_digit = new ImageComponent(owner_);
	first_digit = new ImageComponent(owner_);
}

void base_engine::CounterComponent::Update()
{
	
}

void base_engine::CounterComponent::SetNumber(int number)
{
	number_ = number;
	int a, b, c;
	a = number_ / 100;
	b = (number_ - (100 * a)) / 10;
	c = number_ - ((100 * a) + (10 * b));

	if (a <= 0)
		m_bThirdShow = true;
	if (a <= 0 && b <= 0)
	{
		m_bThirdShow = false;
		m_bSecondShow = true;
	}

	if (m_bThirdShow)
	{
		second_digit->SetImage(numbers[b]);
		first_digit->SetImage(numbers[c]);
		if (is_right_)
		{
			SetPosition();
			return;
		}
		SetPositionLeft();
		return;
	}
	if (m_bSecondShow)
	{
		first_digit->SetImage(numbers[c]);
		if(is_right_)
		{
			SetPosition();
			return;
		}
		SetPositionLeft();
		return;
	}
		third_digit->SetImage(numbers[a]);
		second_digit->SetImage(numbers[b]);
		first_digit->SetImage(numbers[c]);
	    SetPosition();
}

void base_engine::CounterComponent::SetPosition()
{
	second_digit->SetOffset({ second_digit->GetClipRect().GetWidth(),0 });
	first_digit->SetOffset({ first_digit->GetClipRect().GetWidth() * 2,0 });
}

void base_engine::CounterComponent::SetPositionLeft()
{
	if (!m_bSecondShow && m_bThirdShow)
	{
		first_digit->SetOffset({ first_digit->GetClipRect().GetWidth(),0 });
	}
}


