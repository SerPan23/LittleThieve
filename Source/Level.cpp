#include "Level.h"

Level::Level() {}

Level::Level(int LevelIndex, Graphics &graphics) :
		_mapIndex(mapName),
		_size(Vector2(0,0))
{
	this->loadMap(LevelIndex, graphics);
}

Level::~Level() {

}

Level::loadMap(int LevelIndex, Graphics &graphics)
{

}

Level::update(int elapsedTime, Player &player)
{

}

Level::draw(Graphics &graphics)
{

}
