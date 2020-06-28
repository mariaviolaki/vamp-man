#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

// Handles renderer from Game
#include "../header/Game.h"
#include "SDL2/SDL_image.h"
#include <string>

class RenderManager
{
public:
    static SDL_Texture* LoadTexture(std::string imagePath);

    // Overloads depending on whether the texture will be rendered flipped
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, const SDL_RendererFlip flip);
};

#endif // RENDER_MANAGER_H