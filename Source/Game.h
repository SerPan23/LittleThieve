#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "LittleThieve.h"
#include "Player.h"
#include "Graphics.h"
#include "Level.h"
#include "HUD.h"
#include "Alphabet.h"
#include "Button.h"
#include "Input.h"

class Game{
public:
    Game(){}
    Game(Graphics &graphics, Alphabet &alphabet);
	~Game();

public:
	//void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime, Input &input, SCREENS &newScreen);

	//void keyEvents(SDL_Event event);
	void keyEvents(Input &input);
	void checkItemsAround();

	bool isWin;


	Player _player;
	Level _level;
	HUD _hud;
	Graphics _graphics;
	Alphabet _alphabet;
	Vector2 mouse;
};



#endif // GAME_H_INCLUDED
