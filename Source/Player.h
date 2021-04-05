#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "LittleThieve.h"

class Player{
    public:
        int x;
        int y;
        int width = 48;
        int height = 48;
        float speed = 0.2f;
        Player(int x, int y, int width, int height)
        {
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
        }
        Player(){}

        void movePlayer(SDL_Event event);

        void moveLeft();
        void moveRight();
        void moveTop();
        void moveDown();

        void drawPlayer(SDL_Renderer *renderer)
        {
            filled_rect(renderer, x, y, width, height, 0, 255, 0);
        }
    private:
        float _dx, _dy;
};


#endif // PLAYER_H_INCLUDED
