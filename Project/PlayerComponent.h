// @file PlayerComponent.h
// @brief プレイヤーを管理するクラス
// @author ICE
// @date 2022/08/07
//
// @details
#pragma once
#include <Math/Vector2.h>
#include <Utilities/GraphicsUtilities.h>

#include "Component.h"
#include "Game.h"
#include "GridPosition.h"
#include "HandlerRegistration.h"
#include "ISpriteAnimationComponent.h"
#include "InputManager.h"
#include "PhysicsBodyComponent.h"
#include "PlayerFall.h"
#include "PlayerGoal.h"
#include "PlayerIdle.h"
#include "PlayerJump.h"
#include "PlayerMove.h"
#include "PlayerSneak.h"
#include "PlayerSneakMove.h"
#include "PlayerVentAction.h"
#include "ReactiveProperty.h"
#include "SoundEffectActor.h"
#include "StateMachine.h"

class VentComponent;

namespace tile_map {
class TileMapComponent;
}

namespace player {
enum class Dir { kLeft, kRight };
class PlayerComponent final : public base_engine::Component {
  using Vector2 = Mof::CVector2;
  using TileMapWeak =
      base_engine::ComponentDerivedWeakPtr<tile_map::TileMapComponent>;

 public:
  class PlayerListener;
  ~PlayerComponent() override;
  PlayerComponent(base_engine::Actor* owner, int update_order);
  void Start() override;
  void ProcessInput() override;
  void Update() override;
  void OnCollision(const base_engine::SendManifold& manifold) override;
  void VentEnter(VentComponent* vent);

  void SetInput(const InputManager* input_manager);
  bool CanPlace(const GridPosition& pos) const;

    std::optional<GridPosition> SearchPlacePosition() const;
  [[nodiscard]] bool IsJumpKey() const;

  [[nodiscard]] float GetHorizontal() const;
  [[nodiscard]] bool IsSneakKey() const;

  [[nodiscard]] bool IsPlaceBeaconKey() const;

  [[nodiscard]] bool IsCollectBeaconKey() const;

  [[nodiscard]] bool IsActionKey() const;

  [[nodiscard]] base_engine::CollisionComponent* GetCollision() const;

  [[nodiscard]] base_engine::ISpriteAnimationComponent* GetAnimator() const;

  [[nodiscard]] base_engine::PhysicsBodyComponent* PhysicsBody() const;
  [[nodiscard]] int MaxBeacon() const;
  [[nodiscard]] int GetBeacon() const;
  void SetBeacon(const int num);

  void LookAtRight();
  void LookAtLeft();
  bool IsRight() const;
  void MovedLookAt();

  bool IsGround() const;
  void SetGround(const bool ground);
  [[nodiscard]] base_engine::Game* GetGame() const;
  [[nodiscard]] base_engine::Actor* GetOwner() const;

  void SetMap(const TileMapWeak& map);
  void PlaySoundEffect() const;
  void StopSoundEffect() const;
  void ActionKey(const base_engine::CollisionComponent* collision);

private:
  int have_beacon_count_ = MaxBeacon();

  const InputManager* input_manager_ = nullptr;
  TileMapWeak map_;

  til::Machine<PlayerIdle, PlayerMove, PlayerSneak, PlayerSneakMove, PlayerJump,
               PlayerFall, PlayerVentAction, PlayerGoal>
      machine_ = til::Machine{PlayerIdle{this},      PlayerMove{this},
                              PlayerSneak{this},     PlayerSneakMove{this},
                              PlayerJump{this},      PlayerFall{this},
                              PlayerVentAction{this},PlayerGoal{this}};

  std::weak_ptr<base_engine::CollisionComponent> collision_;
  std::weak_ptr<base_engine::PhysicsBodyComponent> physics_body_;
  std::weak_ptr<base_engine::ISpriteAnimationComponent> animator_;
  std::weak_ptr<base_engine::SpriteComponent> sprite_;
  std::unique_ptr<PlayerListener> listener_;
  std::vector<std::shared_ptr<HandlerRegistration>> event_handlers_;
  observable::ReactiveProperty<Dir> dir_ = Dir::kRight;
  bool is_ground_ = false;
  bool can_control_ = true;
  bool goal_event_ = false;
  SoundEffectActor* sound_effect_;

 private:
  void CheckGround();
};
}  // namespace player