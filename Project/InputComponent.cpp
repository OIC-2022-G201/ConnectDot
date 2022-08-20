#include "InputComponent.h"

#include "ComponentParameter.h"

namespace base_engine {
InputComponent::InputComponent(InputActor* owner)
    : Component(owner,kInputUpdateOrder)
{
    
}

InputComponent::~InputComponent()
{
}

void InputComponent::ProcessInput()
{
        
}

void InputComponent::Update()
{
        
}
}  // namespace base_engine