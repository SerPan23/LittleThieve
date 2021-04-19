#include "InfoScreen.h"

InfoScreen::InfoScreen()
{
    Button backBtn(1, 25, 25);
    backBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\backBtn.png");
    backBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\backBtnHover.png");
    backBtn.currentState = backBtn.idleState;
    btns.push_back(backBtn);
}

void InfoScreen::draw(Graphics &graphics)
{
    graphics.clear();
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].draw(graphics.getRenderer());
    }
    graphics.flip();
}

void InfoScreen::update(Vector2 &mouse, SDL_Event &events, SCREENS &newScreen)
{
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].checkHover(mouse);
        if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            if(btns[i].checkClick())
            {
                if(btns[i].id == 1) // btn to menu
                    newScreen = start;
            }
        }
    }
}
