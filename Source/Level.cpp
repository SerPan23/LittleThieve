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
        if(walls[i].w > walls[i].h)
        {
            if(player.y + player._dy * elapsedTime <= walls[i].h + walls[i].spriteData.height-1) // вверхн€€
            {
                player._dy = 0;
                //cout << player.y + player.spriteData.height + player._dy * elapsedTime << endl; // 543
                cout << player._dy * elapsedTime << endl;
            }
            else if(player.y + player.spriteData.height + player._dy * elapsedTime >= walls[i].h)// нижн€€
            {
                //player._dy = 0;
                //cout << player.y + player.spriteData.height + player._dy * elapsedTime << endl; // 543
                //cout << player._dy * elapsedTime << endl;
            }


        }
        else
        {

        }
    }

}
