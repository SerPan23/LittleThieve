#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include "LittleThieve.h"
#include "Alphabet.h"

class HUD{
public:
    int score;

    Alphabet _alphabet;

    void update(int playerScore, Alphabet alphabet);
    void draw(SDL_Renderer *renderer);
};

#endif // HUD_H_INCLUDED
