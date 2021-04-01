#include "LittleThieve.h"

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
