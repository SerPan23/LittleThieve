#include "SelectLevelScreen.h"


SelectLevelScreen::SelectLevelScreen()
{
    Button backBtn(0, 25, 25);
    backBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\backBtn.png");
    backBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\backBtnHover.png");
    backBtn.currentState = backBtn.idleState;
    btns.push_back(backBtn);
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

void SelectLevelScreen::update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen)
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
            }
        }
    }
}
