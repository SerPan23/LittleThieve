#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "LittleThieve.h"

class Wall
{
    public:
        short id;
        int x, y;
        int w, h;
        int r, g, b;
        void    drawWall(SDL_Renderer *renderer)
        {
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            line_vertical(renderer, x, y, y+h);
            line_horizontal(renderer, x, y, x+w);
        }
};

#endif // WALL_H_INCLUDED
