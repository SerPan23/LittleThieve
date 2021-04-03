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
    void event() override {
        cout << "Candy";
    }
};


#endif // ITEM_H_INCLUDED
