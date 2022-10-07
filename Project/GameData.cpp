#include "GameData.h"

#include <Utilities/GraphicsUtilities.h>

#include "BaseEngineCore.h"
#include "IBaseEngineRender.h"
#include "IBaseEngineTexture.h"
#include "TexturePaths.h"

void GameData::Register()
{
    BASE_ENGINE(Render)->SetCameraPosition(
        {Mof::CGraphicsUtilities::GetGraphics()->GetTargetWidth() / 2.0f,
            Mof::CGraphicsUtilities::GetGraphics()->GetTargetHeight() / 2.0f});

    BASE_ENGINE(Texture)->Load("ice.png");
    BASE_ENGINE(Texture)->Load(texture::kEnemyTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kPlayerTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kTestTextureKey);

    BASE_ENGINE(Texture)->Load(texture::effect::kElectricEffectTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kSignboardTextureKey);

    BASE_ENGINE(Texture)->Load(texture::kSignboardDisplayDemoTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kPowerSupplyUnitTextureKey);

}
