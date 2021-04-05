#include "Game.h"
#include "TextureFuncs.h"
int main(int argc, char* argv[])
{
    Game game;

    //SDL_Surface *image = SDL_LoadBMP("C:\\image.bmp");
    //SDL_Surface *image = SDL_LoadBMP("..\\..\\Source\\Sprites\\image.bmp");
    //cout << SDL_GetError();
    //cout << image->pixels;

    /*SDL_Color rgb;
    Uint32 data = getpixel(image, 20, 20);
    SDL_GetRGBA(data, image->format, &rgb.r, &rgb.g, &rgb.b, &rgb.a);*/

    /*vector <vector<SDL_Color> > texture(image->h, vector<SDL_Color>(image->w));

    for(int i = 0; i < image->h; i++)
    {
        for(int j = 0; j < image->w; j++)
        {
            SDL_Color pixelColor;
            Uint32 data = getpixel(image, i, j);
            SDL_GetRGBA(data, image->format, &pixelColor.r, &pixelColor.g, &pixelColor.b, &pixelColor.a);
            texture[i][j] = pixelColor;
        }
    }*/


    vector <vector<SDL_Color> > texture = loadTexture();

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

        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        drawTexture(texture, renderer);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
