#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

#include "LittleThieve.h"
#include "Alphabet.h"
#include "SpriteData.h"
#include "TextureFuncs.h"

class HUD{
public:
    HUD();
    int score, maxScore;
    int time, prevtime;
    float timeLine = 170.0;
    float delgap;
    bool firstUpd = false;

    SpriteData scorebg;
    SpriteData timebg;

    SpriteData candy;
    SpriteData candy_deactive;

    Alphabet _alphabet;

    void update(Alphabet alphabet, int playerScore, int maxScore, int t);
    void draw(SDL_Renderer *renderer);
    void drawTime(SDL_Renderer *renderer);
    void drawScore(SDL_Renderer *renderer);
};

#endif // HUD_H_INCLUDED
