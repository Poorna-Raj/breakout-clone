#include "scenes/GameScene.hpp"
#include "raylib.h"
#include <cmath>
#include <iostream>

GameScene::GameScene()
{
    paddle = std::make_unique<Paddle>(0, GetScreenHeight() - 25, 96, 16, 300);
    addBall(*paddle);
};

GameScene::~GameScene() {};

void GameScene::update()
{
    if (!isPaused)
    {
        paddle->update();
        ball->update();
        checkBallWallCollision();
        checkBallPaddleCollision(*ball, *paddle);
        checkGameStart();
        brickManager.checkCollision(*ball);

        if (brickManager.allBricksCleared())
        {
            startPressed = true;
        }
    }

    if (IsKeyPressed(KEY_TAB))
    {
        isPaused = !isPaused;
    }
}

void GameScene::draw()
{
    brickManager.draw();
    paddle->draw();
    ball->draw();
    if (isPaused)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f));
        DrawText("PAUSED", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2, 30, YELLOW);
    }
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

    ball = std::make_unique<Ball>(startX, startY, 16, 16, 0, velo);
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