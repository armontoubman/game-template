#include <start_scene.h>

#include <raylib.h>
#include <extras/raygui.h>
#include <scene_stack.h>

#include <game_scene.h>

bool start_scene_start = false;

void start_scene_init()
{
  start_scene_start = false;
}

void start_scene_update()
{
  if(start_scene_start)
  {
    scene_stack_init_push(&scenes, &game_scene);
  }
}

void start_scene_draw()
{
  ClearBackground(RAYWHITE);

  start_scene_start = GuiButton((Rectangle){32, 32, 128, 32}, "Start");
}

void start_scene_destroy()
{
  start_scene_start = false;
}