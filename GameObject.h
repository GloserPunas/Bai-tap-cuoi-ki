#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include"Game.h"

class GameObject
{
public:
    GameObject (const char* textureSheet, int x, int y, int height_, int width_, int x_, int y_, int w, int h);
    ~GameObject();
    GameObject();
    void UpdateObj();
    void Render();
    void Free();
    int xpos, ypos, height, width;
    SDL_Rect srcRect;
    int frames = 1;
    bool isMoving = false;
private:

    SDL_Texture* objTexture;
    SDL_Rect destRect;

};

#endif // GAMEOBJECT_H_INCLUDED
