#include <memory>

#include "../header/Game.h"

int main(int argc, char* argv[])
{
    std::unique_ptr<Game> game(new Game);

    // Initialize game SDL data
    game->Init("Vamp-Man", Game::sWindowWidth, Game::sWindowHeight, false);

    // Target frame rate (Frames Per Second)
    const int FPS = 60;
    // Duration for each frame
    const int targetFrameDuration = 1000 / FPS; // milliseconds
    // Store the two points in time
    Uint32 frameStart;
    int frameTime;

    // Start game
    while (game->IsRunning())
    {
        frameStart = SDL_GetTicks();

        game->HandleInput();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;

        // Delay next iteration to match the target frame time
        if (targetFrameDuration >= frameTime)
            SDL_Delay(targetFrameDuration - frameTime);
    }

    return 0;
}