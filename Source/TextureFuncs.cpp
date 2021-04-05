#include "TextureFuncs.h"

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp)
    {
        case 1:
            return *p;
            break;
        case 2:
            return *(Uint16 *)p;
            break;
        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
                break;
        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
    }
}


vector <vector<SDL_Color> > loadTexture(char* path[])
{
    SDL_Surface *image = SDL_LoadBMP("..\\..\\Source\\Sprites\\image.bmp");
    vector <vector<SDL_Color> > texture(image->h, vector<SDL_Color>(image->w));

    for(int i = 0; i < image->h; i++)
    {
        for(int j = 0; j < image->w; j++)
        {
            SDL_Color pixelColor;
            Uint32 data = getpixel(image, i, j);
            SDL_GetRGBA(data, image->format, &pixelColor.r, &pixelColor.g, &pixelColor.b, &pixelColor.a);
            texture[i][j] = pixelColor;
        }
    }
    return texture;
}

void drawTexture(vector <vector<SDL_Color> > texture, SDL_Renderer *renderer)
{
    for(int i = 0; i < texture.size(); i++)
        {
            for(int j = 0; j < texture[i].size(); j++)
            {
                SDL_Color pixelColor = texture[i][j];
                SDL_SetRenderDrawColor(renderer, (int)pixelColor.r, (int)pixelColor.g, (int)pixelColor.b, 255);
                SDL_RenderDrawPoint(renderer, i, j);
            }
        }
}
