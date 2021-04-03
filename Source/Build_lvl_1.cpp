#include "Wall.h"
#include "Item.h"

void    Build_lvl_1(SDL_Renderer *renderer)
{
    Candy candy;
    candy.x = 300;
    candy.y = 300;
    candy.width = 24;
    candy.height = 24;
    candy.r = 255;
    candy.g = 0;
    candy.b = 255;
    candy.draw(renderer);
    Wall main_wall{1, 50, 50, 48, 48, 255, 0, 0};
    main_wall.drawWall(renderer);
}
