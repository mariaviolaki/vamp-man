#ifndef CHARACTER_H
#define CHARACTER_H

#include "SDL2/SDL.h"
#include <string>

enum class Direction { None, Up, Down, Right, Left };

class Character
{
public:
    Character(std::string imagePath);
    ~Character();

    int GetX() const;
    int GetY() const;
    int GetWidth() const;
    int GetHeight() const;

    // Pure virtual functions to be overridden by children
    virtual void Update() = 0;
    virtual void Render() = 0;

// Member variables will be visible to derived classes
protected:
    SDL_Texture* pTexture;
    SDL_Rect mSrc;
    SDL_Rect mDest;
};

#endif // CHARACTER_H