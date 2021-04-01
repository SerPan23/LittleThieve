#include "LittleThieve.h"

void line_vertical(SDL_Renderer *renderer, int x, int y, int y2)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for (int i = y; i <= y2; ++i)
        SDL_RenderDrawPoint(renderer, x, i);
}

void line_horizontal(SDL_Renderer *renderer, int x, int y, int x2)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for (int i = x; i <= x2; ++i)
        SDL_RenderDrawPoint(renderer, i, y);
}

void filled_rect(SDL_Renderer *renderer, int x, int y, int width, int height)
{
    for(int i = 0; i <= height; i++)
    line_horizontal(renderer, x, y+i, x+width);
}
