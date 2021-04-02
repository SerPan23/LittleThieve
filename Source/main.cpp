#include "LittleThieve.h"
#include "Player.h"
#include "Item.h"

int main(int argc, char* argv[])
{

    //vector <vector<int> > gamefield(1400, vector<int>(900));
    int x = 1382, y = 525;
    Player player;
    player.x = x;
    player.y = y;

    Candy candy;
    candy.x = 300;
    candy.y = 300;
    candy.height = 24;
    candy.width = 24;


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
        candy.draw(renderer);
        player.drawPlayer(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
