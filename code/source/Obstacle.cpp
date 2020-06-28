#include "../header/Obstacle.h"

Obstacle::Obstacle(int startX, int startY, int width, int height)
: mStartX(startX),
    mStartY(startY),
    mWidth(width),
    mHeight(height)
{}

Obstacle::~Obstacle()
{}

int Obstacle::GetX() const { return mStartX; }
int Obstacle::GetY() const { return mStartY; }
int Obstacle::GetWidth() const { return mWidth; }
int Obstacle::GetHeight() const { return mHeight; }