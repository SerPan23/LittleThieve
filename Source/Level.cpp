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
    for(int i = 0; i < walls.size(); i++){
        if(walls[i].w > walls[i].h) // горизонтальные
        {
            if(player.y > walls[i].h)
                if(player.y + player._dy * elapsedTime <= walls[i].h + walls[i].spriteData.height-1) // вверхн€€
                {
                    player._dy = 0;
                }
            else if(player.y + player.spriteData.height < walls[i].y)
                if(player.y + player.spriteData.height + player._dy * elapsedTime >= walls[i].y)// нижн€€
                {
                    player._dy = 0;
                }
        }
        else
        {
            if(player.x > walls[i].w)
                if(player.x + player._dx * elapsedTime <= walls[i].w + walls[i].spriteData.width+1) // вверхн€€
                {
                    player._dx = 0;
                }
            else if(player.x + player.spriteData.width < walls[i].x)
                if(player.x + player.spriteData.width + player._dx * elapsedTime >= walls[i].x)// нижн€€
                {
                    player._dx = 0;
                }
        }
    }

}
