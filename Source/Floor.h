#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED
#include "LittleThieve.h"
#include "SpriteData.h"
#include "TextureFuncs.h"

class Floor
{
    public:
        int x, y;
        int w, h;

    SpriteData spriteData;

    Floor(){}
    Floor(int x, int y, int w, int h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    void    drawFloor(SDL_Renderer *renderer)
    {
        if(this->spriteData.width == w && this->spriteData.height == h)
        {
            drawTexture(this->spriteData.texture, renderer, this->x, this->y);
        }
        else
            for(int i = this->y; i <= this->h+y; i += this->spriteData.height){
                    for(int j = this->x; j <= this->w+x; j += this->spriteData.width)
                    {
                        drawTexture(this->spriteData.texture, renderer, j, i);
                    }
            }
    }
};


#endif // FLOOR_H_INCLUDED
