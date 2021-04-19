#ifndef LEVELBULDERS_H_INCLUDED
#define LEVELBULDERS_H_INCLUDED
#include "Floor.h"
#include "Wall.h"
#include "Item.h"

void    Build_lvl_1(SDL_Renderer *renderer, Vector2 &playerSpawnPoint, vector <Wall> &walls, vector <Item> &items, Floor &floor, int &necessaryPoints, float &levelTime);
void    Build_lvl_2(SDL_Renderer *renderer, Vector2 &playerSpawnPoint, vector <Wall> &walls, vector <Item> &items, Floor &floor, int &necessaryPoints, float &levelTime);

#endif // LEVELBULDERS_H_INCLUDED
