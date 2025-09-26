#pragma once

class Paddle
{
private:
    float x;
    float y;
    float width;
    float height;
    int speedX;

public:
    Paddle(float startX, float startY, float w, float h, int spd);
    ~Paddle();

    void draw();
    void update();

    float getX();
    float getY();
    float getWidth();
    float getHeight();

    void moveRight();
    void moveLeft();
};