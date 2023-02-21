#include "GoalEffectActor.h"

#include <numbers>

#include "AudioStreamComponent.h"
#include "AudioVolume.h"
#include "BaseEngineCore.h"
#include "ButtonPressEvent.h"
#include "ClipSizeXTween.h"
#include "ClipSizeYTween.h"
#include "ComponentServiceLocator.h"
#include "CounterComponent.h"
#include "Dummytween.h"
#include "EventBus.h"
#include "EventHandler.h"
#include "GameWindow.h"
#include "GoalEvent.h"
#include "HandlerRegistration.h"
#include "IBaseEngineTexture.h"
#include "ImageAlphaTween.h"
#include "ImageComponent.h"
#include "InputManager.h"
#include "ITransitionFadeSystem.h"
#include "MofSpriteAnimationComponent.h"
#include "NinePatchImageComponent.h"
#include "PositionXTween.h"
#include "QuitEvent.h"
#include "ResourceContainer.h"
#include "ReStartEvent.h"
#include "ResultModel.h"
#include "SceneManager.h"
#include "SpriteComponent.h"
#include "StageContainer.h"
#include "TitleSceneFactory.h"
#include "TransitionParameter.h"
#include "UiFactoryUtilities.h"
#include "UiFrozen.h"
using namespace base_engine;
using ::GoalEffectActor;
using RC = ResourceContainer;
class ResultListener final : public EventHandler<ButtonPressEvent> {
public:
	void OnEvent(ButtonPressEvent& press) override {}
};
constexpr std::string_view kSRankAnimation = "Result_SRankAnimation";
constexpr std::string_view kCheckBoxAnimation= "CheckBoxAnimation";
namespace {
	auto ButtonCreate(Game* game, ButtonSelecter* selector, const ButtonFrozenPack& button_data) {
		const auto button_pack =
			RC::GetResource<ResourceContainer::ButtonResourcePack,
			ButtonResourcePackage>(button_data.path);
		const auto button = new Button(game, 3000);
		button->SetButtonSprite(button_pack->sprites[0]);
		button->SetChangeButtonSprite(button_pack->sprites[1]);
		button->SetPosition({ button_data.x, button_data.y });
		selector->ButtonRegister(button_data.tx, button_data.ty, button);
		{
			const auto audio = new AudioStreamComponent(button);
			audio->AssetLoad("DeterministicSE");
			audio->SetVolume(
				ServiceLocator::Instance().Resolve<AudioVolume>()->SEVolume());
			button->SetEvent([audio] { audio->Play(); });
		}
		{
			const auto audio = new AudioStreamComponent(button);
			audio->AssetLoad("CursorMoveSE");
			audio->SetVolume(
				ServiceLocator::Instance().Resolve<AudioVolume>()->SEVolume());
			button->SetHoverEvent([audio] { audio->Play(); });
		}
		const struct {
			Button* button;
			ButtonSelecter* selector;
		} result = { button, selector };
		return result;
	}
	auto AnimationCreate(Game* game,std::string_view animation_view,int draw_order,Vector2 pos) {
		const auto actor = new Actor(game);
		const auto sprite = new ImageComponent(actor, draw_order);
		const auto pack =
			RC::GetPack<RC::AnimationResourcePack>(animation_view.data());
		const auto image = pack->Get<RC::Sprite>()->Get(0);
		sprite->SetImage(*image);
		const auto clip = pack->Get<RC::AnimationClips>()->Get(0);
		const auto animation = new MofSpriteAnimationComponent(actor);
		animation->Load(sprite, *clip);
		actor->SetPosition(pos);
	}
	
}

class Image {
public:
	Image& Create(Game* game, float x, float y, const std::string_view name,
		const int order = 2000) {
		actor = new Actor(game);
		sprite = new ImageComponent(actor, order);
		actor->SetPosition({ x, y });
		sprite->SetImage(
			*RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(name.data()));
		return *this;
	}

	[[nodiscard]] ImageComponent& Sprite() const { return *sprite; }
	[[nodiscard]] Actor* Owner() const { return actor; }

private:
	Actor* actor;
	ImageComponent* sprite;
};
class PopupPanel {
public:
	PopupPanel& Create(Game* game, const Rect& rect, const std::string_view name,
		const int order = 2000) {
		actor = new Actor(game);
		panel = new NinePatchImageComponent(actor, order);
		const auto sprite_resource =
			RC::GetResource<RC::SpriteResourcePack, RC::Sprite>(name.data());
		panel->SetImage(*sprite_resource, { 2, 2 }, { 126, 126 });
		const Vector2 lt = rect.GetTopLeft();
		const Vector2 rb = rect.GetBottomRight();
		size_ = rb - lt;
		actor->SetPosition(lt);
		panel->SetClipRect({ {0, 0}, {10, 10} });
		return *this;
	}

