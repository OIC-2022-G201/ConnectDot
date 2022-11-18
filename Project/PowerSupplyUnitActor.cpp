#include "PowerSupplyUnitActor.h"

#include <memory>

#include "BaseEngineCore.h"
#include "Circle.h"
#include "CollisionComponent.h"
#include "CollisionLayer.h"
#include "DrawOrder.h"
#include "ElectronicsPower.h"
#include "GridSnapComponent.h"
#include "IBaseEngineTexture.h"
#include "PowerSupplyUnitReceiver.h"
#include "PowerSupplyUnitTransmitter.h"
#include "ReceiverComponent.h"
#include "Rect.h"
#include "ShapeRenderComponent.h"
#include "StageConstitution.h"
#include "TexturePaths.h"
#include "TransmitterComponent.h"
using namespace electronics;
void PowerSupplyUnitActor::Start() {
	{
		const auto cell_half = stage::kStageCellSizeHalf<base_engine::Floating>;
		const auto circle = std::make_shared<base_engine::Circle>(
			cell_half.x, cell_half.y, kPowerRadius);
		const auto shape = new base_engine::ShapeRenderComponent(this, 110);
		shape->SetShape(circle);
		shape->SetFillMode(kElectricAreaFillMode).SetColor(kElectricAreaColor);
		const auto collision = new base_engine::CollisionComponent(this);
		collision->SetShape(circle);
		collision->SetObjectFilter(kPowerSupplyUnitObjectFilter);
		collision->SetTargetFilter(kPowerSupplyUnitTargetFilter);
		collision->SetTrigger(true);
	}

	{
		const auto sign = new base_engine::SpriteComponent(
			this, draw_order::kPowerSupplyUnitDrawOrder);
		const auto img =
			BASE_ENGINE(Texture)->Get(texture::kPowerSupplyUnitTextureKey);
		sign->SetImage(img);
	}

	{
		const auto transmitter = new TransmitterComponent(this, 100);
		transmitter->Create<PowerSupplyUnitTransmitter>(this);

		const auto receiver = new ReceiverComponent(this, 100);
		receiver->Create<PowerSupplyUnitReceiver>(this, target_, transmitter);
	}

	{
		const auto grid = new grid::GridSnapComponent(this);
		grid->SetAutoSnap(grid::AutoSnap::No).SetSnapGridPosition({ 7, 7 });
	}
}
