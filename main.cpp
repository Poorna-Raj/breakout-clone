#include "raylib.h"
#include "core/SceneManager.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Breakout Clone");

    SetTargetFPS(60);

    SceneManager manager;

    while (!WindowShouldClose() && !manager.shouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        manager.update();
        manager.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}