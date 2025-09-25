#include "scenes/StartScene.hpp"
#include "raylib.h"

StartScene::StartScene() {};

StartScene::~StartScene() {};

void StartScene::update()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        startPressed = true;
    }
}

void StartScene::draw()
{
    DrawText("Press ENTER to start.", 200, 200, 20, BLACK);
}

SceneType StartScene::nextScene()
{
    return startPressed ? SceneType::GAME : SceneType::NONE;
}