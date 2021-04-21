#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include "LittleThieve.h"

class Audio{
public:
    Audio(){}
    Audio(bool needInit);

    //Музыка
    Mix_Music *music = NULL;
    //Звуки
    Mix_Chunk *click = NULL;
    Mix_Chunk *eat = NULL;
    Mix_Chunk *footSound = NULL;

    void setMusicVolume(int volume);
    void playPausedMusic(Mix_Music *music);
    void stopMusic(Mix_Music *music);

    void setEffectVolume(Mix_Chunk *effect, int volume);
    void playEffect(Mix_Chunk *effect);
};

#endif // AUDIO_H_INCLUDED
