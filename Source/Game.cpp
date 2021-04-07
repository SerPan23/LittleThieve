#include "Game.h"
#include "Player.h"
#include "Globals.h"
#include "Item.h"
#include "Wall.h"
#include "TextureFuncs.h"

namespace {
	const int FPS = 100;
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
    this->_level = Level(1, graphics);

    this->_player = Player(1334, 495, 48, 48);
    _player.spriteData = loadTexture("..\\..\\Source\\Sprites\\image.bmp");

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

		this->_graphics = graphics;
		this->update(it_min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		this->draw(graphics);
    }

}


void Game::draw(Graphics &graphics) {
    graphics.clear();
    //Build_lvl_1(graphics.getRenderer());
    _level.draw(graphics);
    _player.drawPlayer(graphics.getRenderer());
    graphics.flip();
}

void Game::update(float elapsedTime) {
    this->_level.update(elapsedTime, this->_player);
    this->_player.update(elapsedTime);
}
