#include "../header/Blood.h"

Blood::Blood(int startX, int startY, int width, int height)
: mStartX(startX),
    mStartY(startY),
    mWidth(width),
    mHeight(height)
{}

Blood::~Blood()
{}

int Blood::GetX() const { return mStartX; }
int Blood::GetY() const { return mStartY; }
int Blood::GetWidth() const { return mWidth; }
int Blood::GetHeight() const { return mHeight; }