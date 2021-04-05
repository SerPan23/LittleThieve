#include "Game.h"
#include "Player.h"
#include "Globals.h"
#include "Item.h"
#include "Wall.h"

namespace {
	const int FPS = 60;
	const int MAX_FRAME_TIME = 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {

    vector <Wall> walls;
    vector <Item *> items;

    SDL_Event event;

    Graphics graphics(true);

    this->_player = Player(1334, 495, 48, 48, 3);

    int LAST_UPDATE_TIME = SDL_GetTicks();

    bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                quit = true;

            if(event.type == SDL_KEYDOWN)
                _player.movePlayer(event);
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->_graphics = graphics;
		this->draw(graphics);
    }

}


void Game::draw(Graphics &graphics) {
    graphics.clear();
    Build_lvl_1(graphics.getRenderer());
    _player.drawPlayer(graphics.getRenderer());
    graphics.flip();
}

void Game::update(float elapsedTime) {
    //this->_player.update(elapsedTime);
}
