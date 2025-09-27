#include "core/BrickManager.hpp"

BrickManager::BrickManager()
{
    float totalWidth = columns * brickWidth + (columns + 1) * spacing;
    float offsetX = (GetScreenWidth() - totalWidth) / 2.0f;
    float offsetY = 10.0f;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            float x = offsetX + spacing + col * (brickWidth + spacing);
            float y = offsetY + spacing + row * (brickHeight + spacing);

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