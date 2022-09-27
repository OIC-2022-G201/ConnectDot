#include "WeakRefObject.h"

base_engine::WeakRefObject::WeakRefObject(Object* p_object)
{ instance_ = p_object;
    ref_ = instance_->GetInstanceId();
}
