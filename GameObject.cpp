#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* textureSheet, int x, int y, int height_, int width_, int srcx, int srcy, int srcw, int srch)
{
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
    height = height_;
    width = width_;
    srcRect.x = srcx;
    srcRect.y = srcy;
    srcRect.w = srcw;
    srcRect.h = srch;
}
void GameObject::UpdateObj()
{

    destRect.h = height;
    destRect.w = width;
    destRect.x = xpos;
    destRect.y = ypos;
    if (xpos > 1000)
    {
        xpos = -500;
    }

}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
void GameObject::Free ()
{
    srcRect.x = 0;
    srcRect.y = 0;
}
