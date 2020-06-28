#include "../header/Game.h"

// Initialization of static variables
const int Game::sWindowWidth = 960;
const int Game::sWindowHeight = 640;
SDL_Renderer* Game::sRenderer = nullptr;

// Game Constructor
Game::Game()
: pWindow(nullptr),
    mIsRunning(false)
{}

// Game Destructor
Game::~Game()
{
    // Cleanup SDL resources
    SDL_DestroyRenderer(sRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

bool Game::IsRunning() const { return mIsRunning; }

void Game::Init(std::string title, int width, int height, bool fullscreen)
{
    // Initialize SDL subsystems
    SDL_Init(SDL_INIT_EVERYTHING);

    // Set window properties
    int position = SDL_WINDOWPOS_CENTERED;
    int flag = SDL_WINDOW_SHOWN;
    if (fullscreen)
        flag = SDL_WINDOW_FULLSCREEN;

    // Create SDL window from given properties
    pWindow = SDL_CreateWindow(title.c_str(), position, position, width, height, flag);
    // Create SDL renderer from window
    sRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    // Start the game
    mIsRunning = true;
}

void Game::HandleInput()
{
    SDL_Event event;
    int input = SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
        mIsRunning = false;
    }
}

void Game::Update()
{}

void Game::Render()
{
    SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sRenderer);
    SDL_RenderPresent(sRenderer);
}