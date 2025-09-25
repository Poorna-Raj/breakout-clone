#include "raylib.h"
#include "scenes/SceneManager.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Breakout Clone");

    SetTargetFPS(60);

    SceneManager manager;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        manager.update();
        manager.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}