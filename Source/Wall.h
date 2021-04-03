#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "LittleThieve.h"

class Wall
{
    public:
        short id;
        int x, y;
        int w, h;
        int depth;
        int r, g, b;
        void    drawWall(SDL_Renderer *renderer)
        {
            filled_rect(renderer, x, y, w, h, r, g, b);
        }
};

#endif // WALL_H_INCLUDED
