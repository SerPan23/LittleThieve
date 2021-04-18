#ifndef STARTSCREEN_H_INCLUDED
#define STARTSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "TextureFuncs.h"
#include "Button.h"

class StartScreen{
public:
    StartScreen();

    vector<Button> btns;

    void draw(Graphics &graphics);
    void update(Vector2 &mouse, SDL_Event &events, SCREENS &newScreen);
};

#endif // STARTSCREEN_H_INCLUDED
