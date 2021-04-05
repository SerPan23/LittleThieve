#ifndef TEXTUREFUNCS_H_INCLUDED
#define TEXTUREFUNCS_H_INCLUDED
#include "LittleThieve.h"
#include "SpriteData.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y);

//vector <vector<SDL_Color> > loadTexture(char* path); //..\\..\\Source\\Sprites\\image.bmp
SpriteData loadTexture(char* path);

void drawTexture(vector <vector<SDL_Color> > texture, SDL_Renderer *renderer, int x, int y);

#endif // TEXTUREFUNCS_H_INCLUDED
