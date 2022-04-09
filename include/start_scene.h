#pragma once

#include <scene.h>

void start_scene_init();
void start_scene_update();
void start_scene_draw();
void start_scene_destroy();

static scene start_scene = (scene){ 
  *start_scene_init, 
  *start_scene_update, 
  *start_scene_draw, 
  *start_scene_destroy 
};