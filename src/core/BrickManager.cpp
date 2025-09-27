#include "core/BrickManager.hpp"

BrickManager::BrickManager()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            float x = col * (brickWidth + spacing);
            float y = row * (brickHeight + spacing) + 5;
            bricks.emplace_back(x, y, brickWidth, brickHeight, true);
        }
    }

    brickRemaining = rows * columns;
}

BrickManager::~BrickManager() {};

void BrickManager::draw()
{
    for (auto &brick : bricks)
    {
        brick.draw();
    }
}

void BrickManager::update()
{
}

bool BrickManager::checkCollision(Ball &ball)
{
    for (auto &brick : bricks)
    {
        if (!brick.getStatus())
        {
            continue;
        }

        Rectangle brickRect = {brick.getX(), brick.getY(), brick.getWidth(), brick.getHeight()};
        Rectangle ballRect = {ball.getX(), ball.getY(), ball.getWidth(), ball.getHeight()};

        if (CheckCollisionRecs(brickRect, ballRect))
        {
            brick.setStatus(false);
            ball.bounceY();

            brickRemaining--;
            return true;
        }
    }
    return false;
}

bool BrickManager::allBricksCleared()
{
    return brickRemaining == 0;
}