#include "../header/Map.h"
#include "../header/RenderManager.h"

int map[10][15] =
{
    { 0,0,1,0,0,0,0,0,0,0,0,0,1,0,0 },
    { 0,0,1,0,0,1,1,1,1,1,0,0,1,0,0 },
    { 0,1,1,0,0,0,0,0,0,0,0,0,1,1,0 },
    { 0,0,0,0,1,1,1,0,1,1,1,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 1,1,1,1,1,0,0,0,0,0,1,1,1,1,1 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,1,1,0,0,0,0,0,0,0,0,0,1,1,0 },
    { 0,1,0,0,1,1,1,1,1,1,1,0,0,1,0 },
    { 0,1,0,0,0,0,0,0,0,0,0,0,0,1,0 },
};

Map::Map()
: pFloor(RenderManager::LoadTexture("../assets/floor.png")),
    pObstacle(RenderManager::LoadTexture("../assets/obstacle.png"))
{
    // Set width and height for both floor and obstacles
    SDL_QueryTexture(pFloor, NULL, NULL, &mSrc.w, &mSrc.h);
    // Set space on the screen occupied by the texture
    mDest.w = mSrc.w;
    mDest.h = mSrc.h;
    // Set texture x and y
    mSrc.x = mSrc.y = 0;
    // Set initial position on the screen
    mDest.x = mDest.y = 0;

    LoadMap();
}

Map::~Map()
{
    SDL_DestroyTexture(pFloor);
    SDL_DestroyTexture(pObstacle);
}

int Map::GetCellWidth() const { return mDest.w; }
int Map::GetCellHeight() const { return mDest.h; }

void Map::LoadMap()
{
    // Iterate through the rows of the 2D map 
    for (int row = 0; row < 10; ++row)
    {
        for (int column = 0; column < 15; ++column)
        {
            // Associate numbers of the given map to a tile type
            if (map[row][column] == 0)
            {
                mMap[row][column] = TileType::Floor;
            }
            else if (map[row][column] == 1)
            {
                mMap[row][column] = TileType::Obstacle;
            }
        }
    }
}

void Map::Render()
{
    // Iterate through the rows of the 2D map 
    for (int row = 0; row < 10; ++row)
    {
        // Render tiles based on the data on each map cell
        for (int column = 0; column < 15; ++column)
        {
            // Set x and y positions to start drawing from
            mDest.x = mDest.w * column;
            mDest.y = mDest.h * row;

            // Draw different texture based on the cell tile type
            if (mMap[row][column] == TileType::Floor)
            {
                RenderManager::Draw(pFloor, mSrc, mDest);
            }
            else if (mMap[row][column] == TileType::Obstacle)
            {
                RenderManager::Draw(pObstacle, mSrc, mDest);
            }
        }
    }
}