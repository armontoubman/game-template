#include <stdlib.h>
#include <stdio.h>

#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <extras/raygui.h>

#include <game_lib.h>

int main(void)
{
  SetTraceLogLevel(LOG_ALL);

  InitWindow(800, 450, "c4xgame");
  SetTargetFPS(60);

  scenes = scene_stack_init();

  scene_stack_push(&scenes, &start_scene);

  while (!WindowShouldClose())
  {
    (*scene_stack_top(&scenes))->update();

    BeginDrawing();
    (*scene_stack_top(&scenes))->draw();
    EndDrawing();
  }

  CloseWindow();

  return EXIT_SUCCESS;
}
