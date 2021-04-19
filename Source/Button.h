#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "LittleThieve.h"
#include "TextureFuncs.h"
#include "SpriteData.h"
#include "Globals.h"

class Button{
public:
    short id;
    int x, y;
    bool isHover = false;
    bool needDraw = true;
    SpriteData currentState;
    SpriteData idleState;
    SpriteData hoverState;


    Button(short id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    void draw(SDL_Renderer *renderer);
    void checkHover(Vector2 &mouse);
    bool checkClick();
};

#endif // BUTTON_H_INCLUDED
