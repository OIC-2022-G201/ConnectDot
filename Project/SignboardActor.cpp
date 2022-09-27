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

void SignboardActor::Start() {
  {
    const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
    const auto circle = std::make_shared<base_engine::Circle>(
        cell_half.x, cell_half.y, electronics::kPowerRadius);
    const auto shape = new base_engine::ShapeRenderComponent(this, 110);
    shape->SetShape(circle);
    shape->SetFillMode(electronics::kElectricAreaFillMode)
        .SetColor(electronics::kElectricAreaColor);

    const auto collision = new base_engine::CollisionComponent(this);
    collision->SetShape(circle);
    collision->SetObjectFilter(kSignboardObjectFilter);
    collision->SetTargetFilter(kSignboardTargetFilter);
    collision->SetTrigger(true);
  }
  {
    display_ = new SpriteComponent(this, kSignboardDisplayDrawOrder);
    display_->SetOffset(kDisplayOffset);
    const auto img =
        BASE_ENGINE(Texture)->Get(texture::kSignboardDisplayDemoTextureKey);
    display_texture_ = img;
    display_->SetImage(display_texture_);
    display_->SetEnabled(false);

  }
  {
    auto sign = new SpriteComponent(this, kSignboardDrawOrder);
    sign->SetImage(BASE_ENGINE(Texture)->Get(texture::kSignboardTextureKey));
  }
  {
    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<SignboardReceiver>(display_);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::Yes).SetSnapGridPosition({10, 5});
  }
  SetName("Signboard");
}

void SignboardActor::Update() {}

void SignboardActor::SetDisplayImage(base_engine::TexturePtr texture) {
  display_texture_ = texture;
  if (display_) {
    display_->SetImage(display_texture_);
  }
}
