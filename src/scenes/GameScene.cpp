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
    checkBallWallCollision();
    checkBallPaddleCollision(ball.get(), paddle.get());
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
}

void GameScene::checkBallPaddleCollision(Ball *ball, Paddle *paddle)
{
    Rectangle ballRect = {ball->getX(), ball->getY(), ball->getWidth(), ball->getHeight()};
    Rectangle paddleRect = {paddle->getX(), paddle->getY(), paddle->getWidth(), paddle->getHeight()};

    if (CheckCollisionRecs(ballRect, paddleRect))
    {
        ball->bounceY();
    }
}