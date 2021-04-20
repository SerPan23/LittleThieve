#ifndef INFOSCREEN_H_INCLUDED
#define INFOSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "TextureFuncs.h"
#include "Button.h"
#include "Audio.h"

class InfoScreen{
public:
    InfoScreen(){}
    InfoScreen(Audio &audio);

    Audio audio;
    vector<Button> btns;

    void draw(Graphics &graphics);
    void update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen);
};

#endif // INFOSCREEN_H_INCLUDED
