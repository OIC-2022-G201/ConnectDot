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

    BASE_ENGINE(Texture)->Load(texture::effect::kElectricEffectTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kSignboardTextureKey);

    BASE_ENGINE(Texture)->Load(texture::kSignboardDisplayDemoTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kPowerSupplyUnitTextureKey);

    BASE_ENGINE(Texture)->Load(texture::kRestartButtonTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kResumeButtonTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kChangeRestartButtonTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kChangeResumeButtonTextureKey);

    BASE_ENGINE(Texture)->Load(texture::kZeroTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kOneTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kTwoTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kThreeTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kFourTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kFiveTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kSixTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kSevenTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kEightTextureKey);
    BASE_ENGINE(Texture)->Load(texture::kNineTextureKey);
}
