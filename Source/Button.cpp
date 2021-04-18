#include "Button.h"

void Button::draw(SDL_Renderer *renderer)
{
    drawTexture(this->currentState.texture, renderer, this->x, this->y);
}

void Button::checkHover(Vector2 &mouse)
{
    if((mouse.x >= x && mouse.x <= x+currentState.width)&&(mouse.y >= y && mouse.y <= y+currentState.height))
    {
        isHover = true;
        currentState = hoverState;
    }
    else
    {
        isHover = false;
        currentState = idleState;
    }
}


bool Button::checkClick()
{
    if(isHover)
        return true;
    return false;
}
