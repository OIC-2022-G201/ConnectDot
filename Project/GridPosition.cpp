#include "GridPosition.h"

GridPosition GridPosition::operator*(const int i) const {
  return {this->x * i, this->y * i};
}
