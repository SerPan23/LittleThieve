#include "StartScreen.h"

StartScreen::StartScreen(Audio &audio)
{
    this->audio = audio;

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
    graphics.clear(21, 21, 21);
    SpriteData logo = loadTexture("..\\..\\Source\\Sprites\\logo.png");
    drawTexture(logo.texture, graphics.getRenderer(), 475, 250);
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].draw(graphics.getRenderer());
    }
    graphics.flip();
}

void StartScreen::update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen)
{
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].checkHover(mouse.pos);
        if(mouse.leftBtnPressed)
        {
            if(btns[i].checkClick())
            {
                audio.playEffect(audio.click);
                if(btns[i].id == 1)
                {
                    mouse.leftBtnPressed = false;
                    newScreen = play;
                }
                else if(btns[i].id == 2)
                {
                    mouse.leftBtnPressed = false;
                    newScreen = selectLevel;
                }
                else if(btns[i].id == 3)
                {
                    mouse.leftBtnPressed = false;
                    newScreen = info;
                }
            }
        }
    }
}
