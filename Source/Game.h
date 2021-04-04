#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "LittleThieve.h"
#include "Player.h"
#include "Graphics.h"

class Game{
public:
    Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Player _player;
	Graphics _graphics;
};



#endif // GAME_H_INCLUDED
