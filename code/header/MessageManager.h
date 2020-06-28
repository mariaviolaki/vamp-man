#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include "../header/RenderManager.h"

class MessageManager
{
public:
    // Constructor / Destructor
    MessageManager();
    ~MessageManager();

    // Typical behavior methods
    void ShowMessage(std::string imageName);

private:
    SDL_Texture* pTexture;
    SDL_Rect mSrc;
    SDL_Rect mDest;
};

#endif // MESSAGE_MANAGER_H