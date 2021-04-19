#include "EndLevelScreen.h"

EndLevelScreen::EndLevelScreen(bool &isWin, Alphabet &alphabet)
{
    this->isWin = isWin;
    this->alphabet = alphabet;

    Button homeBtn(1, 610, 500);
    homeBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\menuBtn.png");
    homeBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\menuBtnHover.png");
    homeBtn.currentState = homeBtn.idleState;
    btns.push_back(homeBtn);
}

void EndLevelScreen::draw(Graphics &graphics)
{
    graphics.clear();
    if(isWin)
    {
            SDL_Color c;
            c.r = 0;
            c.g = 255;
            c.b = 0;
            c.a = 255;
            string msg = "YOU WIN!";
            alphabet.drawText(graphics.getRenderer(), msg, 625, 450, c);
    }
    else
    {
            SDL_Color c;
            c.r = 255;
            c.g = 0;
            c.b = 0;
            c.a = 255;
            string msg = "YOU LOSE!";
            alphabet.drawText(graphics.getRenderer(), msg, 625, 450, c);
    }

    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].draw(graphics.getRenderer());
    }
    graphics.flip();
}

void EndLevelScreen::update(Vector2 &mouse, SDL_Event &events, SCREENS &newScreen)
{
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].checkHover(mouse);
        if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            if(btns[i].checkClick())
            {
                if(btns[i].id == 1)
                    newScreen = start;
            }
        }
    }
}
