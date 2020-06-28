#ifndef GAME_H
#define GAME_H

#include "../header/Map.h"
#include "../header/Player.h"
#include "../header/Garlic.h"
#include "../header/MessageManager.h"
#include "SDL2/SDL.h"
#include <string>
#include <memory>

// Forward class declaration
class MessageManager;

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

    // Static variables of the class
    static const int sWindowWidth;
    static const int sWindowHeight;
    static SDL_Renderer* sRenderer;

private:
    SDL_Window* pWindow;
    bool mIsRunning;
    // Unique pointers
    std::unique_ptr<Map> pMap;
    std::unique_ptr<Player> pPlayer;
    std::unique_ptr<Garlic> pGarlic1;
    std::unique_ptr<Garlic> pGarlic2;
    std::unique_ptr<Garlic> pGarlic3;
    std::unique_ptr<MessageManager> pMessageManager;
};

#endif // GAME_H