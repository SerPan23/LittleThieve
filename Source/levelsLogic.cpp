#include "Level.h"

void level1Logic(Level &level, Player &player, Audio &audio, SCREENS &newScreen, bool &isWin)
{
    if(level._TIME <= 0)
    {
        newScreen = levelend;
    }
    if((player.x > 1444)&&(player.currentPoints == level.necessaryPoints))
    {
        isWin = 1;
        newScreen = levelend;
    }
    if(player.currentPoints == level.necessaryPoints)
    {
        if(level.doors[0].isLock)
        {
            level.doors[0].isLock = 0;
            level.doors[0].open();
            audio.playEffect(audio.doorOpen);
        }
    }
    else
        isWin = 0;
}


void level2Logic(Level &level, Player &player, Audio &audio, SCREENS &newScreen, bool &isWin)
{
    if(level._TIME <= 0)
    {
        newScreen = levelend;
    }
    if((player.x > 1444)&&(player.currentPoints == level.necessaryPoints))
    {
        isWin = 1;
        newScreen = levelend;
    }
    if(player.currentPoints == level.necessaryPoints)
    {
        if(level.doors[0].isLock)
        {
            level.doors[0].isLock = 0;
            level.doors[0].open();
            audio.playEffect(audio.doorOpen);
        }
    }
    else
        isWin = 0;
}


void level3Logic(Level &level, Player &player, Audio &audio, SCREENS &newScreen, bool &isWin)
{
    if(level._TIME <= 0)
    {
        newScreen = levelend;
    }
    if((player.x > 1444)&&(player.currentPoints == level.necessaryPoints))
    {
        isWin = 1;
        newScreen = levelend;
    }
    /*if(player.currentPoints == level.necessaryPoints)
    {
        level.doors[0].isLock = 0;
        level.doors[0].open();
    }*/
    else
        isWin = 0;
}
