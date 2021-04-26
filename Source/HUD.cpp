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

HUD::HUD()
{
    this->scorebg = loadTexture("..\\..\\Source\\Sprites\\scorebg.png");
    this->timebg = loadTexture("..\\..\\Source\\Sprites\\timeHUD.png");
    this->candy = loadTexture("..\\..\\Source\\Sprites\\candyRed2_HUD.png");
    this->candy_deactive = loadTexture("..\\..\\Source\\Sprites\\candyRed2_HUD_deactive.png");
}

void HUD::update(Alphabet alphabet, int playerScore, int maxScore, int t)
{
    this->score = playerScore;
    this->maxScore = maxScore;
    this->_alphabet = alphabet;
    this->time = t;
    if(!firstUpd)
    {
        firstUpd = 1;
        this->delgap = timeLine/t;
        this->prevtime = t;
    }
    if(prevtime > time && timeLine > 0)
        timeLine -= delgap;
    prevtime = t;
}

void HUD::draw(SDL_Renderer *renderer)
{
    drawScore(renderer);
    drawTime(renderer);
}

void HUD::drawTime(SDL_Renderer *renderer)
{
    SDL_Color c;
    c.r = 66;
    c.g = 66;
    c.b = 66;
    c.a = 255;
    drawTexture(this->timebg.texture, renderer, 1140, 0);
    if(timeLine > 120)
        filled_rect(renderer, 1244, 5, timeLine, 24, 0, 183, 74, 255);
    else if(timeLine > 56 )
        filled_rect(renderer, 1244, 5, timeLine, 24, 255, 169, 0, 255);
    else
        filled_rect(renderer, 1244, 5, timeLine, 24, 249, 49, 84, 255);
    filled_rect(renderer, 1244, 5, 170, 2, 66, 66, 66, 255);
    filled_rect(renderer, 1414, 5, 2, 26, 66, 66, 66, 255);
    filled_rect(renderer, 1244, 29, 170, 2, 66, 66, 66, 255);
    filled_rect(renderer, 1244, 5, 2, 26, 66, 66, 66, 255);
    string msgs = "";
    if(time >= 1)
        msgs += int_to_str(time);
    else
        msgs = "0";
    _alphabet.drawText(renderer, msgs, 1314, 6, c);
}

void HUD::drawScore(SDL_Renderer *renderer)
{
    drawTexture(this->scorebg.texture, renderer, 50, 0);

    for(int i = 1; i <= maxScore; i++)
    {
        if(score >= i)
            drawTexture(this->candy.texture, renderer, 75 + (i-1)*(44), 5);
        else
            drawTexture(this->candy_deactive.texture, renderer, 75 + (i-1)*(44), 5);
    }
}
