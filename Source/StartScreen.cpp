#include "StartScreen.h"

StartScreen::StartScreen()
{
    Button playBtn(1, 625, 450);
    playBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\playBtn.png");
    playBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\playBtnHover.png");
    playBtn.currentState = playBtn.idleState;
    btns.push_back(playBtn);
    Button selectLevelBtn(2, 625, 600);
    selectLevelBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\selectLevelBtn.png");
    selectLevelBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\selectLevelBtnHover.png");
    selectLevelBtn.currentState = selectLevelBtn.idleState;
    btns.push_back(selectLevelBtn);
    Button infoBtn(3, 1420, 920);
    infoBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\infoBtn.png");
    infoBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\infoBtnHover.png");
    infoBtn.currentState = infoBtn.idleState;
    btns.push_back(infoBtn);
}

void StartScreen::draw(Graphics &graphics)
{
    graphics.clear();
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].draw(graphics.getRenderer());
    }
    graphics.flip();
}

void StartScreen::update(Vector2 &mouse, SDL_Event &events, SCREENS &newScreen)
{
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].checkHover(mouse);
        if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            if(btns[i].checkClick())
            {
                if(btns[i].id == 1)
                    newScreen = play;
                else if(btns[i].id == 2)
                    newScreen = selectLevel;
                else if(btns[i].id == 3)
                    newScreen = info;
            }
        }
    }
}
