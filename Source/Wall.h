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
        bool type = false;

        Wall(short id, int x, int y, int w, int h, int depth, int r, int g, int b, bool type)
        {
            this->id = id;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            this->depth = depth;
            this->r = r;
            this->g = g;
            this->b = b;
            this->type = type;
        }
        Wall(short id, int x, int y, int w, int h, int depth, int r, int g, int b)
        {
            this->id = id;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            this->depth = depth;
            this->r = r;
            this->g = g;
            this->b = b;
        }
        void    drawWall(SDL_Renderer *renderer)
        {
            if(type)
            {
                for(int i = 0; i < w / depth; i++){
                    filled_rect(renderer, i*depth + x, y, depth, depth, r, g, b);
                    filled_rect(renderer, i*depth + x, h, depth, depth, r, g, b);
                }
                for(int i = 0; i < h / depth; i++)
                {
                    filled_rect(renderer, x, i*depth + y, depth, depth, r, g, b);
                    filled_rect(renderer, w, i*depth + y, depth, depth, r, g, b);
                }
            }
            else
            {
                if(depth == w)
                    for(int i = 0; i < h / depth; i++)
                        filled_rect(renderer, x, i*depth + y, depth, depth, r, g, b);
                else
                    for(int i = 0; i < w / depth; i++)
                        filled_rect(renderer, i*depth + x, y, depth, depth, r, g, b);
            }
        }
};

#endif // WALL_H_INCLUDED
