#include "InfoScreen.h"

InfoScreen::InfoScreen(Audio &audio)
{
    this->audio = audio;

    Button backBtn(1, 25, 25);
    backBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\backBtn.png");
    backBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\backBtnHover.png");
    backBtn.currentState = backBtn.idleState;
    btns.push_back(backBtn);
}

void InfoScreen::draw(Graphics &graphics)
{
    graphics.clear(21, 21, 21);
    SpriteData winText = loadTexture("..\\..\\Source\\Sprites\\info.png");
    drawTexture(winText.texture, graphics.getRenderer(), 0, 0);
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].draw(graphics.getRenderer());
    }
    graphics.flip();
}

void InfoScreen::update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen)
{
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].checkHover(mouse.pos);
        if(mouse.leftBtnPressed)
        {
            if(btns[i].checkClick())
            {
                audio.playEffect(audio.click);
                if(btns[i].id == 1) // btn to menu
                {
                    mouse.leftBtnPressed = false;
                    newScreen = start;
                }
            }
        }
    }
}
