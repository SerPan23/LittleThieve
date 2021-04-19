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
    //this->_TIME = levelTime;
    if(LevelIndex == 1)
        Build_lvl_1(graphics.getRenderer(), this->_playerSpawnPoint, walls, items, floor, this->necessaryPoints, this->_TIME);
    else if(LevelIndex == 2)
        Build_lvl_2(graphics.getRenderer(), this->_playerSpawnPoint, walls, items, floor, this->necessaryPoints, this->_TIME);
}

void Level::update(float elapsedTime, Player &player)
{
    checkCollision(elapsedTime, player);
}

void Level::draw(Graphics &graphics)
{
    //floor.drawFloor(graphics.getRenderer());
    for(int i = 0; i < walls.size(); i++)
        walls[i].drawWall(graphics.getRenderer());
    for(int i = 0; i < items.size(); i++)
        items[i].draw(graphics.getRenderer());
}

void Level::checkCollision(float elapsedTime, Player &player)
{
    for(int i = 0; i < walls.size(); i++)
    {
        if((player.x >= walls[i].x && player.x <= walls[i].w+walls[i].x)||(player.x+player.spriteData.width >= walls[i].x && player.x+player.spriteData.width <= walls[i].w+walls[i].x)||(player.x+player.spriteData.width/2 >= walls[i].x && player.x+player.spriteData.width/2 <= walls[i].w+walls[i].x))
        {
            if(((player.y >= walls[i].h + walls[i].y)||(player.y+player.spriteData.width >= walls[i].h + walls[i].y)||(player.y+player.spriteData.width/2 >= walls[i].h + walls[i].y))&&(player.y + player._dy * elapsedTime <= walls[i].h + walls[i].y))// вверхняя
            {
                player._dy = 0;
                //player.y = walls[i].h + walls[i].y;
            }
            else if(((player.y + player.spriteData.height <= walls[i].y)||(player.y + player.spriteData.height + player.spriteData.width <= walls[i].y)||(player.y + player.spriteData.height + player.spriteData.width/2 <= walls[i].y))&&(player.y + player.spriteData.height + player._dy * elapsedTime >= walls[i].y))// нижняя
            {
                player._dy = 0;
                //player.y = walls[i].y - player.spriteData.height;
            }
        }
        if((player.y >= walls[i].y && player.y <= walls[i].h+walls[i].y)||(player.y+player.spriteData.height >= walls[i].y && player.y+player.spriteData.height <= walls[i].h+walls[i].y)||(player.y+player.spriteData.height/2 >= walls[i].y && player.y+player.spriteData.height/2 <= walls[i].h+walls[i].y))
        {
            if(((player.x >= walls[i].w + walls[i].x)||(player.x+player.spriteData.height >= walls[i].w + walls[i].x)||(player.x+player.spriteData.height/2 >= walls[i].w + walls[i].x))&&(player.x + player._dx * elapsedTime <= walls[i].w+walls[i].x))//Левая
            {
                player._dx = 0;
                //player.x = walls[i].w + walls[i].x;
            }
            else if(((player.x + player.spriteData.width <= walls[i].x)||(player.x + player.spriteData.width+player.spriteData.height <= walls[i].x)||(player.x + player.spriteData.width+player.spriteData.height/2 <= walls[i].x))&&(player.x + player.spriteData.width + player._dx * elapsedTime >= walls[i].x)) //Правая
            {
                player._dx = 0;
                //player.x = walls[i].x - player.spriteData.width;
            }
        }
    }

    for(int i = 0; i < items.size(); i++)
    {
        if((player.x >= items[i].x && player.x <= items[i].w+items[i].x)||(player.x+player.spriteData.width >= items[i].x && player.x+player.spriteData.width <= items[i].w+items[i].x)||(player.x+player.spriteData.width/2 >= items[i].x && player.x+player.spriteData.width/2 <= items[i].w+items[i].x))
        {
            if(((player.y >= items[i].h + items[i].y)||(player.y+player.spriteData.width >= items[i].h + items[i].y)||(player.y+player.spriteData.width/2 >= items[i].h + items[i].y))&&(player.y + player._dy * elapsedTime <= items[i].h + items[i].y))// вверхняя
            {
                player._dy = 0;
                //player.y = items[i].h + items[i].y;
            }
            else if(((player.y + player.spriteData.height <= items[i].y)||(player.y + player.spriteData.height + player.spriteData.width <= items[i].y)||(player.y + player.spriteData.height + player.spriteData.width/2 <= items[i].y))&&(player.y + player.spriteData.height + player._dy * elapsedTime >= items[i].y))// нижняя
            {
                player._dy = 0;
                //player.y = items[i].y - player.spriteData.height;
            }
        }
        if((player.y >= items[i].y && player.y <= items[i].h+items[i].y)||(player.y+player.spriteData.height >= items[i].y && player.y+player.spriteData.height <= items[i].h+items[i].y)||(player.y+player.spriteData.height/2 >= items[i].y && player.y+player.spriteData.height/2 <= items[i].h+items[i].y))
        {
            if(((player.x >= items[i].w + items[i].x)||(player.x+player.spriteData.height >= items[i].w + items[i].x)||(player.x+player.spriteData.height/2 >= items[i].w + items[i].x))&&(player.x + player._dx * elapsedTime <= items[i].w+items[i].x))//Левая
            {
                player._dx = 0;
                //player.x = items[i].w + items[i].x;
            }
            else if(((player.x + player.spriteData.width <= items[i].x)||(player.x + player.spriteData.width+player.spriteData.height <= items[i].x)||(player.x + player.spriteData.width+player.spriteData.height/2 <= items[i].x))&&(player.x + player.spriteData.width + player._dx * elapsedTime >= items[i].x)) //Правая
            {
                player._dx = 0;
                //player.x = items[i].x - player.spriteData.width;
            }
        }
    }

}
