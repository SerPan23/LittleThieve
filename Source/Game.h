#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "LittleThieve.h"
#include "Player.h"
#include "Graphics.h"
#include "Level.h"
#include "Alphabet.h"

class Game{
public:
    Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	void keyEvents(SDL_Event event);
	void checkItemsAround();

	Player _player;
	Level _level;
	Graphics _graphics;
	Alphabet _alphabet;
};



#endif // GAME_H_INCLUDED
