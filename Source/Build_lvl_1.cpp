#include "Item.h"
#include "Game.h"
#include "LevelBulders.h"

void    Build_lvl_1(SDL_Renderer *renderer, vector <Wall> &walls, vector <Item *> &items, Floor &floor)
{
    Floor floor1(50, 50, 1394, 914);
    Wall main_wall_1(1, 98, 50, 1298, 48, 48); // 1, 50, 50, 1394, 48, 48
    Wall main_wall_2(1, 50, 98, 48, 818, 48); // 1, 50, 50, 48, 914, 48
    Wall main_wall_3(1, 98, 914, 1298, 48, 48); // 1, 50, 914, 1394, 48, 48
    Wall main_wall_4(1, 1394, 98, 48, 818, 48); // 1, 1394, 50, 48, 914, 48
    Wall main_wallAngle1(1, 50, 50, 48, 48, 48);
    Wall main_wallAngle2(1, 1394, 50, 48, 48, 48);
    Wall main_wallAngle3(1, 50, 914, 48, 48, 48);
    Wall main_wallAngle4(1, 1394, 914, 48, 48, 48);

    floor1.spriteData = loadTexture("..\\..\\Source\\Sprites\\floor(96).bmp");
    main_wall_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(111).bmp");
    main_wall_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(138).bmp");
    main_wall_3.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(111).bmp");
    main_wall_4.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(138).bmp");
    main_wallAngle1.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(109).bmp");
    main_wallAngle2.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(110).bmp");
    main_wallAngle3.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(136).bmp");
    main_wallAngle4.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(137).bmp");
    floor = floor1;

    Wall wall_1(1, 767, 98, 32, 288, 32);
    Wall wall_2(1, 479, 354, 288, 32, 32);
    Wall wall_3(1, 100, 356, 150, 32, 32);
    Wall wall_4(1, 767, 625, 32, 288, 32);
    walls.push_back(main_wall_1);
    walls.push_back(main_wall_2);
    walls.push_back(main_wall_3);
    walls.push_back(main_wall_4);
    walls.push_back(main_wallAngle1);
    walls.push_back(main_wallAngle2);
    walls.push_back(main_wallAngle3);
    walls.push_back(main_wallAngle4);
    wall_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(138)32x32.bmp");
    wall_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(111)32x32.bmp");
    walls.push_back(wall_1);
    walls.push_back(wall_2);
    /*wall_1.drawWall(renderer);
    wall_2.drawWall(renderer);
    wall_3.drawWall(renderer);
    wall_4.drawWall(renderer);*/
}
