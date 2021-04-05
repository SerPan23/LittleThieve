#include "Player.h"

void Player::drawPlayer(SDL_Renderer *renderer)
{
    //filled_rect(renderer, x, y, width, height, 0, 255, 0);
    drawTexture(this->objData.texture, renderer, (int)this->objData.x, (int)this->objData.y);
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

void Player::moveStop(){
    this-> _dx = 0.0f;
    this-> _dy = 0.0f;
}

void Player::movePlayer(SDL_Event event)
{
        if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
        {
            this->moveTop();
        }

        if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
        {
            this->moveDown();
        }

        if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
        {
            this->moveLeft();
        }

        if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
        {
            this->moveRight();
        }
        if(!(event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)&&!(event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)&&!(event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)&&!(event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D))
            this->moveStop();
}

void Player::update(float elapsedTime)
{
    int t = this->objData.x;
    //cout << this->_dx << " " << elapsedTime << " | " << this->_dx * elapsedTime << endl;
    this->objData.x += this->_dx * elapsedTime;
    //cout << this->x-t << endl;
    this->objData.y += this->_dy * elapsedTime;
    this-> _dx = 0.0f;
    this-> _dy = 0.0f;

}
