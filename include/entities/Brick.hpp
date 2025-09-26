#pragma once
#include "raylib.h"

class Brick
{
private:
    float x;
    float y;
    float width;
    float height;
    bool isAlive;

public:
    Brick(float startX, float startY, float w, float h, bool alive = true);
    ~Brick();

    void draw();
    void update();

    float getX();
    float getY();
    float getWidth();
    float getHeight();
    bool getStatus();

    void setStatus(bool stat);
};