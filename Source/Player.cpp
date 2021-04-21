#include "Player.h"

void Player::drawPlayer(SDL_Renderer *renderer)
{
    drawTexture(this->spriteData.texture, renderer, (int)this->x, (int)this->y);
}

void Player::moveLeft() {
	this->_dx = -this->speed;
}

void Player::moveRight() {
	this->_dx = this->speed;
}

void Player::moveTop() {
	this->_dy = -this->speed;
}

void Player::moveDown() {
	this->_dy = this->speed;
}

void Player::moveStopX(){
    this-> _dx = 0.0f;
}

void Player::moveStopY(){
    this-> _dy = 0.0f;
}


void Player::update(float elapsedTime)
{
    this->x += this->_dx * elapsedTime;
    this->y += this->_dy * elapsedTime;
}
