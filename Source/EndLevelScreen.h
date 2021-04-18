#ifndef ENDLEVELSCREEN_H_INCLUDED
#define ENDLEVELSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Alphabet.h"
#include "Button.h"
#include "Graphics.h"

class EndLevelScreen{
public:
    EndLevelScreen(){}
    EndLevelScreen(bool &isWin, Alphabet &alphabet);

    vector<Button> btns;
    bool isWin;
    Alphabet alphabet;

    void draw(Graphics &graphics);
    void update(Vector2 &mouse, SDL_Event &events, SCREENS &newScreen);
};

#endif // ENDLEVELSCREEN_H_INCLUDED
