#include "entities/Brick.hpp"

Brick::Brick(float startX, float startY, float w, float h, bool alive, Texture2D *tex)
    : x(startX), y(startY), width(w), height(h), isAlive(alive), texture(tex) {};

Brick::~Brick() {};

void Brick::draw()
{
    if (isAlive)
    {
        Rectangle src = {0, 0, (float)texture->width, (float)texture->height};
        Rectangle dest = {x, y, width, height};
        DrawTexturePro(*texture, src, dest, {0, 0}, 0.0F, WHITE);
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