#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include <string>

class Game
{
public:
    // Constructor / Destructor
    Game();
    ~Game();

    // Accessors / Mutators
    bool IsRunning() const;

    // Typical behavior methods
    void Init(std::string title, int width, int height, bool fullscreen);
    void HandleInput();
    void Update();
    void Render();

    static const int sWindowWidth;
    static const int sWindowHeight;
    static SDL_Renderer* sRenderer;

private:
    SDL_Window* pWindow;
    bool mIsRunning;
};

#endif // GAME_H