#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "LittleThieve.h"
#include "TextureFuncs.h"
#include "SpriteData.h"

class Wall
{
    public:
        short id;
        int x, y;
        int w, h;
        int depth;
        //vector <vector<SDL_Color> > texture;

        SpriteData spriteData;

        Wall(short id, int x, int y, int w, int h, int depth)
        {
            this->id = id;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            this->depth = depth;
        }
        void    drawWall(SDL_Renderer *renderer)
        {
            if(this->spriteData.width == w && this->spriteData.height == h)
            {
                drawTexture(this->spriteData.texture, renderer, this->x, this->y);
            }
            else
            {
                if(depth == w)
                    for(int i = 0; i < h / depth; i++)
                        //filled_rect(renderer, x, i*depth + y, depth, depth, r, g, b);
                        drawTexture(this->spriteData.texture, renderer, this->x, i*depth + this->y);
                else
                    for(int i = 0; i < w / depth; i++)
                        //filled_rect(renderer, i*depth + x, y, depth, depth, r, g, b);
                        drawTexture(this->spriteData.texture, renderer, i*depth + this->x, this->y);
            }
        }
};

#endif // WALL_H_INCLUDED
