#include "DoorActor.h"

#include "BaseEngineCore.h"
#include "DrawOrder.h"
#include "DoorReceiver.h"
#include "ElectronicsPower.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "ReceiverComponent.h"
#include "TexturePaths.h"

using  namespace base_engine;
using  namespace draw_order;

DoorActor::DoorActor(base_engine::Game* game) : Actor(game){}

void DoorActor::Start(){
  {
  	door_ = new SpriteComponent(this, kDoorDrawOrder);
	door_->SetImage(BASE_ENGINE(Texture)->Get(texture::kDoorTextureKey));
	door_->SetEnabled(true);
  }
  {
  	open_door_ = new SpriteComponent(this, kOpenDoorDrawOrder);
  	open_door_->SetImage(BASE_ENGINE(Texture)->Get(texture::kOpenDoorTextureKey));
	open_door_->SetEnabled(false);
  }
  {
	  const auto receiver = new ReceiverComponent(this, 100);
	  receiver->Create<DoorReceiver>(open_door_);
  }
  {
	  const auto grid = new grid::GridSnapComponent(this);
	  grid->SetAutoSnap(grid::AutoSnap::Yes).SetSnapGridPosition({ 5,6 });
  }
  SetName("Door");
}

void DoorActor::Update(){}
