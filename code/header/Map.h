#ifndef MAP_H
#define MAP_H

#include "../header/Obstacle.h"
#include "../header/Blood.h"
#include "SDL2/SDL.h"
#include <vector>
#include <memory>

// Used to mark cells on the map
enum class TileType { Floor, Obstacle, Blood };

class Map
{
public:
    // Constructor / Destructor
    Map();
    ~Map();

    // Getters / Setters
    int GetCellWidth() const;
    int GetCellHeight() const;
    int GetBloodLeft() const; // if 0, the player won the game
    void SetMapCell(TileType tileType, int row, int column);

    // Move obstacles and blood to CollisionManager
    std::vector<std::unique_ptr<Obstacle>> GetObstacles();
    std::vector<std::unique_ptr<Blood>> GetBloods();

    // Typical behavior methods
    void Render();

private:
    // Helper method
    void LoadMap();

    TileType mMap[10][15];
    SDL_Texture* pFloor;
    SDL_Texture* pObstacle;
    SDL_Texture* pBlood;
    SDL_Rect mSrc;
    SDL_Rect mDest;
    int mBloodDrops;
    // Store obstacles and blood drops loaded on the map
    std::vector<std::unique_ptr<Obstacle>> mObstacles;
    std::vector<std::unique_ptr<Blood>> mBloods;
};

#endif // MAP_H