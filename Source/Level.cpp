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
        Build_lvl_1(graphics.getRenderer(), walls, items, floor);
}

void Level::update(int elapsedTime, Player &player)
{
    checkCollision(elapsedTime, player);
}

void Level::draw(Graphics &graphics)
{
    //floor.drawFloor(graphics.getRenderer());
    for(int i = 0; i < walls.size(); i++)
        walls[i].drawWall(graphics.getRenderer());
    for(int i = 0; i < items.size(); i++)
    {
        Item *p = items[i];
        p->draw(graphics.getRenderer());
    }
}

void Level::checkCollision(int elapsedTime, Player &player)
{
    for(int i = 0; i < walls.size(); i++)
    {
        if((player.x >= walls[i].x && player.x <= walls[i].w+walls[i].x)||(player.x+player.spriteData.width >= walls[i].x && player.x+player.spriteData.width <= walls[i].w+walls[i].x)||(player.x+player.spriteData.width/2 >= walls[i].x && player.x+player.spriteData.width/2 <= walls[i].w+walls[i].x))
        {
            if(((player.y >= walls[i].h + walls[i].y)||(player.y+player.spriteData.width >= walls[i].h + walls[i].y)||(player.y+player.spriteData.width/2 >= walls[i].h + walls[i].y))&&(player.y + player._dy * elapsedTime <= walls[i].h + walls[i].y))// ��������
            {
                player._dy = 0;
                //player.y = walls[i].h + walls[i].y;
            }
            else if(((player.y + player.spriteData.height <= walls[i].y)||(player.y + player.spriteData.height + player.spriteData.width <= walls[i].y)||(player.y + player.spriteData.height + player.spriteData.width/2 <= walls[i].y))&&(player.y + player.spriteData.height + player._dy * elapsedTime >= walls[i].y))// ������
            {
                player._dy = 0;
                //player.y = walls[i].y - player.spriteData.height;
            }
        }
        if((player.y >= walls[i].y && player.y <= walls[i].h+walls[i].y)||(player.y+player.spriteData.height >= walls[i].y && player.y+player.spriteData.height <= walls[i].h+walls[i].y)||(player.y+player.spriteData.height/2 >= walls[i].y && player.y+player.spriteData.height/2 <= walls[i].h+walls[i].y))
        {
            if(((player.x >= walls[i].w + walls[i].x)||(player.x+player.spriteData.height >= walls[i].w + walls[i].x)||(player.x+player.spriteData.height/2 >= walls[i].w + walls[i].x))&&(player.x + player._dx * elapsedTime <= walls[i].w+walls[i].x))//�����
            {
                player._dx = 0;
                //player.x = walls[i].w + walls[i].x;
            }
            else if(((player.x + player.spriteData.width <= walls[i].x)||(player.x + player.spriteData.width+player.spriteData.height <= walls[i].x)||(player.x + player.spriteData.width+player.spriteData.height/2 <= walls[i].x))&&(player.x + player.spriteData.width + player._dx * elapsedTime >= walls[i].x)) //������
            {
                player._dx = 0;
                //player.x = walls[i].x - player.spriteData.width;
            }
        }
    }

    for(int i = 0; i < items.size(); i++)
    {
        Item *itemi = items[i];
        if((player.x >= itemi->x && player.x <= itemi->w+itemi->x)||(player.x+player.spriteData.width >= itemi->x && player.x+player.spriteData.width <= itemi->w+itemi->x)||(player.x+player.spriteData.width/2 >= itemi->x && player.x+player.spriteData.width/2 <= itemi->w+itemi->x))
        {
            if(((player.y >= itemi->h + itemi->y)||(player.y+player.spriteData.width >= itemi->h + itemi->y)||(player.y+player.spriteData.width/2 >= itemi->h + itemi->y))&&(player.y + player._dy * elapsedTime <= itemi->h + itemi->y))// ��������
            {
                player._dy = 0;
                //player.y = itemi->h + itemi->y;
            }
            else if(((player.y + player.spriteData.height <= itemi->y)||(player.y + player.spriteData.height + player.spriteData.width <= itemi->y)||(player.y + player.spriteData.height + player.spriteData.width/2 <= itemi->y))&&(player.y + player.spriteData.height + player._dy * elapsedTime >= itemi->y))// ������
            {
                player._dy = 0;
                //player.y = itemi->y - player.spriteData.height;
            }
        }
        if((player.y >= itemi->y && player.y <= itemi->h+itemi->y)||(player.y+player.spriteData.height >= itemi->y && player.y+player.spriteData.height <= itemi->h+itemi->y)||(player.y+player.spriteData.height/2 >= itemi->y && player.y+player.spriteData.height/2 <= itemi->h+itemi->y))
        {
            if(((player.x >= itemi->w + itemi->x)||(player.x+player.spriteData.height >= itemi->w + itemi->x)||(player.x+player.spriteData.height/2 >= itemi->w + itemi->x))&&(player.x + player._dx * elapsedTime <= itemi->w+itemi->x))//�����
            {
                player._dx = 0;
                //player.x = itemi->w + itemi->x;
            }
            else if(((player.x + player.spriteData.width <= itemi->x)||(player.x + player.spriteData.width+player.spriteData.height <= itemi->x)||(player.x + player.spriteData.width+player.spriteData.height/2 <= itemi->x))&&(player.x + player.spriteData.width + player._dx * elapsedTime >= itemi->x)) //������
            {
                player._dx = 0;
                //player.x = itemi->x - player.spriteData.width;
            }
        }
    }

}
