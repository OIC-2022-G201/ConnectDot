#include "SignboardActor.h"

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LoadObjectParameter.h"
#include "MachineConst.h"
#include "PowerSupplyUnitActor.h"
#include "ReceiverComponent.h"
#include "SignboardReceiver.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace base_engine;
using namespace electronics::signboard;
using namespace draw_order;
SignboardActor::SignboardActor(base_engine::Game* game) : Actor(game) {}

void SignboardActor::Start() {}

void SignboardActor::Update() {}

void SignboardActor::SetDisplayImage(base_engine::TexturePtr texture) {
  display_texture_ = texture;
  if (display_) {
    display_->SetImage(display_texture_);
  }
}

void SignboardActor::Create(const LoadObject& object) {
  {
    display_ = new SpriteComponent(this, kSignboardDisplayDrawOrder);
    display_->SetOffset(kDisplayOffset);
    animation_ = new MofSpriteAnimationComponent(this);
    const auto path = "gimmick/Objects/Signboard/" +
                      std::get<std::string>(object.parameters[5]);
    const auto img = BASE_ENGINE(Texture)->Get(path + ".png");
    display_texture_ = img;
    display_->SetImage(display_texture_);
    display_->SetEnabled(false);


    animation_->Load(display_, path + ".aei");
    animation_->Stop();
  }
  {
    const auto sign = new SpriteComponent(this, kSignboardDrawOrder);
    const auto path =
        std::get<LoadObject::TexturePath>(object.parameters[0]).value;
    sign->SetImage(BASE_ENGINE(Texture)->Get(path));
  }
  {
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<SignboardReceiver>(display_,animation_);
  }
  {
    auto pos = std::get<LoadObject::Transform>(object.parameters[2]).value;
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::Yes).SetSnapGridPosition({pos.x, pos.y});
  }
  SetName("Signboard");
}
