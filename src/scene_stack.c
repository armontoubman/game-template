#include <scene.h>
typedef scene * scene_ptr;

#include <stc/forward.h>
forward_cstack(scene_stack, scene_ptr);

scene_stack scenes;