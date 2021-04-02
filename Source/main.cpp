#include "LittleThieve.h"
#include "Player.h"

int main(int argc, char* argv[])
{

    //vector <vector<int> > gamefield(1400, vector<int>(900));
    int x = 1382, y = 525;
    Player player;
    player.x = x;
    player.y = y;

    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(1500, 1000, 0, &window, &renderer);

    bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                quit = true;

            if(event.type == SDL_KEYDOWN)
                player.movePlayer(event);
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        //filled_rect(renderer, x, y, 100, 100);
        Build_lvl_1(renderer);
        player.drawPlayer(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
