#include "EnemyVisionComponent.h"

#include "EnemyComponent.h"
#include "SecondEnemyComponent.h"
#include "CollisionLayer.h"
#include "InputManager.h"
#include "ShapeRenderComponent.h"
namespace enemy {
	void EnemyVisionComponent::Start()
	{
		is_find_ = false;
		is_change_ = false;

		if(vision_parent_->GetComponent<EnemyComponent>().lock()==nullptr)
		{
			prev_direction = vision_parent_->GetComponent<SecondEnemyComponent>().lock()->GetDirection();
			owner_->SetPosition(vision_parent_->GetPosition());
		}
		else
			prev_direction = vision_parent_->GetComponent<EnemyComponent>().lock()->GetDirection();

		collision_ = new CollisionComponent(owner_);
		collision_->SetShape(find_rect_);
		collision_->SetObjectFilter(CollisionLayer::kNone);
                const auto filter =
                    BitCollisionLayer{kPlayerObjectFilter};
		collision_->SetTargetFilter(kEnemyVisionTargetFilter);
		collision_->SetTrigger(true);

		debug_render_ = new ShapeRenderComponent(owner_, 200);
		debug_render_->SetShape(find_rect_);
		debug_render_->SetColor(MOF_COLOR_HRED);
	}

	void EnemyVisionComponent::ProcessInput()
	{

	}

	void EnemyVisionComponent::Update()
	{
		if (vision_parent_->GetComponent<EnemyComponent>().lock() == nullptr)
			direction = vision_parent_->GetComponent<SecondEnemyComponent>().lock()->GetDirection();
		else
		{
			owner_->SetPosition(vision_parent_->GetPosition());
			direction = vision_parent_->GetComponent<EnemyComponent>().lock()->GetDirection();
		}

		if (direction != prev_direction) {
			if (direction)
			{
				find_rect_->Left += reverse_width_; find_rect_->Right += reverse_width_;
                                find_rect_->ChangeNotification();
								collision_->Sync();
			}
			else
			{
				find_rect_->Left -= reverse_width_; find_rect_->Right -= reverse_width_;
                                find_rect_->ChangeNotification();
								collision_->Sync();
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

	void EnemyVisionComponent::OnCollision(const SendManifold& manifold)
	{
          if (InputManager::Instance()->ActionFire())
          {
            int n = 3;
          }
			is_find_ = true;
			player_center_ = manifold.collision_b->AABB().GetCenter();
		
	}
}