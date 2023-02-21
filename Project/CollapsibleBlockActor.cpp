#include "CollapsibleBlockActor.h"

#include <filesystem>

#include "BaseEngineCore.h"
#include "CollapsibleBlockReceiver.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "ComponentServiceLocator.h"
#include "DoorReceiver.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridPosition.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "LoadObjectParameter.h"
#include "ObjectTileMapComponent.h"
#include "PlayerComponent.h"
#include "ReceiverComponent.h"
#include "SignboardReceiver.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace base_engine;
using namespace draw_order;

void CollapsibleBlockActor::Create(const LoadObject& object) {
  {
    constexpr auto cell = stage::kStageCellSize<Floating>;
    const auto rect = std::make_shared<Rect>(0, 0, cell.x, cell.y);

    const auto collision = new CollisionComponent(this);
    collision->SetShape(rect);
    collision->SetObjectFilter(kFieldObjectFilter);
    collision->SetTargetFilter(kFieldTargetFilter);
    collision->SetTrigger(true);
  }
  {
    const auto sprite = new SpriteComponent(this, kVentDrawOrder);
    const auto path = "gimmick/Objects/syutugenyuka/syutugenyuka1.png";
    sprite->SetImage(BASE_ENGINE(Texture)->Get(path));
    std::filesystem::path file = path;
    const auto animation = new MofSpriteAnimationComponent(this);
    animation->Load(sprite, file.replace_extension(".aei").string());
    animation->Stop();
  }
  {
    auto block = new CollapsibleBlockComponent(this);

    const auto receiver = new ReceiverComponent(this, 100);
    receiver->Create<CollapsibleBlockReceiver>(block, this);
  }
  {
    const auto grid = new grid::GridSnapComponent(this);
    grid->SetAutoSnap(grid::AutoSnap::No)
        .SetSnapGridPosition({object.object.x, object.object.y});
  }
  SetName("Field");
  SetTag("Field");
}
