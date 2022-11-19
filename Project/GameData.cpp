﻿#include "GameData.h"

#include <Utilities/GraphicsUtilities.h>

#include <filesystem>

#include "BaseEngineCore.h"
#include "IBaseEngineRender.h"
#include "IBaseEngineTexture.h"
#include "TexturePaths.h"

/**
 * \brief Resourceフォルダ内にある画像ファイルを再帰的に探索し全てロードを行う
 */
void ResourceFolderTextureAllRegister() {
  namespace fs = std::filesystem;
  for (const auto& entry : fs::recursive_directory_iterator(".")) {
    const auto& path = entry.path();
    if (path.extension() != ".png") continue;
    BASE_ENGINE(Texture)->Load(path.generic_string());
  }
}
void GameData::Register() {
  BASE_ENGINE(Render)->SetCameraPosition(
      {Mof::CGraphicsUtilities::GetGraphics()->GetTargetWidth() / 2.0f,
       Mof::CGraphicsUtilities::GetGraphics()->GetTargetHeight() / 2.0f});

  ResourceFolderTextureAllRegister();
}
