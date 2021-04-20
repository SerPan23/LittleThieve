#ifndef SELECTLEVELSCREEN_H_INCLUDED
#define SELECTLEVELSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "TextureFuncs.h"
#include "Button.h"
#include "Audio.h"

class SelectLevelScreen{
public:
    SelectLevelScreen(){}
    SelectLevelScreen(Audio &audio);

    Audio audio;
    vector<Button> btns;

    void draw(Graphics &graphics);
    void update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen, int &currentLevel);
};

#endif // SELECTLEVELSCREEN_H_INCLUDED
