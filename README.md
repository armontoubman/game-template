# game-template

Project template for games in C, built with CMake.

Includes:

* [raylib](https://github.com/raysan5/raylib) 4.0.0
* [flecs](https://github.com/SanderMertens/flecs) 2.4.8
* [stc](https://github.com/tylov/STC) 3

Dependencies are automatically downloaded and built by CMake.

## Building

### Executable
```bash
mkdir build
cd build
cmake ..
make -j4
```

### Emscripten
```bash
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web
emmake make -j4
emrun app/game.html
```