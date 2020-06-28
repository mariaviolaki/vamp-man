#include "../header/Character.h"
#include "../header/RenderManager.h"

Character::Character(std::string imagePath)
: pTexture(RenderManager::LoadTexture(imagePath))
{}

Character::~Character()
{
    SDL_DestroyTexture(pTexture);
}

int Character::GetX() const { return mDest.x; }
int Character::GetY() const { return mDest.y; }
int Character::GetWidth() const { return mDest.w; }
int Character::GetHeight() const { return mDest.h; }