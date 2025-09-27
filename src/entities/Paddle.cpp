#include "entities/Paddle.hpp"

Paddle::Paddle(float startX, float startY, float w, float h, int spd)
    : x(startX), y(startY), width(w), height(h), speedX(spd)
{
    texture = LoadTexture("assets/entities/Paddle.png");
};

Paddle::~Paddle()
{
    UnloadTexture(texture);
};

void Paddle::draw()
{
    Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
    Rectangle dest = {x, y, width, height};
    DrawTexturePro(texture, src, dest, {0, 0}, 0.0F, WHITE);
}

void Paddle::update()
{
    if (x > 0)
    {
        moveLeft();
    }

    if (x < GetScreenWidth() - width)
    {
        moveRight();
    }
}

void Paddle::moveLeft()
{
    if (IsKeyDown(KEY_LEFT))
    {
        x -= speedX * GetFrameTime();
    }
}

void Paddle::moveRight()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        x += speedX * GetFrameTime();
    }
}

float Paddle::getX()
{
    return x;
};
float Paddle::getY()
{
    return y;
};
float Paddle::getWidth()
{
    return width;
};
float Paddle::getHeight()
{
    return height;
};