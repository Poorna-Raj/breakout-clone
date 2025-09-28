#include "raylib.h"
#include "scenes/EndScene.hpp"

EndScene::EndScene() {};

EndScene::~EndScene() {};

void EndScene::update()
{
    Rectangle menuBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), menuBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        requestNext = true;
    }

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), exitBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        shouldExit = true;
    }
}

void EndScene::draw()
{
    DrawText("Game Over", 260, 100, 50, WHITE);

    Rectangle menuBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    bool hoveringMenu = CheckCollisionPointRec(GetMousePosition(), menuBtn);
    DrawRectangleRec(menuBtn, hoveringMenu ? (Color){60, 120, 255, 255} : (Color){20, 60, 160, 255});
    DrawText("Menu", menuBtn.x + 40, menuBtn.y + 10, 20, (Color){255, 255, 255, 255});

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    bool hoveringExit = CheckCollisionPointRec(GetMousePosition(), exitBtn);
    DrawRectangleRec(exitBtn, hoveringExit ? (Color){255, 60, 60, 255} : (Color){160, 20, 20, 255});
    DrawText("Exit", exitBtn.x + 40, exitBtn.y + 10, 20, (Color){255, 255, 255, 255});
}

bool EndScene::shouldClose()
{
    return shouldExit;
}

SceneType EndScene::nextScene()
{
    return requestNext ? SceneType::START : SceneType::NONE;
}
