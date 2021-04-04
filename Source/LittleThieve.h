#ifndef LITTLETHIEVE_H_INCLUDED
#define LITTLETHIEVE_H_INCLUDED

#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;

//draw funcs
void    line_vertical(SDL_Renderer *renderer, int x, int y, int y2, int r, int g, int b);
void    line_horizontal(SDL_Renderer *renderer, int x, int y, int x2, int r, int g, int b);
void    filled_rect(SDL_Renderer *renderer, int x, int y, int width, int height, int r, int g, int b);
void    Build_lvl_1(SDL_Renderer *renderer);


#endif // LITTLETHIEVE_H_INCLUDED
