#include "entities/Ball.hpp"

Ball::Ball(float startX, float startY, float w, float h, int spd, Vector2 velo)
    : x(startX), y(startY), width(w), height(h), speed(spd), velocity(velo)
{
    texture = LoadTexture("assets/entities/Ball.png");
};

Ball::~Ball()
{
    UnloadTexture(texture);
};

void Ball::draw()
{
    Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
    Rectangle dest = {x, y, width, height};
    DrawTexturePro(texture, src, dest, {0, 0}, 0.0F, WHITE);
}

void Ball::update()
{
    x += velocity.x * speed * GetFrameTime();
    y += velocity.y * speed * GetFrameTime();
}

void Ball::bounceX()
{
    velocity.x *= -1;
}

void Ball::bounceY()
{
    velocity.y *= -1;
}

float Ball::getHeight()
{
    return height;
}

float Ball::getWidth()
{
    return width;
}

float Ball::getX()
{
    return x;
}

float Ball::getY()
{
    return y;
}

void Ball::setY(float posY)
{
    y = posY;
}

void Ball::setVelocity(Vector2 velo)
{
    velocity = velo;
}

int Ball::getSpeed()
{
    return speed;
}

void Ball::setSpeed(int spd)
{
    speed = spd;
}