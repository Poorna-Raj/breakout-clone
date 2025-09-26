#include "scenes/GameScene.hpp"
#include "raylib.h"

GameScene::GameScene()
{
    player = std::make_unique<Paddle>(100, 100, 100, 50, 150);
};

GameScene::~GameScene() {};

void GameScene::update()
{
    player->update();
    if (IsKeyPressed(KEY_ENTER))
    {
        startPressed = true;
    }
}

void GameScene::draw()
{
    player->draw();
    DrawText("Press ENTER to END.", 200, 200, 20, RED);
}

SceneType GameScene::nextScene()
{
    return startPressed ? SceneType::END : SceneType::NONE;
}