#pragma once
#include "raylib.h"
#include <vector>
#include "entities/Brick.hpp"
#include "entities/Ball.hpp"

class BrickManager
{
private:
    const int rows = 5;
    const int columns = 10;
    const float brickWidth = 80;
    const float brickHeight = 30;
    const float spacing = 5;
    std::vector<Brick> bricks;

public:
    BrickManager();
    ~BrickManager();

    void draw();
    void update();

    bool checkCollision(Ball &ball);
};