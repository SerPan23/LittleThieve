#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "LittleThieve.h"
#include "TextureFuncs.h"
#include "SpriteData.h"
//#include "Level.h"

class Player{
    public:
        float x;
        float y;
        //int width = 48;
        //int height = 48;
        float speed = 0.4f;
        //vector <vector<SDL_Color> > texture; //vector <vector<SDL_Color> > texture = loadTexture("123");
        SpriteData spriteData;
        Player(int x, int y, int width, int height)
        {
            this->x = x;
            this->y = y;
            this->spriteData.width = width;
            this->spriteData.height = height;
        }
        Player(){}

        void movePlayer(SDL_Event event);

        void moveLeft();
        void moveRight();
        void moveTop();
        void moveDown();
        void moveStop();
        //bool checkCollosion(vector <Wall> &walls);

        void update(float elapsedTime);
        void drawPlayer(SDL_Renderer *renderer);
    private:
        float _dx = 0.0f, _dy = 0.0f;
};


#endif // PLAYER_H_INCLUDED
