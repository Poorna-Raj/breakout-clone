# Breakout Clone

A classic Breakout game implementation built with C++ and Raylib, featuring a modular scene management system and brick management for smooth gameplay.

# Getting Started

## Prerequisites

- C++ Compiler: MinGW (recommended) or any C++17 compatible compiler
- CMake: Version 3.10 or higher
- Raylib
- Git: For cloning the repository

## Building the Project

1. Clone the repository

```bash
git clone https://github.com/Poorna-Raj/breakout-clone.git
cd breakout-clone
```

2. Create build directory

```bash
mkdir build
cd build
```

3. Generate build files with CMake

```bash
cmake .. -G "MinGW Makefiles" ..
```

4. Build the project

```bash
cmake --build .
```

5. Run the game

```bash
./Breakout
```

## How to Play

1. **Start the Game**: Launch the executable
2. **Move the Paddle**: Use `Left Arrow` and `Right Arrow` keys
3. **Pause Menu**: Press `Tab` to open/close the pause menu
4. **Objective**: Break all the bricks by bouncing the ball with your paddle
5. **Don't let the ball fall**: Keep the ball in play by hitting it with your paddle

### Controls

| Key   | Action            |
| ----- | ----------------- |
| `←`   | Move paddle left  |
| `→`   | Move paddle right |
| `Tab` | Toggle pause menu |

## Screenshots

![screenshot 1](docs/ss/start%20screen.png)
![screenshot 2](docs/ss/game%20screen.png)
![screenshot 3](docs/ss/pause%20menu.png)
![screenshot 4](docs/ss/game%20over%20screen.png)

## Technologies Used

- **C++17**: Modern C++ features and standards
- **Raylib**: 2D graphics library for rendering and input
- **CMake**: Cross-platform build system
- **MinGW**: C++ compiler toolchain

## Known Issues

- No audio implementation yet
- Basic collision detection (could be improved for edge cases)
- Limited visual effects

**Break those bricks and have fun! 🧱⚡**
