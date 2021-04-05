#ifndef TEXTUREFUNCS_H_INCLUDED
#define TEXTUREFUNCS_H_INCLUDED
#include "LittleThieve.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y);

vector <vector<SDL_Color> > loadTexture(char* path[]); //..\\..\\Source\\Sprites\\image.bmp

void drawTexture(vector <vector<SDL_Color> > texture, SDL_Renderer *renderer);

#endif // TEXTUREFUNCS_H_INCLUDED
