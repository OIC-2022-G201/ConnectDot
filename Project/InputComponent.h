#pragma once
#include "InputActor.h"
#include "Component.h"
namespace base_engine {
class InputComponent : public Component {
public:
  InputComponent(class InputActor* owner);
    ~InputComponent() override;

    void ProcessInput() override;

  void Update() override;
};
}  // namespace base_engine