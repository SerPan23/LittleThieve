#include "Player.h"


Player::Player(int x, int y)
{
    this->x = x;
    this->y = y;
    this->idleSprite = loadTexture("..\\..\\Source\\Sprites\\player\\player_idle.png");
    this->spriteData = this->idleSprite;

    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk0.png"));
    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk1.png"));
    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk2.png"));
    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk3.png"));
    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk4.png"));
    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk5.png"));
    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk6.png"));
    this->moveRightSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_right\\player_walk7.png"));

    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk0_reverse.png"));
    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk1_reverse.png"));
    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk2_reverse.png"));
    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk3_reverse.png"));
    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk4_reverse.png"));
    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk5_reverse.png"));
    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk6_reverse.png"));
    this->moveLeftSprites.push_back(loadTexture("..\\..\\Source\\Sprites\\player\\move_left\\player_walk7_reverse.png"));
}

void Player::drawPlayer(SDL_Renderer *renderer)
{
    drawTexture(this->spriteData.texture, renderer, (int)this->x, (int)this->y);
}

void Player::moveLeft() {
	this->_dx = -this->speed;
	Animate(2);
	seeSide = 1;
}

void Player::moveRight() {
	this->_dx = this->speed;
	Animate(1);
	seeSide = 0;
}

void Player::moveTop() {
	this->_dy = -this->speed;
	if(seeSide == 0)
        Animate(1);
    else
        Animate(2);
}

void Player::moveDown() {
	this->_dy = this->speed;
	if(seeSide == 0)
        Animate(1);
    else
        Animate(2);
}

void Player::moveStopX(){
    this-> _dx = 0.0f;
}

void Player::moveStopY(){
    this-> _dy = 0.0f;
}


void Player::Animate(int side) {
    if(side == 0) //idle
    {
        this->spriteData = this->idleSprite;
        return;
    }
    if(OldTime + FrameRate > SDL_GetTicks()) {
        return;
    }

    OldTime = SDL_GetTicks();

    CurrentFrame += FrameInc;

    if(CurrentFrame >= MaxFrames) {
            CurrentFrame = 0;
    }
    if(side == 1) //right
    {
        this->spriteData = this->moveRightSprites[CurrentFrame];
    }
    else if(side == 2) //Left
    {
        this->spriteData = this->moveLeftSprites[CurrentFrame];
    }
}


void Player::update(float elapsedTime)
{
    this->x += this->_dx * elapsedTime;
    this->y += this->_dy * elapsedTime;
}
