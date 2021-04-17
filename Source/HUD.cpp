#include "HUD.h"

string int_to_str(int ch)
{
    string otv, tmp;
    while(ch)
    {
        tmp += ch%10 + 48;
        ch /= 10;
    }
    for(int i = 0; i < tmp.size(); i++)
        otv += tmp[tmp.size()-1-i];
    return otv;
}

void HUD::update(Alphabet alphabet, int playerScore, int t)
{
    score = playerScore;
    _alphabet = alphabet;
    time = t;
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

    string msgs = "Time:";
    msgs += int_to_str(time/1000);
    _alphabet.drawText(renderer, msgs, 1000, 10, c);
}
