#include "../header/Blood.h"

Blood::Blood(int row, int column, int startX, int startY, int width, int height)
: mStartX(startX),
    mStartY(startY),
    mWidth(width),
    mHeight(height)
{
    mMapCell[0] = row;
    mMapCell[1] = column;
}

Blood::~Blood()
{}

int Blood::GetRow() const { return mMapCell[0]; }
int Blood::GetColumn() const { return mMapCell[1]; }
int Blood::GetX() const { return mStartX; }
int Blood::GetY() const { return mStartY; }
int Blood::GetWidth() const { return mWidth; }
int Blood::GetHeight() const { return mHeight; }