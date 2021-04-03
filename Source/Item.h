#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "LittleThieve.h"

class Item{
public:
    int x;
    int y;
    int width;
    int height;
    int r, g, b;


    virtual void event() = 0;

    void draw(SDL_Renderer *renderer){
         filled_rect(renderer,  this->x,  this->y, this->width, this->height, this->r, this->g, this->b);
    }

};


class Candy:public Item{
public:

    Candy(int x, int y, int w, int h, int r, int g, int b)
    {
        this->x = x;
        this->y = y;
        this->width = w;
        this->height = h;
        this->r = r;
        this->g = g;
        this->b = b;
    }
    void event() override {
        cout << "Candy";
    }
};


#endif // ITEM_H_INCLUDED
