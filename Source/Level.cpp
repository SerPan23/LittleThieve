#include "Level.h"

Level::Level() {}

Level::Level(int LevelIndex, Graphics &graphics) :
		_LevelIndex(LevelIndex),
		_size(Vector2(0,0))
{
	this->loadMap(LevelIndex, graphics);
}

Level::~Level() {}

void Level::loadMap(int LevelIndex, Graphics &graphics)
{
    if(LevelIndex == 1)
        Build_lvl_1(graphics.getRenderer(), walls);
}

void Level::update(int elapsedTime, Player &player)
{

}

void Level::draw(Graphics &graphics)
{
    for(int i = 0; i < walls.size(); i++)
        walls[i].drawWall(graphics.getRenderer());
}
