#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "LittleThieve.h"
#include "SpriteData.h"
#include "TextureFuncs.h"

/*Types:
0 - Candy
*/

class Item{
public:
    int x;
    int y;
    int w;
    int h;
    int type;
    //int r, g, b;
    SpriteData spriteData;
    Item(){}
    Item(int x, int y, int w, int h, int type)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->type = type;
    }


    void event()
    {

    }

    void draw(SDL_Renderer *renderer){
         drawTexture(this->spriteData.texture, renderer, (int)this->x, (int)this->y);
    }

};

/*
class Candy:public Item{
public:

    Candy(int x, int y, int w, int h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
    void event() override {
        cout << "Candy";
    }
};*/


#endif // ITEM_H_INCLUDED
