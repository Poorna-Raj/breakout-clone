#include "entities/Paddle.hpp"
#include "raylib.h"

Paddle::Paddle(float startX, float startY, float w, float h, int spd)
    : x(startX), y(startY), width(w), height(h), speedX(spd) {};

Paddle::~Paddle() {};

void Paddle::draw()
{
    DrawRectangle(x, y, width, height, BLUE);
}

void Paddle::update()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        x += speedX * GetFrameTime();
    }

    if (IsKeyDown(KEY_LEFT))
    {
        x -= speedX * GetFrameTime();
    }
}