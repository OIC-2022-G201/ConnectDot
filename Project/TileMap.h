﻿// @file TileMap.h
// @brief
// @author ICE
// @date 2022/08/12
//
// @details

#pragma once
#include <filesystem>
#include <vector>
namespace tile_map {
using Cell = char;
constexpr int kEmptyCell = 0;
class Layer {
  using Row = std::vector<Cell>;
  using Collection = std::vector<Row>;

 public:
  Layer() = default;

  Layer(const size_t x, const size_t y)
      : x_(x), y_(y), layer_(Collection(y, Row(x, kEmptyCell))) {}

  Layer(size_t x, size_t y, const Collection& layer)
      : x_(x), y_(y), layer_(layer) {}

  void SetCell(const size_t x, const size_t y, const Cell type) {
    layer_[y][x] = type;
  }
  [[nodiscard]] Cell GetCell(const size_t x, const size_t y) const {
    return layer_[y][x];
  }

  size_t GetXCount() const { return x_; }
  size_t GetYCount() const { return y_; }
  bool Load(const std::filesystem::path& path);

 private:
  size_t x_{};
  size_t y_{};
  Collection layer_{};
};

}  // namespace tile_map
