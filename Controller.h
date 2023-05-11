#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include"SDL.h"
#include"GameObject.h"

class Controller
{
    public:
    void static inputHandling(SDL_Event event, GameObject* obj, int x);

};


#endif // CONTROLLER_H_INCLUDED
