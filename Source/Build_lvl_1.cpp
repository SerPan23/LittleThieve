#include "Item.h"
#include "Game.h"
#include "LevelBulders.h"
#include "Player.h"
#include "Globals.h"
#include "Door.h"

void    Build_lvl_1(SDL_Renderer *renderer, Vector2 &playerSpawnPoint, vector <Wall> &walls, vector <Item> &items, Floor &floor, vector<Door> &doors, int &necessaryPoints, float &levelTime)
{
    levelTime = 100;
    playerSpawnPoint.x = 1334;
    playerSpawnPoint.y = 495;
    necessaryPoints = 1;

    Floor floor1(50, 50, 1392, 912);
    floor1.spriteData = loadTexture("..\\..\\Source\\Sprites\\Floor_1.png");
    floor = floor1;

    Door door(1404, 482);
    door.spriteDataIdle = loadTexture("..\\..\\Source\\Sprites\\door(441).png");
    door.spriteDataOpen = loadTexture("..\\..\\Source\\Sprites\\doorOpen(441).png");
    door.spriteData = door.spriteDataIdle;
    doors.push_back(door);

    Wall main_wall_1(1, 98, 50, 1298, 48, 48); // 1, 50, 50, 1394, 48, 48
    Wall main_wall_2(1, 50, 98, 48, 818, 48); // 1, 50, 50, 48, 914, 48
    Wall main_wall_3(1, 98, 914, 1298, 48, 48); // 1, 50, 914, 1394, 48, 48
    Wall main_wall_4(1, 1394, 98, 48, 336, 48); // 1, 1394, 50, 48, 914, 48
    Wall main_wall_5(1, 1394, 594, 48, 336, 48);
    Wall main_wall_4_end(1, 1394, 434, 48, 48, 48);
    Wall main_wall_5_end(1, 1394, 546, 48, 48, 48);
    Wall main_wallAngle1(1, 50, 50, 48, 48, 48);
    Wall main_wallAngle2(1, 1394, 50, 48, 48, 48);
    Wall main_wallAngle3(1, 50, 914, 48, 48, 48);
    Wall main_wallAngle4(1, 1394, 914, 48, 48, 48);

    Wall kitchen_1(1, 98, 849, 512, 64, 64);
    kitchen_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\kitchen_1.png");
    walls.push_back(kitchen_1);

    Wall bed_1(1, 638, 99, 128, 192, 64);
    bed_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\bed_1.png");
    walls.push_back(bed_1);

    Wall sofa_1(1, 800, 722, 64, 192, 64);
    sofa_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\sofa_1(green).png");
    walls.push_back(sofa_1);

    Wall tv_1(1, 921, 757, 32, 128, 32);
    tv_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\tv_big.png");
    walls.push_back(tv_1);

    Wall armchair(1, 100, 100, 64, 64, 64);
    armchair.spriteData = loadTexture("..\\..\\Source\\Sprites\\armchair.png");
    walls.push_back(armchair);

    Wall flower(1, 703, 849, 64, 64, 64);
    flower.spriteData = loadTexture("..\\..\\Source\\Sprites\\flower.png");
    walls.push_back(flower);

    main_wall_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(111).bmp");
    main_wall_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(138).bmp");
    main_wall_3.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(111).bmp");
    main_wall_4.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(138).bmp");
    main_wall_4_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall_4_end(115).png");
    main_wall_5.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall(138).bmp");
    main_wall_5_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wall_5_end(141).png");
    main_wallAngle1.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(109).bmp");
    main_wallAngle2.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(110).bmp");
    main_wallAngle3.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(136).bmp");
    main_wallAngle4.spriteData = loadTexture("..\\..\\Source\\Sprites\\main_wallAngle(137).bmp");

    Wall wall_1(1, 767, 98, 32, 256, 32);
    Wall wall_2(1, 479, 354, 288, 32, 32);
    Wall wall_1_2(1, 767, 354, 32, 32, 32);
    Wall wall_2_end(1, 479, 354, 32, 32, 32);
    Wall wall_3(1, 98, 356, 150, 32, 32);
    Wall wall_3_end(1, 216, 356, 32, 32, 32);
    Wall wall_4(1, 767, 658, 32, 256, 32);
    Wall wall_4_end(1, 767, 626, 32, 32, 32);
    walls.push_back(main_wall_1);
    walls.push_back(main_wall_2);
    walls.push_back(main_wall_3);
    walls.push_back(main_wall_4);
    walls.push_back(main_wall_4_end);
    walls.push_back(main_wall_5);
    walls.push_back(main_wall_5_end);
    walls.push_back(main_wallAngle1);
    walls.push_back(main_wallAngle2);
    walls.push_back(main_wallAngle3);
    walls.push_back(main_wallAngle4);
    wall_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(147).bmp");
    wall_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_1_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_1_2(146).bmp");
    wall_2_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_2_end(151).bmp");
    wall_3.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_3_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_3_end(123).bmp");
    wall_4.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(147).bmp");
    wall_4_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_4_end(150).bmp");
    walls.push_back(wall_1);
    walls.push_back(wall_2);
    walls.push_back(wall_1_2);
    walls.push_back(wall_2_end);
    walls.push_back(wall_3);
    walls.push_back(wall_3_end);
    walls.push_back(wall_4);
    walls.push_back(wall_4_end);

    Item candy_1(1, 100, 320, 32, 32, 0);
    candy_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\candyRed2.bmp");
    items.push_back(candy_1);

    /*wall_1.drawWall(renderer);
    wall_2.drawWall(renderer);
    wall_3.drawWall(renderer);
    wall_4.drawWall(renderer);*/
}
