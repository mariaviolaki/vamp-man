#ifndef PLAYER_H
#define PLAYER_H

#include "../header/Character.h"

// Use public inheritance so that parent's members remain visible
class Player : public Character
{
public:
    Player(std::string imagePath);
    ~Player();
    void HandleInput(SDL_Event&& event);
    void Update() override;
    void Render() override;

private:
    // Helper methods
    void AvoidObstacles();
    void DrinkBlood();

    const int cVelocity;
    Direction mDirection;
    // Toggle texture's direction horizontally
    bool mFlip;
};

#endif // PLAYER_H