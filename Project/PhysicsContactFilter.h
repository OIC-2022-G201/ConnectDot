// @PhysicsContactFilter.h
// @brief
// @author ICE
// @date 2022/10/17
//
// @details

#pragma once
namespace base_engine::physics {
class PhysicsFixture;

class IPhysicsContactFilter {
 public:
  virtual ~IPhysicsContactFilter() = default;

  /// Return true if contact calculations should be performed between these two
  /// shapes.
  /// @warning for performance reasons this is only called when the AABBs begin
  /// to overlap.
  virtual bool ShouldCollide(PhysicsFixture* fixtureA,
                             PhysicsFixture* fixtureB) = 0;
};

class PhysicsContactFilter final : public IPhysicsContactFilter {
 public:
  ~PhysicsContactFilter() override;

  bool ShouldCollide(PhysicsFixture* fixtureA,
                     PhysicsFixture* fixtureB) override;
};
}  // namespace base_engine::physics