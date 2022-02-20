#include <stdlib.h>
#include <stdio.h>

#define flecs_STATIC
#include <flecs.h>
#include <raylib.h>

#include <game_lib.h>

Color *colors[] = {
    &RED,
    &ORANGE,
    &YELLOW,
    &GREEN,
    &SKYBLUE,
    &DARKBLUE,
    &VIOLET,
    NULL};

typedef struct ColorComponent
{
  int idx;
} ColorComponent;

void ColorChanger(ecs_iter_t *it)
{
  ColorComponent *c = ecs_term(it, ColorComponent, 1);
  static int counter = 0;
  static int n = 10;
  if (++counter > n) // only update every nth frame
  {
    counter = 0;
  }
  else
  {
    return;
  }
  for (int i = 0; i < it->count; i++)
  {
    c[i].idx++;
    if (colors[c[i].idx] == NULL)
    {
      c[i].idx = 0;
    }
  }
}

int main(void)
{
  ecs_world_t *ecs = ecs_init();
  ECS_COMPONENT(ecs, ColorComponent);
  ECS_SYSTEM(ecs, ColorChanger, EcsOnUpdate, ColorComponent);
  ecs_entity_t e = ecs_new_id(ecs);
  ecs_set(ecs, e, ColorComponent, {0});

  InitWindow(800, 450, "raylib [core] example - basic window");
  SetTargetFPS(add(30, 30));

  while (!WindowShouldClose())
  {
    ecs_progress(ecs, GetFrameTime());
    BeginDrawing();
    ClearBackground(RAYWHITE);
    Color *textcolor = colors[ecs_get(ecs, e, ColorComponent)->idx];
    DrawText("Congrats! You created your first window!", 190, 200, 20, *textcolor);
    EndDrawing();
  }

  CloseWindow();

  return EXIT_SUCCESS;
}
