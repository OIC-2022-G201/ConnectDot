#include "EnemyVisionActor.h"

#include "CollisionLayer.h"
namespace enemy {
	EnemyVisionActor::EnemyVisionActor(base_engine::Game* game) :Actor(game) {}
	EnemyVisionActor::~EnemyVisionActor() {}

	void EnemyVisionActor::Start() {
		collision_ = new base_engine::CollisionComponent(this);
		debug_render_ = new base_engine::ShapeRenderComponent(this, 502);
		find_rect_ = std::make_shared<base_engine::Rect>(0, 0, 512, 256);
		chase_rect_ = std::make_shared<base_engine::Rect>(0, 0, 512, 512);
		collision_->SetShape(find_rect_);
		collision_->SetObjectFilter(kEnemyObjectFilter);
		collision_->SetTargetFilter(kPlayerObjectFilter);
		collision_->SetTrigger(true);
		debug_render_->SetShape(find_rect_);
		debug_render_->SetColor(MOF_COLOR_HRED);
		
	}

	void EnemyVisionActor::Update() {
		SetPosition(parent_->GetPosition());
	}
}