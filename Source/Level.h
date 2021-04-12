#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "Player.h"
#include "Item.h"
#include "Globals.h"
#include "LevelBulders.h"

class Level{
public:
    Level();
	Level(int LevelIndex, Graphics &graphics);
	~Level();

	vector <Wall> walls;
	Floor floor;

	void update(int elapsedTime, Player &player);
	void draw(Graphics &graphics);
	void checkCollision(int elapsedTime, Player &player);


private:
    void loadMap(int LevelIndex, Graphics &graphics);
    int _LevelIndex;
    Vector2 _size;
};

#endif // LEVEL_H_INCLUDED
