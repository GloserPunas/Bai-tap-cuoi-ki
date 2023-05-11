#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Game.h"

class Map
{
public:
    Map(int arr[20][25]);
    ~Map();
    //void LoadMap(int arr[20][25]);
    void DrawMap();
    int map_[20][25];
    void Update();
private:
    SDL_Rect src, dest;
    SDL_Texture* pathwgrass;
    SDL_Texture* ground;
    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* sky;
};


#endif // MAP_H_INCLUDED
