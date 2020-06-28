#include "../header/RenderManager.h"

SDL_Texture* RenderManager::LoadTexture(std::string imagePath)
{
    // Load image to a temporary surface
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    // Convert the surface into a texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::sRenderer, surface);
    // The surface is no longer needed
    SDL_FreeSurface(surface);

    return texture;
}

void RenderManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    // Render texture at a given area of the screen
    SDL_RenderCopy(Game::sRenderer, tex, NULL, &dest);
}

void RenderManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, const SDL_RendererFlip flip)
{
    // Render flipped texture at a given area of the screen
    SDL_RenderCopyEx(Game::sRenderer, tex, NULL, &dest, 0.f, NULL, flip);
}