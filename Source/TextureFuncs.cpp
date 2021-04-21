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

SpriteData loadTexture(char* path)
{
    //SDL_Surface *image = SDL_LoadBMP(path);//"..\\..\\Source\\Sprites\\image.bmp"
    SDL_Surface *image = IMG_Load(path);
    vector <vector<SDL_Color> > texture(image->w, vector<SDL_Color>(image->h));
    for(int i = 0; i < image->w; i++)
    {
        for(int j = 0; j < image->h; j++)
        {
            SDL_Color pixelColor;
            Uint32 data = getpixel(image, i, j);
            SDL_GetRGBA(data, image->format, &pixelColor.r, &pixelColor.g, &pixelColor.b, &pixelColor.a);
            texture[i][j] = pixelColor;
        }
    }
    SpriteData data;
    data.height = image->h;
    data.width = image->w;
    data.texture = texture;
    return data;
}


void drawTexture(vector <vector<SDL_Color> > texture, SDL_Renderer *renderer, int x, int y)
{
    for(int i = 0; i < texture.size(); i++)
    {
        for(int j = 0; j < texture[i].size(); j++)
        {
            SDL_Color pixelColor = texture[i][j];
            if((int)pixelColor.a > 0)
            {
                SDL_SetRenderDrawColor(renderer, (int)pixelColor.r, (int)pixelColor.g, (int)pixelColor.b, (int)pixelColor.a);
                SDL_RenderDrawPoint(renderer, i+x, j+y);
            }
        }
    }
}
