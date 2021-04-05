#include "Wall.h"
#include "Item.h"
#include "Game.h"

void    Build_lvl_1(SDL_Renderer *renderer)
{
    Candy candy(625, 225, 24, 24, 255, 0, 255);
    candy.draw(renderer);
    Wall main_wall_1(1, 98, 50, 1298, 48, 48); // 1, 50, 50, 1394, 48, 48
    Wall main_wall_2(1, 50, 98, 48, 818, 48); // 1, 50, 50, 48, 914, 48
    Wall main_wall_3(1, 98, 914, 1298, 48, 48); // 1, 50, 914, 1394, 48, 48
    Wall main_wall_4(1, 1394, 98, 48, 818, 48); // 1, 1394, 50, 48, 914, 48
    Wall main_wallAngle1(1, 50, 50, 48, 48, 48);
    Wall main_wallAngle2(1, 1394, 50, 48, 48, 48);
    Wall main_wallAngle3(1, 50, 914, 48, 48, 48);
    Wall main_wallAngle4(1, 1394, 914, 48, 48, 48);

    main_wall_1.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wall(111).bmp");
    main_wall_2.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wall(138).bmp");
    main_wall_3.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wall(111).bmp");
    main_wall_4.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wall(138).bmp");
    main_wallAngle1.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(109).bmp");
    main_wallAngle2.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(110).bmp");
    main_wallAngle3.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(136).bmp");
    main_wallAngle4.objData.texture = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(137).bmp");

    main_wall_1.drawWall(renderer);
    main_wall_2.drawWall(renderer);
    main_wall_3.drawWall(renderer);
    main_wall_4.drawWall(renderer);
    main_wallAngle1.drawWall(renderer);
    main_wallAngle2.drawWall(renderer);
    main_wallAngle3.drawWall(renderer);
    main_wallAngle4.drawWall(renderer);

    Wall wall_1(1, 767, 100, 32, 300, 32);
    Wall wall_2(1, 479, 356, 300, 32, 32);
    Wall wall_3(1, 100, 356, 150, 32, 32);
    Wall wall_4(1, 767, 625, 32, 300, 32);
    wall_1.drawWall(renderer);
    wall_2.drawWall(renderer);
    wall_3.drawWall(renderer);
    wall_4.drawWall(renderer);
}
