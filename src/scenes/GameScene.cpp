#include "scenes/GameScene.hpp"
#include "raylib.h"
#include <cmath>
#include <iostream>

GameScene::GameScene()
{
    paddle = std::make_unique<Paddle>(0, GetScreenHeight() - 25, 120, 20, 300);
    addBall(*paddle);
};

GameScene::~GameScene() {};

void GameScene::update()
{
    paddle->update();
    ball->update();
    checkBallWallCollision();
    checkBallPaddleCollision(*ball, *paddle);
    checkGameStart();
    brickManager.checkCollision(*ball);
    if (IsKeyPressed(KEY_ENTER))
    {
        startPressed = true;
    }
}

void GameScene::draw()
{
    paddle->draw();
    ball->draw();
    brickManager.draw();
    DrawText("Press ENTER to END.", 200, 200, 20, RED);
}

SceneType GameScene::nextScene()
{
    return startPressed ? SceneType::END : SceneType::NONE;
}

void GameScene::addBall(Paddle &paddle)
{
    float startX = paddle.getX() + paddle.getWidth() / 2;
    float startY = paddle.getY() - 20;

    float angle = GetRandomValue(30, 150);
    float rad = angle * PI / 180.0F;
    Vector2 velo = {cosf(rad), -sinf(rad)};

    ball = std::make_unique<Ball>(startX, startY, 20, 20, 0, velo);
}

void GameScene::checkBallWallCollision()
{
    if (ball->getX() < 0)
    {
        ball->bounceX();
    }

    if (ball->getX() > GetScreenWidth() - ball->getWidth())
    {
        ball->bounceX();
    }

    if (ball->getY() < 0)
    {
        ball->bounceY();
    }

    if (ball->getY() > GetScreenHeight() - ball->getHeight())
    {
        startPressed = true;
    }
}

void GameScene::checkBallPaddleCollision(Ball &ball, Paddle &paddle)
{
    Rectangle ballRect = {ball.getX(), ball.getY(), ball.getWidth(), ball.getHeight()};
    Rectangle paddleRect = {paddle.getX(), paddle.getY(), paddle.getWidth(), paddle.getHeight()};

    if (CheckCollisionRecs(ballRect, paddleRect))
    {
        ball.bounceY();
    }
}

void GameScene::checkGameStart()
{
    if (IsKeyPressed(KEY_SPACE) && ball->getSpeed() == 0)
    {
        ball->setSpeed(350);
    }
}