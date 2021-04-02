#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "LittleThieve.h"

class Item{
public:
    int x;
    int y;
    int width;
    int height;


    virtual void event() = 0;

    void draw(SDL_Renderer *renderer){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        filled_rect(renderer, x, y, width, height);
    }

};


class Candy:public Item{
public:
    void event() override {
        cout << "Candy";
    }
};


#endif // ITEM_H_INCLUDED
