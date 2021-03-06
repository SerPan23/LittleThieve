#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "LittleThieve.h"
#include "Graphics.h"
#include "Player.h"
#include "Item.h"
#include "Globals.h"
#include "LevelBulders.h"
#include "Door.h"
#include "Audio.h"

class Level{
public:
    Level();
	Level(int LevelIndex, Graphics &graphics);
	~Level();

	vector <Wall> walls;
	Floor floor;
    vector <Item> items;
    vector <Door> doors;
    Vector2 _playerSpawnPoint;
    int necessaryPoints;
    float _TIME;

	void update(float elapsedTime, Player &player);
	void draw(Graphics &graphics);
	void checkCollision(float elapsedTime, Player &player);
	void checkCollisionWall(float elapsedTime, Player &player);
	void checkCollisionItem(float elapsedTime, Player &player);
	void checkCollisionDoor(float elapsedTime, Player &player);


	void (*levelLogic)(Level &level, Player &player, Audio &audio, SCREENS &newScreen, bool &isWin);


private:
    void loadMap(int LevelIndex, Graphics &graphics);
    int _LevelIndex;
    Vector2 _size;
};

void level1Logic(Level &level, Player &player, Audio &audio, SCREENS &newScreen, bool &isWin);
void level2Logic(Level &level, Player &player, Audio &audio, SCREENS &newScreen, bool &isWin);
void level3Logic(Level &level, Player &player, Audio &audio, SCREENS &newScreen, bool &isWin);

#endif // LEVEL_H_INCLUDED
