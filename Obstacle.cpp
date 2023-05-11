#include "Obstacle.h"
#include <cstdlib>
#include <ctime>
#include "TextureManager.h"
#include <random>
#include <math.h>

Obstacle::Obstacle()
{
    obstacle1 = TextureManager::LoadTexture("Image/obstacle1.png");
    obstacle2 = TextureManager::LoadTexture("Image/obstacle2.png");
    obstacle3 = TextureManager::LoadTexture("Image/obstacle3.png");
    obstacle4 = TextureManager::LoadTexture("Image/obstacle4.png");
    GetType();
    GetY();
    x = -100;
    dstRect.w = 64;
    dstRect.h = 60;
}
void Obstacle::Draw()
{
    switch (type)
    {
    case 1:
        SDL_RenderCopy(Game::renderer, obstacle1, NULL, &dstRect);
        break;
    case 2:
        SDL_RenderCopy(Game::renderer, obstacle2, NULL, &dstRect);
        break;
    case 3:
        SDL_RenderCopy(Game::renderer, obstacle3, NULL, &dstRect);
        break;
    case 4:
        SDL_RenderCopy(Game::renderer, obstacle4, NULL, &dstRect);
        break;
    }
}
int Obstacle::GetType()
{
    type = rand()%4 + 1;
    return type;
}
int Obstacle::GetY()
{
    srand (time(NULL));

    int cc = rand();

    int tmp = cc%3;
        switch(tmp)
        {
        case 0:
            y = 320;
            break;
        case 1:
            y = 380;
            break;
        case 2:
            y = 440;
            break;
        }
        return y;
}
void Obstacle::Update()
{
    this -> dstRect.x = x;
    this -> dstRect.y = y;
}
