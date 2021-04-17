#ifndef ALPHABET_H_INCLUDED
#define ALPHABET_H_INCLUDED

#include "LittleThieve.h"

class Letter{
public:
    vector <vector<SDL_Color> > texture;
};

class Alphabet{
public:
    vector<Letter> alphabet;

    void loadAlphabet(char* path);
    void drawLetter(SDL_Renderer *renderer, char letter, int x, int y, SDL_Color Color);
    void drawText(SDL_Renderer *renderer, string text, int x, int y, SDL_Color Color);
};

#endif // ALPHABET_H_INCLUDED
