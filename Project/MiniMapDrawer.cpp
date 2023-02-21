#include "MiniMapDrawer.h"

#include <algorithm>
#include "BaseEngineCore.h"
#include "CollisionComponent.h"
#include "ComponentServiceLocator.h"
#include "GoalComponent.h"
#include "GridPosition.h"
#include "IBaseEngineRender.h"
#include "IBaseEngineTexture.h"
#include "IBaseEngineCanvasRender.h"
#include "ObjectTileMapComponent.h"
#include "Rect.h"
#include "TileMap.h"

void MiniMapDrawer::Draw(tile_map::TileMapComponent* tile_map) {
    Mof::CRectangle rect;
    const auto pos = BASE_ENGINE(Render)->GetCameraPosition();
    const auto camera_pos = GridPosition::VectorTo({ pos.x, pos.y });

    const auto top = std::max(camera_pos.y - 14, 0);
    const size_t bottom = std::min(top + 36, tile_map->LeftBottom().y);

    const auto left = std::max(camera_pos.x - 20, 0);
    const size_t right = std::min(left + 40, tile_map->LeftBottom().x);

    const auto object_map = ComponentServiceLocator::Instance().
        Resolve<tile_map::ObjectTileMapComponent>();
    
    for (int y = top; y < bottom; ++y) {
        for (int x = left; x < right; ++x) {
            const auto cell = tile_map->GetCell(x, y);
            const auto object_cell = object_map->GetCell(x, y);
            int color = 0;
            int goal_bottom = 0;


            if (IsDrawCell(cell)) {
                color = MOF_COLOR_WHITE;
            }
            else if (IsDrawCell(object_cell)) {
                switch (object_cell) {
                case tile_map::kPowerSupplyCell:
                    color = MOF_COLOR_YELLOW;
                    break;
                case tile_map::kStartCell:
                    color = MOF_COLOR_HBLUE;
                    break;
                case tile_map::kGoalCell:
                    color = MOF_COLOR_RED;
                    goal_bottom = 1;
                    break;
                }
            }
            //else if (render_rect.CollisionPoint(goal_pos))color = HBLUE;

            if (color == 0) continue;

            base_engine::Vector2 map_pos = { 50,50 };
            base_engine::Rect render_rect = {
                map_pos.x + (x - left) * 128 * scale_,map_pos.y + (y - top) * 128 * scale_,
                map_pos.x + (x - left + 1) * 128 * scale_,map_pos.y + (y - top + 1 + goal_bottom) * 128 * scale_
            };

            BASE_ENGINE(CanvasRender)->AddRect(render_rect, color);
            rect.Translation({ 128, 0 });
        }
        rect.Translation({ 0, 128 });
    }
}

bool MiniMapDrawer::IsDrawCell(tile_map::Layer::CellType type) {
    if (type > s_rectangles_.size()) return false;
    if (type == tile_map::kEmptyCell) return false;
    return true;
}

void MiniMapDrawer::Load(tile_map::FrozenMapData map_data) {
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