#ifndef ANIMATE_H_INCLUDED
#define ANIMATE_H_INCLUDED
#include <SDL.h>
#include "GameObject.h"

class Animate
{
public:
    void static Walking(GameObject* obj);
    void static Idle (GameObject* obj);
};


#endif // ANIMATE_H_INCLUDED