	[[nodiscard]] NinePatchImageComponent& Panel() const { return *panel; }
	[[nodiscard]] Actor* Owner() const { return actor; }

	Vector2 size_;

private:
	Actor* actor;
	NinePatchImageComponent* panel;
};
class GoalEffectActor::GoalEffectComponent final : public Component {
	Image top_;
	Image bottom_;
	Image popup_text_;
	Button* next_stage_logo_;
	Button* stage_select_logo_;
	Button* retry_logo_;
	Image clear_logo_;
	PopupPanel panel_;
	std::unique_ptr<ResultListener> listener_;
	std::shared_ptr<HandlerRegistration> handle_;
	bool end_animation_ = false;
	std::unordered_map<std::string, base_engine::Actor*> elements_{};
public:
	explicit GoalEffectComponent(Actor* owner);

	void Start() override;
	void Update() override;
	void Show() {}
	void Transition();
	void CreateButtons();

private:
	auto& OpenPopup() const {
		panel_.Panel()
			.SetColor(MOF_ARGB(255, 255, 255, 255))
			.SetClipRect({ 0, 0, 0, 0 });
		panel_.Panel().SetEnabled(true);
		ma_tween::ClipSizeYTween::TweenClipSizeY(
			panel_.Owner(), panel_.Owner()->GetComponent<NinePatchImageComponent>(),
			panel_.size_.y, 0.5f)
			.SetEase(EaseType::kInoutcirc);
		return ma_tween::ClipSizeXTween::TweenClipSizeX(
			panel_.Owner(),
			panel_.Owner()->GetComponent<NinePatchImageComponent>(),
			panel_.size_.x, 0.5f)
			.SetEase(EaseType::kInoutcirc);
	}
	auto& ShowScore() const {
		return ma_tween::DummyTween::TweenDummy(panel_.Owner(), 0.01)
			.SetOnComplete([this] {
			popup_text_.Sprite().SetColor(MOF_ARGB(255, 255, 255, 255));
		});
	}
	auto& NextStageLogoAnimation() const {
		next_stage_logo_->SetEnable(true);
		return ma_tween::ImageAlphaTween::TweenImageAlpha(next_stage_logo_, 255,
			0.17f);
	}
	auto& StageSelectLogoAnimation() const {
		stage_select_logo_->SetEnable(true);
		return ma_tween::ImageAlphaTween::TweenImageAlpha(stage_select_logo_, 255,
			0.17f);
	}
	auto& RetryLogoAnimation() const {
		retry_logo_->SetEnable(true);
		return ma_tween::ImageAlphaTween::TweenImageAlpha(retry_logo_, 255,
			0.17f);
	}
	auto& ClearLogoAnimation() const {
		return ma_tween::ImageAlphaTween::TweenImageAlpha(clear_logo_.Owner(), 255,
			0.17f);
	}

	auto& LetterBoxAnimation() const {
		constexpr float letter_time = 0.2f;
		ma_tween::PositionXTween::TweenLocalPositionX(bottom_.Owner(), 0,
			letter_time)
			.SetEase(EaseType::kOutquart)
			.SetSequenceDelay(1);
		return ma_tween::PositionXTween::TweenLocalPositionX(top_.Owner(), 0,
			letter_time)
			.SetEase(EaseType::kOutquart)
			.SetSequenceDelay(1)
			.SetOnComplete([this] { ClearLogoAnimation(); });
	}
};
GoalEffectActor::GoalEffectComponent::GoalEffectComponent(Actor* owner)
	: Component(owner) {}

