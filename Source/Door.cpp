#include "Door.h"

void Door::draw(SDL_Renderer *renderer)
{
    drawTexture(this->spriteData.texture, renderer, this->x, this->y);
}

void Door::open()
{
    spriteData = spriteDataOpen;
    isOpen = 1;
}

void Door::close()
{
    spriteData = spriteDataIdle;
    isOpen = 0;
}
