#pragma once
#include "raylib.h"
#include <vector>
#include "entities/Brick.hpp"
#include "entities/Ball.hpp"

class BrickManager
{
private:
    const int rows = 10;
    const int columns = 21;
    const float brickWidth = 32.0F;
    const float brickHeight = 16.0F;
    const float spacing = 5.0F;
    std::vector<Brick> bricks;
    Texture2D brickTexture[3];

    int brickRemaining;

public:
    BrickManager();
    ~BrickManager();

    void draw();
    void update();

    bool checkCollision(Ball &ball);
    bool allBricksCleared();

    int getRemainingBricks();
    Texture2D *getRandomTexture();
};