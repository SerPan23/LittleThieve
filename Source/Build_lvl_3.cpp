#include "Item.h"
#include "Game.h"
#include "LevelBulders.h"
#include "Player.h"
#include "Globals.h"
#include "Door.h"

void    Build_lvl_3(SDL_Renderer *renderer, Vector2 &playerSpawnPoint, vector <Wall> &walls, vector <Item> &items, Floor &floor, vector<Door> &doors, int &necessaryPoints, float &levelTime)
{
    levelTime = 90;
    playerSpawnPoint.x = 1334;
    playerSpawnPoint.y = 495;
    necessaryPoints = 1;

    Door door(1404, 482, 1);
    door.spriteDataIdle = loadTexture("..\\..\\Source\\Sprites\\door(441).png");
    door.spriteDataOpen = loadTexture("..\\..\\Source\\Sprites\\doorOpen(441).png");
    door.spriteData = door.spriteDataIdle;
    doors.push_back(door);

    Door door_1(354, 708, 2);
    door_1.spriteDataIdle = loadTexture("..\\..\\Source\\Sprites\\door(441).png");
    door_1.spriteDataOpen = loadTexture("..\\..\\Source\\Sprites\\doorOpen(441).png");
    door_1.spriteData = door_1.spriteDataIdle;
    doors.push_back(door_1);

    Floor floor1(50, 50, 1394, 914);
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

    floor1.spriteData = loadTexture("..\\..\\Source\\Sprites\\floor(96).bmp");
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

    floor = floor1;

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

    Wall wall_1(1, 98, 676, 256, 32, 32);
    Wall wall_1_end(1, 354, 676, 32, 32, 32);
    Wall wall_2(1, 354, 818, 32, 96, 32);
    Wall Wall_2_end(1, 354, 786, 32, 32, 32);
    Wall wall_3(1, 98, 441, 608, 32, 32);
    Wall wall_3_end(1, 706, 441, 32, 32, 32);
    Wall wall_4(1, 708, 98, 32, 224, 32);
    Wall wall_4_end(1, 708, 322, 32, 32, 32);
    Wall wall_5(1, 760, 722, 32, 192, 32);
    Wall wall_5_end(1, 760, 690, 32, 32, 32);
    Wall wall_6(1, 792, 690, 224, 32, 32);
    Wall wall_6_end(1, 1016, 690, 32, 32, 32);
    Wall wall_7(1, 1138, 690, 256, 32, 32);
    Wall wall_7_end(1, 1112, 690, 32, 32, 32);
    Wall wall_8(1, 920, 98, 32, 224, 32);
    Wall wall_8_end(1, 920, 322, 32, 32, 32);
    Wall wall_9(1, 952, 441, 32, 32, 32);
    Wall wall_9_end(1, 920, 441, 32, 32, 32);
    Wall wall_9_end2(1, 984, 441, 32, 32, 32);
    Wall wall_10(1, 1138, 441, 256, 32, 32);
    Wall wall_10_end(1, 1106, 441, 32, 32, 32);
    wall_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_1_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_3_end(123).bmp");
    wall_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(147).bmp");
    Wall_2_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_4_end(150).bmp");
    wall_3.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_3_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_3_end(123).bmp");
    wall_4.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(147).bmp");
    wall_4_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_end(124).bmp");
    wall_5.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(147).bmp");
    wall_5_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_end(118).bmp");
    wall_6.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_6_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_3_end(123).bmp");
    wall_7.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_7_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_2_end(151).bmp");
    wall_8.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(147).bmp");
    wall_8_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_end(124).bmp");
    wall_9.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_9_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_2_end(151).bmp");
    wall_9_end2.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_3_end(123).bmp");
    wall_10.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall(120).bmp");
    wall_10_end.spriteData = loadTexture("..\\..\\Source\\Sprites\\wall_2_end(151).bmp");
    walls.push_back(wall_1);
    walls.push_back(wall_1_end);
    walls.push_back(wall_2);
    walls.push_back(Wall_2_end);
    walls.push_back(wall_3);
    walls.push_back(wall_3_end);
    walls.push_back(wall_4);
    walls.push_back(wall_4_end);
    walls.push_back(wall_5);
    walls.push_back(wall_5_end);
    walls.push_back(wall_6);
    walls.push_back(wall_6_end);
    walls.push_back(wall_7);
    walls.push_back(wall_7_end);
    walls.push_back(wall_8);
    walls.push_back(wall_8_end);
    walls.push_back(wall_9);
    walls.push_back(wall_9_end);
    walls.push_back(wall_9_end2);
    walls.push_back(wall_10);
    walls.push_back(wall_10_end);

    Wall bed_1(1, 324, 98, 128, 192, 64);
    bed_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\bed_1.png");
    walls.push_back(bed_1);

    Wall table_1(1, 260, 98, 32, 32, 32);
    table_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\nightstand(479).png");
    walls.push_back(table_1);

    Wall table_2(1, 452, 98, 32, 32, 32);
    table_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\nightstand(479).png");
    walls.push_back(table_2);

    Wall bed_2(1, 1204, 162, 192, 128, 64);
    bed_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\bed_2.png");
    walls.push_back(bed_2);

    Wall kitchen_2(1, 884, 850, 512, 64, 64);
    kitchen_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\kitchen_2.png");
    walls.push_back(kitchen_2);

    Wall kitchen_22(1, 1332, 722, 64, 128, 64);
    kitchen_22.spriteData = loadTexture("..\\..\\Source\\Sprites\\kitchen_22.png");
    walls.push_back(kitchen_22);

    Wall box_1(1, 101, 706, 64, 64, 64);
    box_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\box(129).png");
    walls.push_back(box_1);

    Wall box_2(1, 280, 840, 64, 64, 64);
    box_2.spriteData = loadTexture("..\\..\\Source\\Sprites\\box(156).png");
    walls.push_back(box_2);

    Wall table(1, 475, 610, 192, 192, 64);
    table.spriteData = loadTexture("..\\..\\Source\\Sprites\\table.png");
    walls.push_back(table);

    Item candy_1(1, 101, 795, 32, 32, 0); // 101, 795
    candy_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\candyRed2.bmp");
    items.push_back(candy_1);

    Item key_1(2, 836, 806, 32, 32, 1); // 836, 806
    key_1.spriteData = loadTexture("..\\..\\Source\\Sprites\\key.png");
    items.push_back(key_1);
}
