#include "DummyActor.h"

namespace enemy {
	DummyActor::DummyActor(base_engine::Game* game) :Actor(game) {}
	DummyActor::~DummyActor() {}

	void DummyActor::Start() {
		SetTag("Dummy");
	}

	void DummyActor::Update() {

	}
}