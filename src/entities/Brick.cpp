#include "entities/Brick.hpp"

Brick::Brick(float startX, float startY, float w, float h, bool alive)
    : x(startX), y(startY), width(w), height(h), isAlive(alive) {};

Brick::~Brick() {};

void Brick::draw()
{
    if (isAlive)
    {
        DrawRectangle(x, y, width, height, GREEN);
    }
}

void Brick::update()
{
}

float Brick::getHeight()
{
    return height;
}

float Brick::getWidth()
{
    return width;
}

bool Brick::getStatus()
{
    return isAlive;
}

float Brick::getX()
{
    return x;
}

float Brick::getY()
{
    return y;
}

void Brick::setStatus(bool stat)
{
    isAlive = stat;
}