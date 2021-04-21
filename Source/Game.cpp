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

Game::Game(Graphics &graphics, Alphabet &alphabet, int &currentLevel, Audio &audio) {
	//SDL_Init(SDL_INIT_EVERYTHING);
	//Graphics graphics(true);
	this->_graphics = graphics;
	this->_alphabet = alphabet;
	this->audio = audio;

	this->_level = Level(currentLevel, graphics);


    this->_player = Player(this->_level._playerSpawnPoint.x, this->_level._playerSpawnPoint.y);
    _player.spriteData = loadTexture("..\\..\\Source\\Sprites\\player_idle.png");

    //this->gameLoop();
}

void Game::gameReset(int &currentLevel)
{
    this->_player = Player(this->_level._playerSpawnPoint.x, this->_level._playerSpawnPoint.y);
    _player.spriteData = loadTexture("..\\..\\Source\\Sprites\\player_idle.png");
    _level = Level(currentLevel, _graphics);
    isWin = 0;
}

Game::~Game() {

}


void Game::keyEvents(Input &input, SCREENS &newScreen)
{
    if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true || input.isKeyHeld(SDL_SCANCODE_A))
        {_player.moveLeft(); audio.playEffect(audio.footSound);}
    else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true || input.isKeyHeld(SDL_SCANCODE_D))
        {_player.moveRight(); audio.playEffect(audio.footSound);}
    if (input.isKeyHeld(SDL_SCANCODE_W) == true || input.isKeyHeld(SDL_SCANCODE_UP))
        {_player.moveTop(); audio.playEffect(audio.footSound);}
    else if (input.isKeyHeld(SDL_SCANCODE_S) == true || input.isKeyHeld(SDL_SCANCODE_DOWN))
        {_player.moveDown(); audio.playEffect(audio.footSound);}
    if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT) && !input.isKeyHeld(SDL_SCANCODE_A) && !input.isKeyHeld(SDL_SCANCODE_D))
        _player.moveStopX();
    if (!input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN) && !input.isKeyHeld(SDL_SCANCODE_S) && !input.isKeyHeld(SDL_SCANCODE_W))
        _player.moveStopY();

    if (input.wasKeyPressed(SDL_SCANCODE_E) == true)
        checkItemsAround();

    if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
        newScreen = start;
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
                //cout << "Taked" << endl;
                audio.playEffect(audio.eat);
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
            if(_player.x+_player.spriteData.width <= items[i].x && _player.x+_player.takedRadius+_player.spriteData.width >= items[i].x)
            {
                //cout << "Taked" << endl;
                audio.playEffect(audio.eat);
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
        }
        if(items[i].x >= _player.x && items[i].x <= _player.x+_player.spriteData.width)
        {
            if(_player.y >= items[i].y+items[i].spriteData.height && _player.y-_player.takedRadius <= items[i].y+items[i].spriteData.height)
            {
                //cout << "Taked" << endl;
                audio.playEffect(audio.eat);
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
            if(_player.y+_player.spriteData.height <= items[i].y && _player.y+_player.takedRadius+_player.spriteData.height >= items[i].y)
            {
                //cout << "Taked" << endl;
                audio.playEffect(audio.eat);
                _level.items.erase(_level.items.begin() + i);
                _player.currentPoints += 1;
            }
        }
    }
}


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
        newScreen = levelend;
    }
    if((_player.x > 1444)&&(this->_player.currentPoints == this->_level.necessaryPoints))
    {
        isWin = 1;
        newScreen = levelend;
    }
    if(this->_player.currentPoints == this->_level.necessaryPoints)
    {
        _level.doors[0].isLock = 0;
        _level.doors[0].open();
    }
    else
        isWin = 0;

    keyEvents(input, newScreen);

    this->_level.update(elapsedTime, this->_player);
    this->_player.update(elapsedTime);
    this->_hud.update(_alphabet, this->_player.currentPoints, this->_level._TIME);
}
