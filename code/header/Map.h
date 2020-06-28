#ifndef MAP_H
#define MAP_H

#include "../header/Obstacle.h"
#include "SDL2/SDL.h"

// Used to mark cells on the map
enum class TileType { Floor, Obstacle };

class Map
{
public:
    Map();
    ~Map();

    // Getters / Setters
    int GetCellWidth() const;
    int GetCellHeight() const;

    // Typical behavior methods
    void Render();

private:
    // Helper method
    void LoadMap();

    TileType mMap[10][15];
    SDL_Texture* pFloor;
    SDL_Texture* pObstacle;
    SDL_Rect mSrc;
    SDL_Rect mDest;
};

#endif // MAP_H