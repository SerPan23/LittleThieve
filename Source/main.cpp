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

void doKeyDown(SDL_Event event, int &x, int &y)
{
    int speed = 3;
    if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
    {
        y -= speed;
    }

    if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
    {
        y += speed;
    }

    if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
    {
        x -= speed;
    }

    if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
    {
        x += speed;
    }
}

int main(int argc, char* argv[])
{

    vector <vector<int> > gamefield(1500, vector<int>(1000));


    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(1500, 1000, 0, &window, &renderer);


    int x = 1382, y = 525;

    bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                quit = true;

            if(event.type == SDL_KEYDOWN)
                doKeyDown(event, x, y);
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        filled_rect(renderer, x, y, 100, 100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
