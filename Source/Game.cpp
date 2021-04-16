#include "Game.h"
#include "Player.h"
#include "Globals.h"
#include "Item.h"
#include "Wall.h"
#include "TextureFuncs.h"


namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::keyEvents(SDL_Event event)
{
    if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
    {
        _player.moveTop();
    }

    if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
    {
        _player.moveDown();
    }

    if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
    {
        _player.moveLeft();
    }

    if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
    {
        _player.moveRight();
    }
    if (event.key.keysym.scancode == SDL_SCANCODE_E)
    {
        checkItemsAround();
        //_player.takeSMT();
    }
}

void Game::checkItemsAround()
{
    vector <Item> items = _level.items;
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i].y >= _player.y && items[i].y <= _player.y+_player.spriteData.height)
        {
            if(_player.x >= items[i].x+items[i].spriteData.width && _player.x-_player.takedRadius <= items[i].x+items[i].spriteData.width)
            {
                cout << "Taked" << endl;
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
            if(_player.x+_player.spriteData.width <= items[i].x && _player.x+_player.takedRadius+_player.spriteData.width >= items[i].x)
            {
                cout << "Taked" << endl;
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
        }
        if(items[i].x >= _player.x && items[i].x <= _player.x+_player.spriteData.width)
        {
            if(_player.y >= items[i].y+items[i].spriteData.height && _player.y-_player.takedRadius <= items[i].y+items[i].spriteData.height)
            {
                cout << "Taked" << endl;
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
            if(_player.y+_player.spriteData.height <= items[i].y && _player.y+_player.takedRadius+_player.spriteData.height >= items[i].y)
            {
                cout << "Taked" << endl;
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
        }
    }
}

void Game::gameLoop() {

    SDL_Event event;

    Graphics graphics(true);
    this->_level = Level(1, graphics);

    this->_player = Player(this->_level._playerSpawnPoint.x, this->_level._playerSpawnPoint.y);
    _player.spriteData = loadTexture("..\\..\\Source\\Sprites\\player_idle.png");


    Alphabet alphabet;
    alphabet.loadAlphabet("..\\..\\Source\\Sprites\\alphabet\\alphabet_24px.png");
    _alphabet = alphabet;


    int LAST_UPDATE_TIME = SDL_GetTicks();

    bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                quit = true;

            if(event.type == SDL_KEYDOWN)
                //_player.keyEvents(event);
                keyEvents(event);
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
    SDL_Color c;
    c.r = 255;
    c.g = 255;
    c.b = 0;
    c.a = 255;
    _alphabet.drawLetter(graphics.getRenderer(), 'S', 10, 10, c);
    _alphabet.drawLetter(graphics.getRenderer(), 'C', 40, 10, c);
    _alphabet.drawLetter(graphics.getRenderer(), 'O', 70, 10, c);
    _alphabet.drawLetter(graphics.getRenderer(), 'R', 100, 10, c);
    _alphabet.drawLetter(graphics.getRenderer(), 'E', 120, 10, c);
    _alphabet.drawLetter(graphics.getRenderer(), ':', 150, 10, c);
    _alphabet.drawLetter(graphics.getRenderer(), _player.currentPoints+48, 180, 10, c);
    graphics.flip();
}

void Game::update(float elapsedTime) {
    this->_level.update(elapsedTime, this->_player);
    this->_player.update(elapsedTime);
}
