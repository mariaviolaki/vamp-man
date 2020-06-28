#include <iostream>
#include <memory>

#include "../header/Game.h"

int main(int argc, char* argv[])
{
    std::unique_ptr<Game> game(new Game);

    // Initialize game SDL data
    game->Init("Vamp-Man", Game::sWindowWidth, Game::sWindowHeight, false);

    // Start game
    while (game->IsRunning())
    {
        game->HandleInput();
        game->Update();
        game->Render();
    }

    return 0;
}