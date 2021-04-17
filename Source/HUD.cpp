#include "HUD.h"

void HUD::update(int playerScore, Alphabet alphabet)
{
    score = playerScore;
    _alphabet = alphabet;
}


void HUD::draw(SDL_Renderer *renderer)
{
    SDL_Color c;
    c.r = 255;
    c.g = 255;
    c.b = 0;
    c.a = 255;
    string msg = "Score:";
    msg += char(score+48);
    _alphabet.drawText(renderer, msg, 10, 10, c);
}
