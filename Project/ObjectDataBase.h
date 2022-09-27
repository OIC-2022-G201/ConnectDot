// @file ObjectDataBase.h
// @brief 
// @author ICE
// @date 2022/09/27
// 
// @details

#pragma once
#include <cstdint>

#include "ObjectID.h"

class ObjectDataBase
{
#define OBJECTDB_VALIDATOR_BITS 39
#define OBJECTDB_VALIDATOR_MASK ((uint64_t(1) << OBJECTDB_VALIDATOR_BITS) - 1)
#define OBJECTDB_SLOT_MAX_COUNT_BITS 24
#define OBJECTDB_SLOT_MAX_COUNT_MASK \
  ((uint64_t(1) << OBJECTDB_SLOT_MAX_COUNT_BITS) - 1)
#define OBJECTDB_REFERENCE_BIT \
  (uint64_t(1) << (OBJECTDB_SLOT_MAX_COUNT_BITS + OBJECTDB_VALIDATOR_BITS))

  struct ObjectSlot {  // 128 bits per slot.
    uint64_t validator : OBJECTDB_VALIDATOR_BITS;
    uint64_t next_free : OBJECTDB_SLOT_MAX_COUNT_BITS;
    uint64_t is_ref_counted : 1;
    class Object *object = nullptr;
  };
  
  static uint32_t slot_count;
  static uint32_t slot_max;
  static ObjectSlot *object_slots;
  static uint64_t validator_counter;

 public:
    /*
  void AddInstance(Object *p_object)
  {
   if (slot_count == slot_max) {

     uint32_t new_slot_max = slot_max > 0 ? slot_max * 2 : 1;
     object_slots = (ObjectSlot *)memrealloc(object_slots,    sizeof(ObjectSlot) * new_slot_max);
     for (uint32_t i = slot_max; i < new_slot_max; i++) {
       object_slots[i].object = nullptr;
       object_slots[i].is_ref_counted = false;
       object_slots[i].next_free = i;
       object_slots[i].validator = 0;
     }
     slot_max = new_slot_max;
   }

   uint32_t slot = object_slots[slot_count].next_free;
   
   object_slots[slot].object = p_object;
   object_slots[slot].is_ref_counted = p_object->is_ref_counted();
   validator_counter = (validator_counter + 1) & OBJECTDB_VALIDATOR_MASK;
   if (validator_counter == 0) {
     validator_counter = 1;
   }
   object_slots[slot].validator = validator_counter;

   uint64_t id = validator_counter;
   id <<= OBJECTDB_SLOT_MAX_COUNT_BITS;
   id |= uint64_t(slot);

   if (p_object->is_ref_counted()) {
     id |= OBJECTDB_REFERENCE_BIT;
   }

   slot_count++;
  }
  Object *get_instance(base_engine::ObjectId p_instance_id) {
    uint32_t id = static_cast<uint32_t>(p_instance_id);
    uint32_t slot = id & OBJECTDB_SLOT_MAX_COUNT_MASK;
    
    uint64_t validator =
        (id >> OBJECTDB_SLOT_MAX_COUNT_BITS) & OBJECTDB_VALIDATOR_MASK;

    if (unlikely(object_slots[slot].validator != validator)) {
      spin_lock.unlock();
      return nullptr;
    }

    Object *object = object_slots[slot].object;

    spin_lock.unlock();

    return object;
  }
  */
};
