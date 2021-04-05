#include "Player.h"

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
}