void GoalEffectActor::GoalEffectComponent::Start() {
	const auto game = owner_->GetGame();
	top_.Create(game, -1920, 0, "LetterBox")
		.Sprite()
		.SetAngle(std::numbers::pi_v<float>)
		.SetAlignment(Mof::TEXALIGN_BOTTOMRIGHT);

	bottom_.Create(game, 1920, window::kHeight, "LetterBox")
		.Sprite()
		.SetAlignment(Mof::TEXALIGN_BOTTOMLEFT);

	popup_text_.Create(game, 252, 291, "ResultPopup", 2001)
		.Sprite()
		.SetColor(MOF_ARGB(0, 255, 255, 255));

	clear_logo_.Create(game, 176, 125, "ResultLogo")
		.Sprite()
		.SetColor(MOF_ARGB(0, 255, 255, 255));

	panel_.Create(game, { 252 ,291, 926 ,828 }, "Panel")
		.Panel()
		.SetColor(MOF_ARGB(0, 255, 255, 255))
		.SetEnabled(false);

	
	LetterBoxAnimation().SetOnComplete([this] {
		ClearLogoAnimation();
	OpenPopup().SetOnComplete([this]
		{
			ShowScore();
		StageSelectLogoAnimation();
		RetryLogoAnimation();
	; NextStageLogoAnimation().SetOnComplete([this] {
		end_animation_ = true;
	static_cast<ButtonSelecter*>(elements_.at("selector"))->SetEnable(true);
	
		AnimationCreate(owner_->GetGame(), kSRankAnimation.data(), 1000, { 1000, 310 });
	//CheckBox（上）
		AnimationCreate(owner_->GetGame(), kCheckBoxAnimation.data(), 1000, { 363 ,432 });
		//CheckBox（中央）
		AnimationCreate(owner_->GetGame(), kCheckBoxAnimation.data(), 1000, { 363 ,552 });
		//CheckBox（下）
		AnimationCreate(owner_->GetGame(), kCheckBoxAnimation.data(), 1000, { 363 ,672 });
		});
		});
		});
	CreateButtons();
}

void GoalEffectActor::GoalEffectComponent::Update() {
	
}

void  GoalEffectActor::GoalEffectComponent::CreateButtons() {

	constexpr bool enable = false;
	const std::vector<std::tuple<Vector2, std::string, std::function<void()>>>
		main_pack = {
								 {{100, 985}, "StageSelect_BackButton", [this] {
										std::any sender = this;
										QuitEvent quit{sender};
										EventBus::FireEvent(quit);
										ServiceLocator::Instance()
												.Resolve<ITransitionFadeSystem>()
												->SceneTransition(scene::kTitle, kPauseToGameFadeIn,
																					kPauseToGameFadeOut);
								 }},
									{{846 ,978},
									"Result_RetryButton",
									[this] {
										std::any sender = this;
										ReStartEvent restart{sender};
										EventBus::FireEvent(restart);
										ServiceLocator::Instance()
												.Resolve<ITransitionFadeSystem>()
												->SceneTransition(scene::kGame, kPauseToGameFadeIn,
																					kPauseToGameFadeOut);
								 }},
									{ {1384, 978},
									"Result_NextStageButton",
									[this] {
										std::any sender = this;
										GoalEvent e{sender};
										EventBus::FireEvent(e);
										Transition();
									}},
	};
	auto selector = new ButtonSelecter(owner_->GetGame());
	selector->SetInput(InputManager::Instance());
	selector->SetEnable(false);
	selector->SetSelect(2, 0);
	elements_.emplace("selector", selector);

	for (int i = 0; i < main_pack.size(); ++i) {
		const auto &[pos, name, action] = main_pack[i];
		const auto [button, _] = ButtonCreate(
			owner_->GetGame(), selector, ButtonFrozenPack{ pos.x, pos.y, name, i, 0 });
		elements_.emplace(name, button);
		button->SetEvent(action);
		button->SetEnable(enable);
	}
	next_stage_logo_ = static_cast<Button*>(elements_.at("Result_NextStageButton"));
	stage_select_logo_ = static_cast<Button*>(elements_.at("StageSelect_BackButton"));
	retry_logo_ = static_cast<Button*>(elements_.at("Result_RetryButton"));
	
};

GoalEffectActor::GoalEffectActor(base_engine::Game* game) : Actor(game) {}

void GoalEffectActor::Start() { new GoalEffectComponent(this); }

void GoalEffectActor::GoalEffectComponent::Transition()
{
	const auto stage_container = ServiceLocator::Instance().Resolve<StageContainer>();
	auto stage = stage_container->GetStageName().back();
	stage++;
	if (stage > '3')
	{
		ServiceLocator::Instance()
			.Resolve<ITransitionFadeSystem>()
			->SceneTransition(scene::kTitle, kGoalToTitleFadeIn, kGoalToTitleFadeout);
	}
	else
	{
		std::string next = "Stage";
		next.push_back(stage);
		stage_container->SelectStage(next);
		ServiceLocator::Instance()
			.Resolve<ITransitionFadeSystem>()
			->SceneTransition(scene::kGame, kGoalToNextStageFadeIn,
				kGoalToNextStageFadeout);
	}
}