#ifndef LITTLETHIEVE_H_INCLUDED
#define LITTLETHIEVE_H_INCLUDED

#include <SDL.h>
#include <iostream>
#include <vector>

#include <SDL_image.h>
#include <SDL_mixer.h>

#include "it_math.h"

using namespace std;

enum SCREENS {start, exitGame, info, play, selectLevel, levelend};

//draw funcs
void line_vertical(SDL_Renderer *renderer, int x, int y, int y2, int r, int g, int b, int a);
void line_horizontal(SDL_Renderer *renderer, int x, int y, int x2, int r, int g, int b, int a);
void filled_rect(SDL_Renderer *renderer, int x, int y, int width, int height, int r, int g, int b, int a);

#endif // LITTLETHIEVE_H_INCLUDED
