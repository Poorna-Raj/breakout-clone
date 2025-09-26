#include "scenes/GameScene.hpp"
#include "raylib.h"
#include <cmath>
#include <iostream>

GameScene::GameScene()
{
    paddle = std::make_unique<Paddle>(0, GetScreenHeight() - 25, 120, 20, 300);
    addBall(paddle.get());
};

GameScene::~GameScene() {};

void GameScene::update()
{
    paddle->update();
    ball->update();
    if (IsKeyPressed(KEY_ENTER))
    {
        startPressed = true;
    }
}

void GameScene::draw()
{
    paddle->draw();
    ball->draw();
    DrawText("Press ENTER to END.", 200, 200, 20, RED);
}

SceneType GameScene::nextScene()
{
    return startPressed ? SceneType::END : SceneType::NONE;
}

void GameScene::addBall(Paddle *paddle)
{
    float startX = paddle->getX() + paddle->getWidth() / 2;
    float startY = paddle->getY() - 100;

    float angle = GetRandomValue(30, 150);
    float rad = angle * PI / 180.0F;
    Vector2 velo = {cosf(rad), -sinf(rad)};

    ball = std::make_unique<Ball>(startX, startY, 20, 20, 350, velo);
    std::cout << "I made the ball" << "\n";
}