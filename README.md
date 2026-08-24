# Pong (SDL2 + C++)

A classic Pong clone built from scratch in C++ using SDL2 — no game engine, just raw rendering, manual game state, and a hand-written game loop.

## Features

- Two-player local play (left paddle: `W`/`S`, right paddle: `Up`/`Down` arrows)
- Smooth, frame-rate-independent movement using delta time
- AABB collision detection between the ball and both paddles
- Ball bounces off top/bottom walls and resets when it passes a paddle
- Simple `Game` class encapsulating the SDL lifecycle (`init` → `handleEvents` → `update` → `render` → `clean`)

## Requirements

- CMake 3.10+
- SDL2 (install via Homebrew: `brew install sdl2`)
- A C++20-compatible compiler

## Building

```bash
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
cmake --build .
```

Or open the project directly in CLion, which will configure the CMake build automatically.

## Controls

| Player       | Move Up | Move Down |
|--------------|---------|-----------|
| Left paddle  | `W`     | `S`       |
| Right paddle | `↑`     | `↓`       |

## Project structure

```
.
├── CMakeLists.txt
├── main.cpp      # entry point, owns the Game instance and main loop
├── pong.h         # Game class declaration
└── pong.cpp       # Game class implementation (SDL setup, input, physics, rendering)
```

## Status / Roadmap

- [x] Paddle rendering and movement
- [x] Ball movement with delta-time-based physics
- [x] Wall and paddle collision
- [ ] Scoring system
- [ ] On-screen score display (SDL_ttf)
- [ ] Sound effects

## About

Built as a learning project while picking up C++ and SDL2 fundamentals — window/renderer setup, event handling, collision detection, and frame-rate-independent movement.
