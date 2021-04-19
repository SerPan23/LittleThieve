#ifndef INFOSCREEN_H_INCLUDED
#define INFOSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "TextureFuncs.h"
#include "Button.h"

class InfoScreen{
public:
    InfoScreen();

    vector<Button> btns;

    void draw(Graphics &graphics);
    void update(Vector2 &mouse, SDL_Event &events, SCREENS &newScreen);
};

#endif // INFOSCREEN_H_INCLUDED
