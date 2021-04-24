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
        float speed = 100.0f;
        int takedRadius = 10;
        float _dx = 0.0f, _dy = 0.0f;
        int currentPoints = 0;
        int seeSide = 0;
        //vector <vector<SDL_Color> > texture; //vector <vector<SDL_Color> > texture = loadTexture("123");
        SpriteData spriteData;

        SpriteData idleSprite;

        vector<SpriteData> moveRightSprites;
        vector<SpriteData> moveLeftSprites;
        int CurrentFrame = 0;
        int MaxFrames = 7;
        int FrameInc = 1;

        int FrameRate = 100;
        int OldTime = 0;

        void Animate(int side);

        Player(int x, int y);
        Player(){}

        void keyEvents(SDL_Event event);

        void moveLeft();
        void moveRight();
        void moveTop();
        void moveDown();
        void moveStopX();
        void moveStopY();

        void update(float elapsedTime);
        void drawPlayer(SDL_Renderer *renderer);
};


#endif // PLAYER_H_INCLUDED
