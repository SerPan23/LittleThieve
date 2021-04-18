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

Game::Game(Graphics &graphics, Alphabet &alphabet) {
	//SDL_Init(SDL_INIT_EVERYTHING);
	//Graphics graphics(true);
	this->_graphics = graphics;
	this->_alphabet = alphabet;

	this->_level = Level(1, graphics);

    this->_player = Player(this->_level._playerSpawnPoint.x, this->_level._playerSpawnPoint.y);
    _player.spriteData = loadTexture("..\\..\\Source\\Sprites\\player_idle.png");

    this->_level._TIME = 30;

    //this->gameLoop();
}

Game::~Game() {

}

/*void Game::keyEvents(SDL_Event event)
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
}*/

void Game::keyEvents(Input &input)
{
    if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true || input.isKeyHeld(SDL_SCANCODE_A))
        _player.moveLeft();
    else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true || input.isKeyHeld(SDL_SCANCODE_D))
        _player.moveRight();
    if (input.isKeyHeld(SDL_SCANCODE_W) == true || input.isKeyHeld(SDL_SCANCODE_UP))
        _player.moveTop();
    else if (input.isKeyHeld(SDL_SCANCODE_S) == true || input.isKeyHeld(SDL_SCANCODE_DOWN))
        _player.moveDown();
    if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT) && !input.isKeyHeld(SDL_SCANCODE_A) && !input.isKeyHeld(SDL_SCANCODE_D))
        _player.moveStopX();
    if (!input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN) && !input.isKeyHeld(SDL_SCANCODE_S) && !input.isKeyHeld(SDL_SCANCODE_W))
        _player.moveStopY();

    if (input.wasKeyPressed(SDL_SCANCODE_E) == true)
        checkItemsAround();
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

/*void Game::gameLoop() {

    SDL_Event event;

    this->_level = Level(1, this->_graphics);

    this->_player = Player(this->_level._playerSpawnPoint.x, this->_level._playerSpawnPoint.y);
    _player.spriteData = loadTexture("..\\..\\Source\\Sprites\\player_idle.png");


    Alphabet alphabet;
    alphabet.loadAlphabet("..\\..\\Source\\Sprites\\alphabet\\alphabet_24px.png");
    _alphabet = alphabet;


    int LAST_UPDATE_TIME = SDL_GetTicks();

    this->_level._TIME = 8*1000;
    bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                quit = true;

            //if(event.type == SDL_KEYDOWN)
                //_player.keyEvents(event);
                //keyEvents(event);
            if(event.type == SDL_MOUSEMOTION)
            {
                mouse.x = event.motion.x;
                mouse.y = event.motion.y;
            }
        }



        const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		this->_level._TIME -= ELAPSED_TIME_MS;


		//this->update(it_min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		this->draw(this->_graphics);
    }

}*/


void Game::draw(Graphics &graphics) {
    graphics.clear();

    _level.draw(graphics);
    _player.drawPlayer(graphics.getRenderer());
    _hud.draw(graphics.getRenderer());

    graphics.flip();
}

void Game::update(float elapsedTime, Input &input, SCREENS &newScreen) {
    this->_level._TIME -= elapsedTime;
    if(this->_level._TIME <= 0)
    {
        if(this->_player.currentPoints == this->_level.necessaryPoints)
            isWin = 1;
        else
            isWin = 0;
        newScreen = levelend;
    }

    keyEvents(input);

    this->_level.update(elapsedTime, this->_player);
    this->_player.update(elapsedTime);
    this->_hud.update(_alphabet, this->_player.currentPoints, this->_level._TIME);
}
