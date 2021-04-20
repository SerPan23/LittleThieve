#ifndef ENDLEVELSCREEN_H_INCLUDED
#define ENDLEVELSCREEN_H_INCLUDED

#include "LittleThieve.h"
#include "Alphabet.h"
#include "Button.h"
#include "Graphics.h"
#include "Audio.h"

class EndLevelScreen{
public:
    EndLevelScreen(){}
    EndLevelScreen(bool &isWin, Alphabet &alphabet, Audio &audio);

    vector<Button> btns;
    bool isWin;
    Alphabet alphabet;
    Audio audio;

    void draw(Graphics &graphics);
    void update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen, int &currentLevel, int &numberOfLevel);
};

#endif // ENDLEVELSCREEN_H_INCLUDED
