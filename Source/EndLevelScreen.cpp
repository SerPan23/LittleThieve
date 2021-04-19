#include "EndLevelScreen.h"

EndLevelScreen::EndLevelScreen(bool &isWin, Alphabet &alphabet)
{
    this->isWin = isWin;
    this->alphabet = alphabet;

    Button homeBtn(1, 625, 500);
    homeBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\menuBtn.png");
    homeBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\menuBtnHover.png");
    homeBtn.currentState = homeBtn.idleState;
    btns.push_back(homeBtn);
    Button homeBtn2(1, 625, 650);
    homeBtn2.idleState = loadTexture("..\\..\\Source\\Sprites\\menuBtn.png");
    homeBtn2.hoverState = loadTexture("..\\..\\Source\\Sprites\\menuBtnHover.png");
    homeBtn2.currentState = homeBtn2.idleState;
    btns.push_back(homeBtn2);

    Button nextLevelBtn(2, 625, 500);
    nextLevelBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\nextBtn.png");
    nextLevelBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\nextBtnHover.png");
    nextLevelBtn.currentState = nextLevelBtn.idleState;
    btns.push_back(nextLevelBtn);

    Button retryBtn(3, 625, 500);
    retryBtn.idleState = loadTexture("..\\..\\Source\\Sprites\\retryBtn.png");
    retryBtn.hoverState = loadTexture("..\\..\\Source\\Sprites\\retryBtnHover.png");
    retryBtn.currentState = retryBtn.idleState;
    btns.push_back(retryBtn);
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
            alphabet.drawText(graphics.getRenderer(), msg, 665, 450, c);
    }
    else
    {
            SDL_Color c;
            c.r = 255;
            c.g = 0;
            c.b = 0;
            c.a = 255;
            string msg = "YOU LOSE!";
            alphabet.drawText(graphics.getRenderer(), msg, 645, 450, c);
    }
    for(int i = 0; i < btns.size(); i++)
    {
        if(btns[i].needDraw)
            btns[i].draw(graphics.getRenderer());
    }
    graphics.flip();
}

void EndLevelScreen::update(Mouse &mouse, SDL_Event &events, SCREENS &newScreen, int &currentLevel, int &numberOfLevel)
{
    if(currentLevel == numberOfLevel && isWin)
    {
        btns[0].needDraw = true;
        btns[1].needDraw = false;
        btns[2].needDraw = false;
        btns[3].needDraw = false;
    }
    else if(!isWin)
    {
        btns[0].needDraw = false;
        btns[1].needDraw = true;
        btns[2].needDraw = false;
        btns[3].needDraw = true;
    }
    else
    {
        btns[0].needDraw = false;
        btns[1].needDraw = true;
        btns[2].needDraw = true;
        btns[3].needDraw = false;
    }
    for(int i = 0; i < btns.size(); i++)
    {
        btns[i].checkHover(mouse.pos);
        if(mouse.leftBtnPressed)
        {
            if(btns[i].checkClick() && btns[i].needDraw)
            {
                if(btns[i].id == 1)
                {
                    mouse.leftBtnPressed = false;
                    newScreen = start;
                }
                else if(btns[i].id == 2)
                {
                    mouse.leftBtnPressed = false;
                    currentLevel += 1;
                    newScreen = play;
                }
                else if(btns[i].id == 3)
                {
                    mouse.leftBtnPressed = false;
                    newScreen = play;
                }
            }
        }
    }
}
