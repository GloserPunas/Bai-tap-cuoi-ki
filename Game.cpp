#include"Game.h"
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include <math.h>
#include"TextureManager.h"
#include"GameObject.h"
#include "Map.h"
#include <vector>
#include "Controller.h"
#include "Animate.h"
#include "Text.h"
#include <cstdlib>
#include <time.h>
#include "Obstacle.h"

using namespace std;

SDL_Renderer*Game::renderer = nullptr;

SDL_Event Game::event;


GameObject* cat2;
GameObject* flower;
GameObject* tree;
GameObject* tree1;
GameObject* tree2;
GameObject* tree3;
GameObject* house;
GameObject* flower2;
GameObject* flower1;
GameObject* flower3;
GameObject* flower4;
GameObject* flower5;

GameObject* newgame;
GameObject* quit;
GameObject* pausebutton;
GameObject* resume;

GameObject* gameover_;



Obstacle* obs1;
Obstacle* obs2;
Obstacle* obs3;
Obstacle* obs4;
Obstacle* obs5;
Obstacle* obs6;

int lvl1[20][25] ={
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


Map* map_;

int posx = 500, posy = 350;
int v1 = 25, v2 = 30;

SDL_Rect srcR, destR;
SDL_Rect bgR = {1, 1, 1000, 700};
SDL_Rect pR = {250, 50, 550, 620};


Uint32 FrameStart;
int FrameTime;
int const ANIMATIONFRAME = 5;
int frame = 0;

LTexture* text;

SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int x, int y, int height, int width, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING)== 0)
    {
        cout << "Subsystem initialized" << endl;
        window = SDL_CreateWindow(title, x, y, height,  width, flags);
        if(window)
        {
            cout << "Window created" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            cout << "Renderer created" << endl;
        }
        isRunning = true;
    }
    int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                }
    if (TTF_Init() == -1)
	{
		std::cout << "Error : SDL_TTF" << std::endl;
	}
    else cout << "TTF is ready!" << endl;

    gameover = false;
    start = false;

    newgame = new GameObject ("Image/button/newgame1.png", 400, 350, 100, 200, 1, 1, 496, 158 );
    quit = new GameObject ("Image/button/quit1.png", 400, 500, 100, 200, 1, 1, 572, 185);
    pausebutton = new GameObject ("Image/button/pause.png", 930, 2, 64, 64, 1, 1, 469, 387);
    resume = new GameObject ("Image/button/resume1.png", 430, 250, 100, 200, 1, 1, 474, 154);

    cat2 = new GameObject("Image/catmain.png", 900, 350, 70, 70, 1, 1, 94, 75);
    flower = new GameObject("Image/flower.png", 200, 300, 29, 29, 1, 1, 29, 29);
    flower1 = new GameObject("Image/flower.png", 700, 300, 29, 29, 1, 1, 29, 29);
    flower3 = new GameObject("Image/flower.png", 600, 300, 29, 29, 1, 1, 29, 29);
    flower4 = new GameObject("Image/flower.png", 500, 300, 29, 29, 1, 1, 29, 29);
    flower5 = new GameObject("Image/flower.png", 400, 300, 29, 29, 1, 1, 29, 29);
    flower2 = new GameObject("Image/flower.png", 300, 300, 29, 29, 1, 1, 29, 29);
    house = new GameObject("Image/house.png", 1, 10, 300, 600, 1, 1, 577, 167);
    tree = new GameObject ("Image/baum.png", 650, 100, 200, 200, 1, 1, 128, 128 );
    tree1 = new GameObject ("Image/baum.png", 550, 100, 200, 200, 1, 1, 128, 128 );
    tree2 = new GameObject ("Image/baum.png", 750, 100, 200, 200, 1, 1, 128, 128 );
    tree3 = new GameObject ("Image/baum.png", 850, 100, 200, 200, 1, 1, 128, 128 );

    map_ = new Map(lvl1);
    text = new LTexture("Hello World!", 100, 100, 100, 30);

    obs1 = new Obstacle();
    obs2 = new Obstacle();
    obs2 -> x -= 100;
    obs3 = new Obstacle();
    obs3 -> x-= 200;
    obs4 = new Obstacle();
    obs4 -> x -= 300;
    obs5 = new Obstacle();
    obs5 -> x -= 400;
    obs6 = new Obstacle();
    obs6 -> x -= 500;

    gameover_ = new GameObject("Image/gameover.png", 1, 1, 700, 1000, 1, 1, 1000, 700);
}
void Game::menu()
{
    SDL_Surface* surface = IMG_Load("Image/welcome_screen.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &bgR);
    newgame -> Render();
    quit -> Render();

    if ( tmpx >= 400 && tmpx <= 600 && tmpy <= 450 && tmpy >= 350 )
    {
        newgame = new GameObject ("Image/button/newgame2.png", 400, 350, 100, 200, 1, 1, 616, 199 );
        if (event.button.type == SDL_MOUSEBUTTONUP || event.button.type == SDL_MOUSEBUTTONDOWN )
        if (event.button.state == SDL_PRESSED && event.button.clicks == 1)
        {
            start = true;
        }
    }
    else newgame = new GameObject ("Image/button/newgame1.png", 400, 350, 100, 200, 1, 1, 496, 158 );
    if (tmpx >= 400 && tmpx <= 600 && tmpy >= 500 && tmpy <= 650)
    {
        quit = new GameObject ("Image/button/quit2.png", 400, 500, 100, 200, 1, 1, 654, 211);
        if (event.button.type == SDL_MOUSEBUTTONUP || event.button.type == SDL_MOUSEBUTTONDOWN )
        if (event.button.state == SDL_PRESSED && event.button.clicks == 1)
        {
            SDL_Quit();
        }
    }
    else quit = new GameObject ("Image/button/quit1.png", 400, 500, 100, 200, 1, 1, 572, 185);
}
void Game::update()
{
    newgame -> UpdateObj();
    quit -> UpdateObj();
    pausebutton -> UpdateObj();
    resume -> UpdateObj();

    if (event.button.y != 0)
    {
        tmpy = event.button.y;
    }
    if (event.button.x != 0)
    {
        tmpx = event.button.x;
    }

    cat2 -> UpdateObj();
    flower -> UpdateObj();
    flower1 -> UpdateObj();
    flower3 -> UpdateObj();
    flower4-> UpdateObj();
    flower5 -> UpdateObj();
    flower2 -> UpdateObj();
    tree -> UpdateObj();
    tree1 -> UpdateObj();
    tree2 -> UpdateObj();
    tree3 -> UpdateObj();

    house -> UpdateObj();
    gameover_ -> UpdateObj();

    map_ -> Update();

    obs1 -> Update();
    obs2 -> Update();
    obs3 -> Update();
    obs4 -> Update();
    obs5 -> Update();
    obs6 -> Update();


    Controller ::inputHandling(event, cat2, v1);
    if(cat2 -> ypos > 440)
    {
        cat2 -> ypos = 440;
    }
    if (cat2 -> ypos < 280)
    {
        cat2 -> ypos = 280;
    }
}
void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    }
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    //add function here
    if (!start)
    menu();
    //cout << tmpx << " " << tmpy << endl;
    if (start)
    {
        SDL_RenderClear(renderer);
    if (!gameover)
    {

    map_ ->DrawMap();
    pausebutton -> Render();

    flower -> Render();
    flower1 -> Render();
    flower3 -> Render();
    flower4 -> Render();
    flower5 -> Render();
    flower2 -> Render();
    house -> Render();
    tree -> Render();
    tree1 -> Render();
    tree2 -> Render();
    tree3 -> Render();

    obs1 ->Draw();
    obs2 ->Draw();
    obs3 ->Draw();
    obs4 ->Draw();
    obs5 ->Draw();
    obs6 ->Draw();

    cat2 -> Render();
    Animate::Idle(cat2);

    house -> xpos += v1;
    flower -> xpos += v1;
    flower1 -> xpos += v1;
    flower2 -> xpos += v1;
    flower3 -> xpos += v1;
    flower4 -> xpos += v1;
    flower5 -> xpos += v1;
    tree -> xpos += v1;
    tree1 -> xpos += v1;
    tree2 -> xpos += v1;
    tree3 -> xpos += v1;

    obs1 -> x += v2;
    obs2 -> x += v2;
    obs3 -> x += v2;
    obs4 -> x += v2;
    obs5 -> x += v2;
    obs6 -> x += v2;

     if (obs1 -> x > 1000)
    {
        obs1 = new Obstacle();
    }
     if (obs2 -> x > 1000)
    {
        obs2 = new Obstacle();
    }
     if (obs3 -> x > 1000)
    {
        obs3 = new Obstacle();
    }
    if (obs4 -> x > 1000)
    {
        obs4 = new Obstacle();
    }
     if (obs5 -> x > 1000)
    {
        obs5 = new Obstacle();
    }
     if (obs6 -> x > 1000)
    {
        obs6 = new Obstacle();
    }

    Game::gameOver();

    if (tmpx >= 600 && tmpx <= 990 && tmpy <= 60)
    {
        if (event.button.type == SDL_MOUSEBUTTONUP || event.button.type == SDL_MOUSEBUTTONDOWN )
        if (event.button.state == SDL_PRESSED && event.button.clicks == 1)
        {
            pause = true;
        }

    }
    }
    if (gameover)
    {
        SDL_RenderClear(renderer);
        clock_t start = clock();
        while ( clock() - start < 700)
        {

        }
        printGameOver();
    }
    if (pause)
    {
            Pause();
    }
    }

    SDL_RenderPresent(renderer);
}
bool Game::running(){
return isRunning;}
bool Game::gameOver()
{
    if (abs(cat2->ypos - obs1 -> y) <= 20 && abs(cat2 -> xpos - obs1 -> x) <= 10 )
    {
        gameover = true;
    }
    if (abs(cat2->ypos - obs2 -> y) <= 20 && abs(cat2 -> xpos - obs2 -> x) <= 10)
    {
        gameover = true;
    }
    if (abs(cat2->ypos - obs3 -> y) <= 20 && abs(cat2 -> xpos - obs3 -> x) <= 10)
    {
        gameover = true;
    }
    if (abs(cat2->ypos - obs4 -> y) <= 20 && abs(cat2 -> xpos - obs4 -> x) <= 10)
    {
        gameover = true;
    }
    if (abs(cat2->ypos - obs5 -> y) <= 20 && abs(cat2 -> xpos - obs5 -> x) <= 10)
    {
        gameover = true;
    }
    if (abs(cat2->ypos - obs6 -> y) <= 20 && abs(cat2 -> xpos - obs6 -> x) <= 10)
    {
        gameover = true;
    }
    return gameover;
}
void Game::Pause()
{
    v1 = 0;
    v2 = 0;
    SDL_Surface* surf = IMG_Load("Image/button/pauseScreen.png");
    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_RenderCopy(renderer, text, NULL, &pR);
    resume -> Render();
    quit -> xpos = 430;
    quit -> ypos = 450;
    quit -> UpdateObj();
    quit -> Render();
    if (tmpx <= 600 && tmpx >= 400 && tmpy <= 350 && tmpy >= 250 )
    {
        resume = new GameObject ("Image/button/resume2.png", 430, 250, 100, 200, 1, 1, 476, 152);
        if (event.button.type == SDL_MOUSEBUTTONUP || event.button.type == SDL_MOUSEBUTTONDOWN )
        if (event.button.state == SDL_PRESSED && event.button.clicks == 1)
        {
            v1 = 25;
            v2 = 30;
            pause = false;
        }
    }
    else resume = new GameObject ("Image/button/resume1.png", 430, 250, 100, 200, 1, 1, 474, 154);



    if (tmpx <= 630 && tmpx >= 430 && tmpy <= 650 && tmpy >= 450 )
    {
        quit = new GameObject ("Image/button/quit2.png", 400, 500, 100, 200, 1, 1, 654, 211);
        if (event.button.type == SDL_MOUSEBUTTONUP || event.button.type == SDL_MOUSEBUTTONDOWN )
        if (event.button.state == SDL_PRESSED && event.button.clicks == 1)
        {
            SDL_Quit();
        }
    }
    else quit = new GameObject ("Image/button/quit1.png", 400, 500, 100, 200, 1, 1, 572, 185);

}
void Game::refresh()
{
   cat2 = new GameObject("Image/catmain.png", 900, 350, 70, 70, 1, 1, 94, 75);
    flower = new GameObject("Image/flower.png", 200, 300, 29, 29, 1, 1, 29, 29);
    flower1 = new GameObject("Image/flower.png", 700, 300, 29, 29, 1, 1, 29, 29);
    flower3 = new GameObject("Image/flower.png", 600, 300, 29, 29, 1, 1, 29, 29);
    flower4 = new GameObject("Image/flower.png", 500, 300, 29, 29, 1, 1, 29, 29);
    flower5 = new GameObject("Image/flower.png", 400, 300, 29, 29, 1, 1, 29, 29);
    flower2 = new GameObject("Image/flower.png", 300, 300, 29, 29, 1, 1, 29, 29);
    house = new GameObject("Image/house.png", 1, 10, 300, 600, 1, 1, 577, 167);
    tree = new GameObject ("Image/baum.png", 650, 100, 200, 200, 1, 1, 128, 128 );
    tree1 = new GameObject ("Image/baum.png", 550, 100, 200, 200, 1, 1, 128, 128 );
    tree2 = new GameObject ("Image/baum.png", 750, 100, 200, 200, 1, 1, 128, 128 );
    tree3 = new GameObject ("Image/baum.png", 850, 100, 200, 200, 1, 1, 128, 128 );

    map_ = new Map(lvl1);
    text = new LTexture("Hello World!", 100, 100, 100, 30);

    obs1 = new Obstacle();
    obs2 = new Obstacle();
    obs2 -> x -= 100;
    obs3 = new Obstacle();
    obs3 -> x-= 200;
    obs4 = new Obstacle();
    obs4 -> x -= 300;
    obs5 = new Obstacle();
    obs5 -> x -= 400;
    obs6 = new Obstacle();
    obs6 -> x -= 500;
}
void Game::printGameOver()
{
    SDL_RenderClear(renderer);
        gameover_ -> Render();
        refresh();
        if (event.button.type == SDL_MOUSEBUTTONDOWN || event.button.type == SDL_MOUSEBUTTONUP)
            if (event.button.clicks == 1 && event.button.state == SDL_PRESSED)
        {
            SDL_RenderClear(renderer);
            start = false;
            gameover = false;
        }
}
