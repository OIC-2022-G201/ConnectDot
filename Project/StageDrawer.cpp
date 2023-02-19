#include "StageDrawer.h"

#include <algorithm>
#include "BaseEngineCore.h"
#include "GridPosition.h"
#include "IBaseEngineRender.h"
#include "IBaseEngineTexture.h"
#include "Rect.h"
#include "TileMap.h"

#include "CollisionComponent.h"

void StageDrawer::Draw(tile_map::TileMapComponent* tile_map) {
    Mof::CRectangle rect;
    const auto pos = BASE_ENGINE(Render)->GetCameraPosition();
    const auto camera_pos = GridPosition::VectorTo({ pos.x, pos.y });

    const auto top = std::max(camera_pos.y - 7, 0);
    const size_t bottom = std::min(top + 18, tile_map->LeftBottom().y);

    const auto left = std::max(camera_pos.x - 10, 0);
    const size_t right = std::min(left + 20, tile_map->LeftBottom().x);

    for (int y = top; y < bottom; ++y) {
        for (int x = left; x < right; ++x) {
            const auto cell = tile_map->GetCell(x,y);
            if (cell == tile_map::kEmptyCell) continue;
            if (cell > 5) {
                int n = 3;
            }
            if (cell > s_rectangles_.size()) {
                continue;
            }

            BASE_ENGINE(Render)->AddTexture(
                texture_, { x * 128.0f, y * 128.0f }, { 1, 1 }, 0,
                s_rectangles_[cell - 1], MOF_COLOR_WHITE,
                Mof::TextureAlignment::TEXALIGN_TOPLEFT);
            rect.Translation({ 128, 0 });
        }
        rect.Translation({ 0, 128 });
    }
}

void StageDrawer::Load(tile_map::FrozenMapData map_data) {
    const int cell_size_ = map_data.chip_size;

    texture_ = BASE_ENGINE(Texture)->Get(map_data.map_chip_path);
    const auto tx = texture_->GetWidth() / cell_size_;
    const auto ty = texture_->GetHeight() / cell_size_;
    for (int y = 0; y < ty; ++y) {
        for (int x = 0; x < tx; ++x) {
            s_rectangles_.emplace_back(x * cell_size_, y * cell_size_,
                (x + 1) * cell_size_,
                (y + 1) * cell_size_);
        }
    }
}