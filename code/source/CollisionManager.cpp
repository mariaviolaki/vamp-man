#include "../header/CollisionManager.h"
#include "../header/Game.h"
#include <memory>
#include <algorithm>

// Initialization of static variables
std::vector<std::unique_ptr<Obstacle>> CollisionManager::mObstacles = {};
std::vector<std::unique_ptr<Blood>> CollisionManager::mBloods = {};
Map* CollisionManager::pMap = nullptr;

CollisionManager::CollisionManager(Map* map)
{
    pMap = map;
    // Store instances created by the map
    mObstacles = std::move(map->GetObstacles());
    mBloods = std::move(map->GetBloods());
}

CollisionManager::~CollisionManager()
{}

bool CollisionManager::ObstacleCollision(int startX, int startY, int endX, int endY)
{
    // Get coordinates of each obstacle
    for (auto const &obstacle : mObstacles)
    {
        int obstacleStartX = obstacle->GetX();
        int obstacleStartY = obstacle->GetY();
        int obstacleEndX = obstacle->GetX() + obstacle->GetWidth();
        int obstacleEndY = obstacle->GetY() + obstacle->GetHeight();

        // All four conditions must apply for two objects to collide
        if (endX > obstacleStartX && endY > obstacleStartY 
            && startX < obstacleEndX && startY < obstacleEndY)
            return true;
    }
    // Check for collision with window borders
    if (startX < 0 || endX > Game::sWindowWidth
        || startY < 0 || endY > Game::sWindowHeight)
        return true;

    return false;
}

void CollisionManager::BloodCollision(int startX, int startY, int endX, int endY)
{
    // Get coordinates of each blood drop
    for (auto const &blood : mBloods)
    {
        int bloodStartX = blood->GetX();
        int bloodStartY = blood->GetY();
        int bloodEndX = blood->GetX() + blood->GetWidth();
        int bloodEndY = blood->GetY() + blood->GetHeight();

        // All four conditions must apply for two objects to collide
        if (endX > bloodStartX && endY > bloodStartY 
            && startX < bloodEndX && startY < bloodEndY)
        {
            // Mark each map cell as 'floor' instead or 'blood'
            pMap->SetMapCell(TileType::Floor, blood->GetRow(), blood->GetColumn());
            // Remove blood instance from the vector
            mBloods.erase(std::find(mBloods.begin(), mBloods.end(), blood));
            break;
        }
    }   
}

bool CollisionManager::GarlicCollision(Player* player, Garlic* garlic)
{
    // Get start and end points of player
    int playerStartX = player->GetX();
    int playerStartY = player->GetY();
    int playerEndX = player->GetX() + player->GetWidth();
    int playerEndY = player->GetY() + player->GetHeight();

    // Get start and end points of garlic
    int garlicStartX = garlic->GetX();
    int garlicStartY = garlic->GetY();
    int garlicEndX = garlic->GetX() + garlic->GetWidth();
    int garlicEndY = garlic->GetY() + garlic->GetHeight();
    
    // Check for collision
    if (playerEndX > garlicStartX && playerEndY > garlicStartY
        && playerStartX < garlicEndX && playerStartY < garlicEndY)
    {
        return true;
    }
    
    return false;
}
