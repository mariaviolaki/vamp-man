#ifndef BLOOD_H
#define BLOOD_H

class Blood
{
public:
    // Constructor / Destructor
    Blood(int row, int column, int startX, int startY, int width, int height);
    ~Blood();

    // Accessors / Mutators
    int GetRow() const;
    int GetColumn() const;
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;

private:
    // Row and column on the map
    int mMapCell[2];
    // Coordinates on the screen / dimensions
    int mStartX;
    int mStartY;
    int mWidth;
    int mHeight;
};

#endif // BLOOD_H