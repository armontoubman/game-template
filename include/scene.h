#pragma once

typedef struct scene {
  void (*init)();
  void (*update)();
  void (*draw)();
  void (*destroy)();
} scene;
