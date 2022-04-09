#include <game_scene.h>

#include <flecs.h>
#include <raylib.h>

#include <scene_stack.h>

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

ecs_world_t *ecs;
ecs_entity_t e;

void game_scene_init()
{
  ecs = ecs_init();
  ECS_COMPONENT(ecs, ColorComponent);
  ECS_SYSTEM(ecs, ColorChanger, EcsOnUpdate, ColorComponent);
  e = ecs_new_id(ecs);
  ecs_set(ecs, e, ColorComponent, {0});
}

void game_scene_update()
{
}

void game_scene_draw()
{
  ClearBackground(RAYWHITE);

  ECS_COMPONENT(ecs, ColorComponent);
  ecs_progress(ecs, GetFrameTime());
  BeginDrawing();
  ClearBackground(RAYWHITE);
  Color *textcolor = colors[ecs_get(ecs, e, ColorComponent)->idx];
  DrawText("Congrats! You created your first window!", 190, 200, 20, *textcolor);
  EndDrawing();
}

void game_scene_destroy()
{
}