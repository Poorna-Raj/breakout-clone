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
    else
    {
        updatePauseMenu();
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
    drawGameStats();
    if (isPaused)
    {
        drawPauseMenu();
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

void GameScene::drawPauseMenu()
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color){0, 0, 0, 150});
    DrawRectangle(GetScreenWidth() / 2 - 200.0f, GetScreenHeight() / 2 - 112.0f, 400, 225, (Color){30, 30, 30, 220});

    DrawText("GAME PAUSED", GetScreenWidth() / 2 - 115.0f, GetScreenHeight() / 2 - 100.0f, 30, (Color){255, 255, 255, 255});

    Rectangle resumeBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    bool hoveringResume = CheckCollisionPointRec(GetMousePosition(), resumeBtn);
    DrawRectangleRec(resumeBtn, hoveringResume ? (Color){60, 120, 255, 255} : (Color){20, 60, 160, 255});
    DrawText("Resume", resumeBtn.x + 23, resumeBtn.y + 10, 20, (Color){255, 255, 255, 255});

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    bool hoveringExit = CheckCollisionPointRec(GetMousePosition(), exitBtn);
    DrawRectangleRec(exitBtn, hoveringExit ? (Color){255, 60, 60, 255} : (Color){160, 20, 20, 255});
    DrawText("Exit", exitBtn.x + 40, exitBtn.y + 10, 20, (Color){255, 255, 255, 255});
}

void GameScene::updatePauseMenu()
{
    Rectangle resumeBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 - 50.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), resumeBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        isPaused = !isPaused;
    }

    Rectangle exitBtn = {GetScreenWidth() / 2 - 60.0f, GetScreenHeight() / 2 + 30.0f, 120, 40};
    if (CheckCollisionPointRec(GetMousePosition(), exitBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        requestClose = true;
    }
}

bool GameScene::shouldClose()
{
    return requestClose;
}

void GameScene::drawGameStats()
{
    DrawText(TextFormat("Remaining Bricks : %d", brickManager.getRemainingBricks()), 15.0f, 5.0f, 20, YELLOW);
}