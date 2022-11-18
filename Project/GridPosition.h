// @file GridPosition.h
// @brief グリッドベースの座標構造体
// @author ICE
// @date 2022/08/20
// 
// @details

#pragma once
#include <utility>

#include "StageConstitution.h"
#include "Vector.h"

struct GridPosition
{
  int x;
  int y;

  GridPosition(int cell_x, int cell_y)
      : x(cell_x),
        y(cell_y)
  {
  }

  GridPosition(const GridPosition& other)
      : x(other.x),
        y(other.y)
  {
  }

  GridPosition& operator=(const GridPosition& other)
  {
      if (this == &other)
          return *this;
      x = other.x;
      y = other.y;
      return *this;
  }
 
  static GridPosition VectorTo(base_engine::InVector2 pos)
  {
    int x = floor(pos.x / stage::kStageCellWidth<float>);
    int y = floor(pos.y / stage::kStageCellHeight<float>);

    return {x,y};
  }
  static base_engine::Vector2 GridTo(const GridPosition& pos)
  {
    base_engine::Floating x = pos.x * stage::kStageCellWidth<float>;
    base_engine::Floating y = pos.y * stage::kStageCellHeight<float>;
    return {x, y};
  }
  
};
