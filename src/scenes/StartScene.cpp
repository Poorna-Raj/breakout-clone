#include "scenes/StartScene.hpp"
#include "raylib.h"

StartScene::StartScene() {};

StartScene::~StartScene() {};

void StartScene::update()
{
    Rectangle playBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), playBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        startPressed = true;
    }

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), exitBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        shouldExit = true;
    }
}

void StartScene::draw()
{
    DrawText("Breakout", 280, 100, 50, WHITE);

    Rectangle playBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    bool hoveringPlay = CheckCollisionPointRec(GetMousePosition(), playBtn);
    DrawRectangleRec(playBtn, hoveringPlay ? (Color){60, 120, 255, 255} : (Color){20, 60, 160, 255});
    DrawText("Play", playBtn.x + 40, playBtn.y + 10, 20, (Color){255, 255, 255, 255});

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    bool hoveringExit = CheckCollisionPointRec(GetMousePosition(), exitBtn);
    DrawRectangleRec(exitBtn, hoveringExit ? (Color){255, 60, 60, 255} : (Color){160, 20, 20, 255});
    DrawText("Exit", exitBtn.x + 40, exitBtn.y + 10, 20, (Color){255, 255, 255, 255});
}

SceneType StartScene::nextScene()
{
    return startPressed ? SceneType::GAME : SceneType::NONE;
}

bool StartScene::shouldClose()
{
    return shouldExit;
}