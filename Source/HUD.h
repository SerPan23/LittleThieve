#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include "LittleThieve.h"
#include "Alphabet.h"

class HUD{
public:
    int score;
    int time;

    Alphabet _alphabet;

    void update(Alphabet alphabet, int playerScore, int t);
    void draw(SDL_Renderer *renderer);
};

#endif // HUD_H_INCLUDED
