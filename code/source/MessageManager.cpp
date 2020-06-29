#include "../header/MessageManager.h"

MessageManager::MessageManager()
: pTexture(nullptr)
{
    // Set starting x and y of the texture 
    mSrc.x = mSrc.y = 0;
    // Set width and height of the texture
    mSrc.w = 600;
    mSrc.h = 350;
    // Set position on screen to center the message
    mDest.x = 60;
    mDest.y = 60;
    mDest.w = Game::sWindowWidth - 140;
    mDest.h = Game::sWindowHeight - 140;
}

MessageManager::~MessageManager()
{
    SDL_DestroyTexture(pTexture);
}

void MessageManager::ShowMessage(std::string imageName)
{
    // Prepare for rendering
    SDL_SetRenderDrawColor(Game::sRenderer, 0, 0, 0, 255);
    SDL_RenderClear(Game::sRenderer);

    // Load and draw the correct image according to input
    pTexture = RenderManager::LoadTexture("../assets/" + imageName + ".png");
    RenderManager::Draw(pTexture, mSrc, mDest);
    SDL_RenderPresent(Game::sRenderer);

    // Show message image for 1.5 seconds
    SDL_Delay(1500);
}
