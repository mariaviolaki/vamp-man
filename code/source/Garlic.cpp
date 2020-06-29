#include "../header/Garlic.h"
#include "../header/RenderManager.h"

Garlic::Garlic(std::string imagePath, int x, int y)
: Character(imagePath),
    cMinSteps(150),
    mRng(std::random_device{}()),
    cVelocity(2),
    mDirection(Direction::None),
    mChangeDirection(true),
    mSteps(0)
{
    // Set width and height the texture
    mDest.w = mSrc.w = 55;
    mDest.h = mSrc.h = 55;
    // Set texture x and y
    mSrc.x = mSrc.y = 0;
    // Set initial position on the screen
    mDest.x = x;
    mDest.y = y;
}

Garlic::~Garlic()
{}

void Garlic::Update()
{
    do
    {
        ChooseDirection();
    }
    while (!AvoidObstacles());
}

void Garlic::Render()
{
    RenderManager::Draw(pTexture, mSrc, mDest);
}

void Garlic::ChooseDirection()
{
    if (!mChangeDirection)
        return;

    // Set random number range between 0 and 3 (inclusive)
    std::uniform_int_distribution<int> distribution(0, 3);
    // Choose a random number
    int randomNum = distribution(mRng);
    // Associate the number to a direction
    switch (randomNum)
    {
    case 0:
        mDirection = Direction::Up;
        break;
    case 1:
        mDirection = Direction::Down;
        break;
    case 2:
        mDirection = Direction::Left;
        break;
    case 3:
        mDirection = Direction::Right;
        break;
    }
}

// Change Garlic's coords unless there is collision with an obstacle
bool Garlic::AvoidObstacles()
{
    mChangeDirection = false;
    // Check if garlic has made too many steps
    if (mSteps > cMinSteps)
    {
        // Set random number range between 0 and 1 (inclusive)
        std::uniform_int_distribution<int> distribution(0, 1);
        // Choose a random number
        bool keepMoving = distribution(mRng);
        // 50% chance to change direction
        if (!keepMoving)
        {
            mChangeDirection = true;
            mSteps = 0;
            return false;
        }
    }

    // Move according to the current direction and avoid obstacles
    if (mDirection == Direction::Up && !(CollisionManager::ObstacleCollision(
        mDest.x, mDest.y - cVelocity, mDest.x + mDest.w, mDest.y + mDest.h - cVelocity)))
    {
        mDest.y-=cVelocity;
        mSteps++;
        return true;
    }
    else if (mDirection == Direction::Down && !(CollisionManager::ObstacleCollision(
        mDest.x, mDest.y + cVelocity, mDest.x + mDest.w, mDest.y + mDest.h + cVelocity)))
    {
        mDest.y+=cVelocity;
        mSteps++;
        return true;
    }
    else if (mDirection == Direction::Left && !(CollisionManager::ObstacleCollision(
        mDest.x - cVelocity, mDest.y, mDest.x + mDest.w - cVelocity, mDest.y + mDest.h)))
    {
        mDest.x-=cVelocity;
        mSteps++;
        return true;
    }
    else if (mDirection == Direction::Right && !(CollisionManager::ObstacleCollision(
        mDest.x + cVelocity, mDest.y, mDest.x + mDest.w + cVelocity, mDest.y + mDest.h)))
    {
        mDest.x+=cVelocity;
        mSteps++;
        return true;
    }

    mChangeDirection = true;
    mSteps = 0;

    return false;
}
