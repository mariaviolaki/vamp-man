#ifndef GARLIC_H
#define GARLIC_H

#include "../header/Character.h"
#include <random>

// Use public inheritance so that parent's members remain visible
class Garlic : public Character
{
public:
    // Constructor / Destructor
    Garlic(std::string imagePath, int x, int y);
    ~Garlic();

    // Typical behavior methods
    void HandleInput(SDL_Event&& event);
    void Update() override;
    void Render() override;

private:
    // Helper methods
    void ChooseDirection();
    bool AvoidObstacles();

    const int cMinSteps;
    std::mt19937 mRng;
    const int cVelocity;
    Direction mDirection;
    bool mChangeDirection;
    Uint32 mSteps;
};

#endif // GARLIC_H