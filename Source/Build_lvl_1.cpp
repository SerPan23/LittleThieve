#include "Wall.h"
#include "Item.h"
#include "Game.h"

void    Build_lvl_1(SDL_Renderer *renderer)
{
    Candy candy(625, 225, 24, 24, 255, 0, 255);
    candy.draw(renderer);
    Wall main_wall(1, 50, 50, 1394, 914, 48, 0, 0, 255, true);
    main_wall.drawWall(renderer);
    Wall wall_1(1, 767, 100, 32, 300, 32, 255, 255, 255);
    Wall wall_2(1, 479, 356, 300, 32, 32, 255, 255, 255);
    Wall wall_3(1, 100, 356, 150, 32, 32, 255, 255, 255);
    Wall wall_4(1, 767, 625, 32, 300, 32, 255, 255, 255);
    wall_1.drawWall(renderer);
    wall_2.drawWall(renderer);
    wall_3.drawWall(renderer);
    wall_4.drawWall(renderer);
}
