#include "../header/Player.h"
#include "../header/Character.h"
#include "../header/RenderManager.h"

Player::Player(std::string imagePath)
: Character(imagePath),
    cVelocity(5),
    mDirection(Direction::None),
    mFlip(false)
{
    // Set width and height the texture
    mDest.w = mSrc.w = 55;
    mDest.h = mSrc.h = 55;
    // Set texture x and y
    mSrc.x = mSrc.y = 0;
    // Set initial position on the screen
    mDest.x = mDest.y = 0;
}

Player::~Player()
{}

void Player::HandleInput(SDL_Event&& event)
{
    SDL_PollEvent(&event);
    // Set direction and check for texture flipping
    switch (event.key.keysym.sym)
    {
        case SDLK_UP:
            mDirection = Direction::Up;
            break;
        case SDLK_DOWN:
            mDirection = Direction::Down;
            break;
        case SDLK_LEFT:
            mFlip = true;
            mDirection = Direction::Left;
            break;
        case SDLK_RIGHT:
            mFlip = false;
            mDirection = Direction::Right;
            break;
        default:
            break;
    }
}

void Player::Update()
{
    AvoidObstacles();
    DrinkBlood();
}

void Player::Render()
{
    // Flip texture left and right according to player's direction
    if (mFlip)
        RenderManager::Draw(pTexture, mSrc, mDest, SDL_FLIP_HORIZONTAL);
    else
        RenderManager::Draw(pTexture, mSrc, mDest);
}

// Change player's coords unless there is collision with an obstacle
void Player::AvoidObstacles()
{
    if (mDirection == Direction::Up && !(CollisionManager::ObstacleCollision(
        mDest.x, mDest.y - cVelocity, mDest.x + mDest.w, mDest.y + mDest.h - cVelocity)))
    {
        mDest.y-=cVelocity;
    }
    else if (mDirection == Direction::Down && !(CollisionManager::ObstacleCollision(
        mDest.x, mDest.y + cVelocity, mDest.x + mDest.w, mDest.y + mDest.h + cVelocity)))
    {
        mDest.y+=cVelocity;
    }
    else if (mDirection == Direction::Left && !(CollisionManager::ObstacleCollision(
        mDest.x - cVelocity, mDest.y, mDest.x + mDest.w - cVelocity, mDest.y + mDest.h)))
    {
        mDest.x-=cVelocity;
    }
    else if (mDirection == Direction::Right && !(CollisionManager::ObstacleCollision(
        mDest.x + cVelocity, mDest.y, mDest.x + mDest.w + cVelocity, mDest.y + mDest.h)))
    {
        mDest.x+=cVelocity;
    }
    else
    {
        mDirection = Direction::None;
    }
}

void Player::DrinkBlood()
{
    CollisionManager::BloodCollision(
        mDest.x - cVelocity, mDest.y, mDest.x + mDest.w - cVelocity, mDest.y + mDest.h);
}
