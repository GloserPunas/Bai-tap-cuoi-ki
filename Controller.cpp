#include "Controller.h"
#include "Animate.h"
#include "Game.h"


void  Controller::inputHandling(SDL_Event event, GameObject* obj, int x)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            obj->ypos -= x;

            break;
        case SDLK_DOWN:
            obj->ypos += x;

            break;
        default:
            break;
        }
    case SDL_KEYUP:
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_RIGHT:

                break;
            case SDLK_LEFT:

                break;
            case SDLK_UP:

                break;
            case SDLK_DOWN:

                break;
            default:

                break;
            }

        }
    }
}
