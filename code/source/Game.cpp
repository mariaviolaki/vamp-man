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

    // Create instances on the heap
    pMap = std::make_unique<Map>();
    pPlayer = std::make_unique<Player>("../assets/vampire.png");
}

void Game::HandleInput()
{
    SDL_Event event;
    int input = SDL_PollEvent(&event);
    // Check if the user quits the program
    if (event.type == SDL_QUIT)
    {
        mIsRunning = false;
    }
    // Player handles the keyboard and the absence of new events
    else if (event.type == SDL_KEYDOWN || input == 0)
    {
        pPlayer->HandleInput(std::move(event));
    }
}

void Game::Update()
{
    pPlayer->Update();
}

void Game::Render()
{
    // Prepare to render from scratch
    SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sRenderer);

    // Render changes to instances
    pMap->Render();
    pPlayer->Render();

    // Render all the above
    SDL_RenderPresent(sRenderer);
}