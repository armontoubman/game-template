#pragma once

#include <scene.h>

void game_scene_init();
void game_scene_update();
void game_scene_draw();
void game_scene_destroy();

static scene game_scene = (scene){ 
  *game_scene_init, 
  *game_scene_update, 
  *game_scene_draw, 
  *game_scene_destroy 
};