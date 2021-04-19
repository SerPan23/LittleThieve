#ifndef SELECTLEVELSCREEN_H_INCLUDED
#define SELECTLEVELSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "TextureFuncs.h"
#include "Button.h"

class SelectLevelScreen{
public:
    SelectLevelScreen();

    vector<Button> btns;

    void draw(Graphics &graphics);
    void update(Vector2 &mouse, SDL_Event &events, SCREENS &newScreen);
};

#endif // SELECTLEVELSCREEN_H_INCLUDED
