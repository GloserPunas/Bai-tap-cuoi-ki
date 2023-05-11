#include "Animate.h"

void Animate::Walking(GameObject* obj)
{
    int f = 0;
    //obj -> Render();
    obj -> frames += 2;
    //int const maxFrames = obj -> frames * obj -> srcRect.w;
    obj -> srcRect.x += 2;
    obj -> srcRect.y = 75;
    if (f < obj -> frames)
    {
        obj -> Render();
        obj ->srcRect.x += obj->srcRect.w;
        f++;
    }
    if (obj -> srcRect.x > 528){
            obj -> srcRect.x = 1;
            f = 0;
        }
        SDL_Delay(100);
}
void Animate :: Idle (GameObject* obj)
{
    obj -> srcRect.y = 1;
    int f = 0;
    obj -> Render();
    SDL_Delay(100);
    //int const maxFrames = obj -> frames * obj -> srcRect.w ;
    if (f < obj -> frames)
    {
        obj -> Render();
        obj ->srcRect.x += obj->srcRect.w;
        f++;
    }
    if (obj -> srcRect.x > 558){
            obj -> srcRect.x = 1;
            f = 0;
        }
}
