#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "../header/Map.h"
#include "../header/Obstacle.h"
#include "../header/Player.h"
#include "../header/Blood.h"
#include "../header/Garlic.h"
#include <vector>
#include <memory>

// Must be initialized after Map to store the obstacles
class CollisionManager
{
public:
    // Constructor / Destructor
    CollisionManager(Map* map);
    ~CollisionManager();

    // Static functions
    static bool ObstacleCollision(int startX, int startY, int endX, int endY);
    static void BloodCollision(int startX, int startY, int endX, int endY);
    static bool GarlicCollision(Player* player, Garlic* garlic);

    // Static variables
    static std::vector<std::unique_ptr<Obstacle>> mObstacles;
    static std::vector<std::unique_ptr<Blood>> mBloods;
    static std::vector<std::unique_ptr<Garlic>> mGarlics;
    static Map* pMap;    
};

#endif // COLLISION_MANAGER_H