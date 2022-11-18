#include "EnemyVisionComponent.h"

#include "EnemyComponent.h"
#include "CollisionLayer.h"
#include "ShapeRenderComponent.h"
namespace enemy {
	void EnemyVisionComponent::Start()
	{
		is_find_ = false;
		is_change_ = false;
		prev_direction = parent_->GetComponent<EnemyComponent>().lock()->GetDirection();
		find_rect_ = std::make_shared<base_engine::Rect>(-256, 0, 256, 256);
		chase_rect_ = std::make_shared<base_engine::Rect>(-256, -256, 512, 512);

		collision_ = new base_engine::CollisionComponent(owner_);
		collision_->SetShape(find_rect_);
		collision_->SetObjectFilter(CollisionLayer::kNone);
		collision_->SetTargetFilter(kPlayerObjectFilter);
		collision_->SetTrigger(true);

		debug_render_ = new base_engine::ShapeRenderComponent(owner_, 502);
		debug_render_->SetShape(find_rect_);
		debug_render_->SetColor(MOF_COLOR_HRED);

		const_cast<EnemyMove&>(parent_->GetComponent<EnemyComponent>().lock()->GetMachine()->get_state<EnemyMove>()).SetVisionComponent(this);
		const_cast<EnemyChase&>(parent_->GetComponent<EnemyComponent>().lock()->GetMachine()->get_state<EnemyChase>()).SetVisionComponent(this);
	}

	void EnemyVisionComponent::ProcessInput()
	{

	}

	void EnemyVisionComponent::Update()
	{
		owner_->SetPosition(parent_->GetPosition());
		direction = parent_->GetComponent<EnemyComponent>().lock()->GetDirection();

		if (direction != prev_direction) {
			if (direction)
			{
				find_rect_->Left += 256; find_rect_->Right += 256;
			}
			else
			{
				find_rect_->Left -= 256; find_rect_->Right -= 256;
			}
		}
		prev_direction = direction;

		if (is_change_ != is_find_)
		{
			if (is_find_)
			{
				collision_->SetShape(chase_rect_);
				debug_render_->SetShape(chase_rect_);
			}
			else
			{
				collision_->SetShape(find_rect_);
				debug_render_->SetShape(find_rect_);
			}
		}
		is_change_ = is_find_;

		is_find_ = false;
	}

	void EnemyVisionComponent::OnCollision(const base_engine::SendManifold& manifold)
	{
		is_find_ = true;
		player_center_ = manifold.collision_b->AABB().GetCenter().x;
	}
}