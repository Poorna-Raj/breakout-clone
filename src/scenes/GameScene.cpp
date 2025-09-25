#include "scenes/GameScene.hpp"
#include "raylib.h"

GameScene::GameScene() {};

GameScene::~GameScene() {};

void GameScene::update()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        startPressed = true;
    }
}

void GameScene::draw()
{
    DrawText("Press ENTER to END.", 200, 200, 20, RED);
}

SceneType GameScene::nextScene()
{
    return startPressed ? SceneType::END : SceneType::NONE;
}