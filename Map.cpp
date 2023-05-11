#include "Map.h"
#include "TextureManager.h"
#include <SDL_mixer.h>

Map::Map (int arr[20][25])
{
    ground = TextureManager::LoadTexture("Image/ground.png");
    grass = TextureManager::LoadTexture("Image/grass.png");
    pathwgrass = TextureManager::LoadTexture("Image/pathwgrass.png");
    water = TextureManager::LoadTexture("Image/water.png");
    sky = TextureManager::LoadTexture("Image/sky.png");

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            map_[i][j] = arr[i][j];
        }
    }

    src.x = src.y = 0;
    src.w = src.h = 64;

    dest.x = 1;
    dest.y = 1;
    dest.h = 64;
    dest.w = 64;
}

void Map::DrawMap()
{
    int type = 0;
     for (int row = 0; row < 20; row ++)
    {
        //dest.x = col*64;
        for (int col = 0; col < 25; col++)
        {
          type = map_[row][col];
          dest.x = col*64;
          dest.y = row*64;
          switch (type)
          {
          case 0:
            TextureManager::Draw(grass, src, dest);
            break;
          case 1:
            TextureManager::Draw(ground, src, dest);
            break;
          case 2:
            TextureManager::Draw(pathwgrass, src, dest);
            break;
          case 3:
            TextureManager::Draw(water, src, dest);
            break;
          case 4:
            TextureManager::Draw(sky, src, dest);
          default:
            break;
          }
        }
    }
}
void Map::Update()
{

}
