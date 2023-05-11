#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED
#include <SDL.h>


class Obstacle
{
public:
    Obstacle();
    ~Obstacle();
    void Draw();
    void Update();
    int GetType();
    int GetY();
    int y;
    int x;
    int type;
private:
    SDL_Rect dstRect;
    SDL_Texture* obstacle1;
    SDL_Texture* obstacle2;
    SDL_Texture* obstacle3;
    SDL_Texture* obstacle4;
};


#endif // OBSTACLE_H_INCLUDED
