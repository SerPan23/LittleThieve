#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "LittleThieve.h"
#include "Wall.h"
#include "Item.h"

class Game{
public:
    vector <Wall> walls;
    vector <Item *> items;
};



#endif // GAME_H_INCLUDED