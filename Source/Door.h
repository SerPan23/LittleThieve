#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "SpriteData.h"
#include "TextureFuncs.h"

class Door{
public:
    Door(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Door(int x, int y, int keyId)
    {
        this->x = x;
        this->y = y;
        this->keyId = keyId;
    }
    int x, y;
    bool isLock = true;
    bool isOpen = false;
    int keyId = -1;
    SpriteData spriteDataIdle;
    SpriteData spriteDataOpen;
    SpriteData spriteData = spriteDataIdle;
    void draw(SDL_Renderer *renderer);
    void open();
    void close();
};

#endif // DOOR_H_INCLUDED
