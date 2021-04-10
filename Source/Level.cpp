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
    checkCollision(elapsedTime, player);
}

void Level::draw(Graphics &graphics)
{
    for(int i = 0; i < walls.size(); i++)
        walls[i].drawWall(graphics.getRenderer());
}

void Level::checkCollision(int elapsedTime, Player &player)
{
    for(int i = 0; i < walls.size(); i++)
    {
        if(player.x >= walls[i].x && player.x <= walls[i].w+walls[i].x)
        {
            if((player.y >= walls[i].h+ walls[i].y)&&(player.y + player._dy * elapsedTime <= walls[i].h + walls[i].y))// вверхняя
            {
                player._dy = 0;
                player.y = walls[i].h + walls[i].y;
            }
            else if((player.y + player.spriteData.height <= walls[i].y)&&(player.y + player.spriteData.height + player._dy * elapsedTime >= walls[i].y))// нижняя
            {
                player._dy = 0;
                player.y = walls[i].y - player.spriteData.height;
            }
        }
        if(player.y >= walls[i].y && player.y <= walls[i].h+walls[i].y)
        {
            if((player.x >= walls[i].w + walls[i].x)&&(player.x + player._dx * elapsedTime <= walls[i].w+walls[i].x))//Левая
            {
                player._dx = 0;
                player.x = walls[i].w + walls[i].x;
            }
            else if((player.x + player.spriteData.width <= walls[i].x)&&(player.x + player.spriteData.width + player._dx * elapsedTime >= walls[i].x)) //Правая
            {
                player._dx = 0;
                player.x = walls[i].x - player.spriteData.width;
            }
        }
    }

}
