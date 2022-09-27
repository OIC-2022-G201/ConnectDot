// @file ObjectID.h
// @brief
// @author ICE
// @date 2022/09/25
//
// @details

#pragma once
#include <cstdint>

namespace base_engine {
using ObjectIdType = uint_fast32_t;
class ObjectId {
  ObjectIdType id_ = 0;
  ObjectIdType version_ = 0;

 public:
  [[nodiscard]] bool is_ref_counted() const {
    return (id_ & (1ul << 31)) != 0;
  }

  [[nodiscard]] bool is_valid() const { return id_ != 0; }
  [[nodiscard]] bool is_null() const { return id_ == 0; }
  explicit operator ObjectIdType() const { return id_; }

  bool operator==(const ObjectId &p_id) const {
    return id_ == p_id.id_ && version_ == p_id.version_;
  }
  bool operator!=(const ObjectId &p_id) const {
    return id_ != p_id.id_ || version_ != p_id.version_;
  }
  bool operator<(const ObjectId &p_id) const { return id_ < p_id.id_; }

  ObjectId() = default;
  explicit ObjectId(const ObjectIdType value, const ObjectIdType version) : id_(value),version_(version) {}
};
}  // namespace base_engine