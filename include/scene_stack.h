#pragma once

typedef scene * scene_ptr;

#define i_type scene_stack
#define i_val scene_ptr
#include <stc/cstack.h>

extern scene_stack scenes;

static inline scene_ptr scene_stack_init_push(scene_stack*, scene_ptr); 
static inline void scene_stack_destroy_pop(scene_stack*);

static inline scene_ptr scene_stack_init_push(scene_stack* stack, scene_ptr val)
{
  val->init();
  return (*scene_stack_push(stack, val));
}

static inline void scene_stack_destroy_pop(scene_stack* stack)
{
  (*scene_stack_top(stack))->destroy();
  scene_stack_pop(stack);
}