#ifndef OBJECTDATA_H_INCLUDED
#define OBJECTDATA_H_INCLUDED

#include "LittleThieve.h"

struct ObjectData{
    short id;
    vector <vector<SDL_Color> > texture;
    int height;
    int width;
    float x, y;
};


#endif // OBJECTDATA_H_INCLUDED
