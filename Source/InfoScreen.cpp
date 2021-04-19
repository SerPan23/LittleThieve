#include "InfoScreen.h"

InfoScreen::InfoScreen()
{

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
