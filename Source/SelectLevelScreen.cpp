#include "SelectLevelScreen.h"


SelectLevelScreen::SelectLevelScreen()
{
    Button backBtn(0, 25, 25);
    backBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\backBtn.png");
    backBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\backBtnHover.png");
    backBtn.currentState = backBtn.idleState;
    btns.push_back(backBtn);

    Button level1Btn(1, 200, 200);
    level1Btn.idleState = loadTexture("..\\..\\Source\\Sprites\\level1Btn.png");
    level1Btn.hoverState = loadTexture("..\\..\\Source\\Sprites\\level1BtnHover.png");
    level1Btn.currentState = level1Btn.idleState;
    btns.push_back(level1Btn);
    Button level2Btn(2, 280, 200);
    level2Btn.idleState = loadTexture("..\\..\\Source\\Sprites\\level2Btn.png");
    level2Btn.hoverState = loadTexture("..\\..\\Source\\Sprites\\level2BtnHover.png");
    level2Btn.currentState = level2Btn.idleState;
    btns.push_back(level2Btn);
}

void SelectLevelScreen::draw(Graphics &graphics)
{
    graphics.clear();
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].draw(graphics.getRenderer());
    }
    graphics.flip();
}

void SelectLevelScreen::update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen, int &currentLevel)
{
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].checkHover(mouse.pos);
        if(mouse.leftBtnPressed)
        {
            if(btns[i].checkClick())
            {
                if(btns[i].id == 0) // btn to menu
                {
                    mouse.leftBtnPressed = false;
                    newScreen = start;
                }
                else if(btns[i].id == 1) // btn to menu
                {
                    mouse.leftBtnPressed = false;
                    currentLevel = 1;
                    newScreen = play;
                }
                else if(btns[i].id == 2) // btn to menu
                {
                    mouse.leftBtnPressed = false;
                    currentLevel = 2;
                    newScreen = play;
                }
            }
        }
    }
}
