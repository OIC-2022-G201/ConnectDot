#include "EnemyVisionComponent.h"

#include "EnemyComponent.h"
#include "CollisionLayer.h"
#include "ShapeRenderComponent.h"
void EnemyVisionComponent::Start()
{
	is_find_ = false;
	is_change_ = false;
	collision_ = new base_engine::CollisionComponent(owner_);
	find_rect_ = std::make_shared<base_engine::Rect>(0, 0, 512, 256);
	chase_rect_ = std::make_shared<base_engine::Rect>(0, 0, 512, 512);
	collision_->SetShape(find_rect_);
	collision_->SetObjectFilter(CollisionLayer::kNone);
	collision_->SetTargetFilter(kPlayerObjectFilter);
	collision_->SetTrigger(true);
	debug_render_ = new base_engine::ShapeRenderComponent(owner_, 502);
	debug_render_->SetShape(find_rect_);
	debug_render_->SetColor(MOF_COLOR_HRED);
	const_cast<enemy::EnemyMove&>(parent_->GetComponent<enemy::EnemyComponent>().lock()->GetMachine()->get_state<enemy::EnemyMove>()).SetVisionComponent(this);
	const_cast<enemy::EnemyChase&>(parent_->GetComponent<enemy::EnemyComponent>().lock()->GetMachine()->get_state<enemy::EnemyChase>()).SetVisionComponent(this);
}

void EnemyVisionComponent::ProcessInput()
{
	
}

void EnemyVisionComponent::Update()
 {
	owner_->SetPosition(parent_->GetPosition());
	if (is_change_ != is_find_)
	{
		if(is_find_)
		{
			owner_->GetComponent<base_engine::CollisionComponent>().lock().get()->SetShape(chase_rect_);
			owner_->GetComponent<base_engine::ShapeRenderComponent>().lock().get()->SetShape(chase_rect_);
		}
		else
		{
			owner_->GetComponent<base_engine::CollisionComponent>().lock().get()->SetShape(find_rect_);
			owner_->GetComponent<base_engine::ShapeRenderComponent>().lock().get()->SetShape(find_rect_);
		}
	}
	is_change_ = is_find_;
	is_find_ = false;
 }

void EnemyVisionComponent::OnCollision(const base_engine::SendManifold& manifold)
{
	is_find_ = true;
}
