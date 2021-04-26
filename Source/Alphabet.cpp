#include "Alphabet.h"
#include "TextureFuncs.h"


void Alphabet::loadAlphabet(char* path)
{
    SDL_Surface *image = IMG_Load(path);
    alphabet.clear();
    for(int k = 1; k <= image->w; k+=24)
    {
        vector <vector<SDL_Color> > texture(24, vector<SDL_Color>(24));
        for(int i = 0; i < 24; i++)
        {
            for(int j = 0; j < 24; j++)
            {
                SDL_Color pixelColor;
                Uint32 data = getpixel(image, i+k, j);
                SDL_GetRGBA(data, image->format, &pixelColor.r, &pixelColor.g, &pixelColor.b, &pixelColor.a);
                texture[i][j] = pixelColor;
            }
        }
        Letter letter;
        letter.texture = texture;
        alphabet.push_back(letter);
    }
}

void Alphabet::drawLetter(SDL_Renderer *renderer, char letter, int x, int y, SDL_Color Color)
{
    for(int i = 0; i < alphabet[(int)letter - 32].texture.size(); i++)
    {
        for(int j = 0; j < alphabet[(int)letter - 32].texture[i].size(); j++)
        {
            SDL_Color pixelColor = alphabet[(int)letter - 32].texture[i][j];
            if((int)pixelColor.a > 0 && (int)pixelColor.r == 0 && (int)pixelColor.g == 0 && (int)pixelColor.b == 0)
            {
                SDL_SetRenderDrawColor(renderer, (int)Color.r, (int)Color.g, (int)Color.b, (int)Color.a);
                SDL_RenderDrawPoint(renderer, i+x, j+y);
            }
        }
    }
}

void Alphabet::drawText(SDL_Renderer *renderer, string text, int x, int y, SDL_Color Color)
{
    for(int i = 0; i < text.size(); i++)
    {
        drawLetter(renderer, text[i], x+(i*16), y, Color);
    }
}
