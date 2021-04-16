#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "LittleThieve.h"
#include "TextureFuncs.h"
#include "SpriteData.h"

class Player{
    public:
        float x;
        float y;
        //int width = 48;
        //int height = 48;
        float speed = 0.4f;
        int takedRadius = 10;
        float _dx = 0.0f, _dy = 0.0f;
        //vector <vector<SDL_Color> > texture; //vector <vector<SDL_Color> > texture = loadTexture("123");
        SpriteData spriteData;
        Player(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
        Player(){}

        void keyEvents(SDL_Event event);

        void moveLeft();
        void moveRight();
        void moveTop();
        void moveDown();
        void moveStop();
        void takeSMT();

        void update(float elapsedTime);
        void drawPlayer(SDL_Renderer *renderer);
    //private:

};


#endif // PLAYER_H_INCLUDED
