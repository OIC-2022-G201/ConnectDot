#include "RenderComponent.h"

#include "Actor.h"
#include "Game.h"
base_engine::RenderComponent::RenderComponent(Actor* owner, int draw_order): Component(owner), draw_order_(draw_order)
{
    owner_->GetGame()->AddSprite(this);
}

base_engine::RenderComponent::~RenderComponent()
{ owner_->GetGame()->RemoveSprite(this); }

void base_engine::RenderComponent::Update()
{}
