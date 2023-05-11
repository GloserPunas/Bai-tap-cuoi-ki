#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int x, int y, int height, int width, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean ();
    bool running();
    bool gameOver();
    void Pause();
    void menu();
    void printGameOver();
    void refresh();

    int tmpx, tmpy;


    static SDL_Renderer *renderer;
    static SDL_Event event;
private:
    SDL_Window *window;
    bool isRunning;
    bool gameover;
    bool start;
    bool pause;

};
#endif // GAME_H_INCLUDED
