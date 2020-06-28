#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle
{
public:
    // Constructor / Destructor
    Obstacle(int startX, int startY, int width, int height);
    ~Obstacle();

    // Accessors / Mutators
    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;

private:
    // Starting coordinates on the screen
    int mStartX;
    int mStartY;
    int mWidth;
    int mHeight;
};

#endif // OBSTACLE_H