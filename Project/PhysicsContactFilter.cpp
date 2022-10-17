#include "PhysicsContactFilter.h"

#include "PhysicsFixture.h"

base_engine::physics::PhysicsContactFilter::~PhysicsContactFilter()
{}

bool base_engine::physics::PhysicsContactFilter::ShouldCollide(PhysicsFixture* fixtureA, PhysicsFixture* fixtureB)
{
    const b2Filter& filterA = fixtureA->GetFilterData();
    const b2Filter& filterB = fixtureB->GetFilterData();

    if (filterA.groupIndex == filterB.groupIndex && filterA.groupIndex != 0) {
        return filterA.groupIndex > 0;
    }

    bool collide = (filterA.maskBits & filterB.categoryBits) != 0 &&
        (filterA.categoryBits & filterB.maskBits) != 0;
    return collide;
}
