#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED
#include "LittleThieve.h"
#include "SpriteData.h"
#include "TextureFuncs.h"

class Floor
{
    public:
        int x, y;
        int x1, y1;

    SpriteData spriteData;

    Floor(){}
    Floor(int x, int x1, int y, int y1)
    {
        this->x = x;
        this->y = y;
        this->x1 = x1;
        this->y1 = y1;
    }

    void    drawFloor(SDL_Renderer *renderer)
    {
        for(int i = this->y; i <= this->y1; i += this->spriteData.height){
                for(int j = this->x; j <= this->x1; j += this->spriteData.width)
                {
                    drawTexture(this->spriteData.texture, renderer, j, i);
                }
        }
    }
};


#endif // FLOOR_H_INCLUDED
