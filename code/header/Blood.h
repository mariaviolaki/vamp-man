#ifndef BLOOD_H
#define BLOOD_H

class Blood
{
public:
    // Constructor / Destructor
    Blood(int startX, int startY, int width, int height);
    ~Blood();

    // Accessors / Mutators
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;

private:
    // Coordinates on the screen / dimensions
    int mStartX;
    int mStartY;
    int mWidth;
    int mHeight;
};

#endif // BLOOD_H