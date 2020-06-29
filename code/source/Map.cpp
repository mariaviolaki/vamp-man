#include "../header/Map.h"
#include "../header/RenderManager.h"
#include "../header/CollisionManager.h"

int map[10][15] =
{
    { 0,0,1,2,2,2,2,2,2,2,2,2,1,2,2 },
    { 0,0,1,2,2,1,1,1,1,1,2,2,1,2,2 },
    { 2,1,1,2,2,2,2,2,2,2,2,2,1,1,2 },
    { 2,2,2,2,1,1,1,2,1,1,1,2,2,2,2 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 1,1,1,1,1,2,2,2,2,2,1,1,1,1,1 },
    { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 2,1,1,2,2,2,2,2,2,2,2,2,1,1,2 },
    { 2,1,2,2,1,1,1,1,1,1,1,2,2,1,2 },
    { 2,1,2,2,2,2,2,2,2,2,2,2,2,1,2 },
};

Map::Map()
: pFloor(RenderManager::LoadTexture("../assets/floor.png")),
    pObstacle(RenderManager::LoadTexture("../assets/obstacle.png")),
    pBlood(RenderManager::LoadTexture("../assets/blood.png"))
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
    SDL_DestroyTexture(pBlood);
}

int Map::GetCellWidth() const { return mDest.w; }
int Map::GetCellHeight() const { return mDest.h; }
int Map::GetBloodLeft() const { return mBloodDrops; }

// Change the value of a map cell
void Map::SetMapCell(TileType tileType, int row, int column)
{
    mMap[row][column] = tileType;
}

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
                // Create an obstacle and store it in the vector
                mObstacles.emplace_back(std::make_unique<Obstacle>(
                    mDest.w * column + 5, mDest.h * row + 5, mDest.w - 5, mDest.h - 5));
            }
            else if (map[row][column] == 2)
            {
                mMap[row][column] = TileType::Blood;
                // Create a blood object and store it in the vector
                mBloods.emplace_back(std::make_unique<Blood>(
                    row, column, mDest.w * column, mDest.h * row, mDest.w, mDest.h));
            }
        }
    }
}

// Move vectors to CollisionManager
std::vector<std::unique_ptr<Obstacle>> Map::GetObstacles()
{
    return std::move(mObstacles);
}
std::vector<std::unique_ptr<Blood>> Map::GetBloods()
{
    return std::move(mBloods);
}

void Map::Render()
{
    mBloodDrops = 0;

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
            else if (mMap[row][column] == TileType::Blood)
            {
                RenderManager::Draw(pFloor, mSrc, mDest);
                RenderManager::Draw(pBlood, mSrc, mDest);
                mBloodDrops++;
            }
        }
    }
}
