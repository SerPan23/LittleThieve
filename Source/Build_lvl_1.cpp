#include "Wall.h"

void    Build_lvl_1(SDL_Renderer *renderer)
{
    Wall main_wall{1, 50, 50, 48, 48, 0, 0, 255};
    main_wall.drawWall(renderer);
}
