#ifndef STARTSCREEN_H_INCLUDED
#define STARTSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "TextureFuncs.h"
#include "Button.h"
#include "Audio.h"

class StartScreen{
public:
    StartScreen(){}
    StartScreen(Audio &audio);

    Audio audio;
    vector<Button> btns;

    void draw(Graphics &graphics);
    void update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen);
};

#endif // STARTSCREEN_H_INCLUDED
