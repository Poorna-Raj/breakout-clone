#pragma once
#include "raylib.h"

class Ball
{
private:
    float x;
    float y;
    float width;
    float height;
    int speed;
    Vector2 velocity;

public:
    Ball(float startX, float startY, float w, float h, int spd, Vector2 velo);
    ~Ball();

    void draw();
    void update();
    void bounceX();
    void bounceY();

    float getX();
    float getY();
    float getWidth();
    float getHeight();

    void setY(float posY);
    void setVelocity(Vector2 velo);
};