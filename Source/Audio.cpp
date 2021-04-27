#include "Audio.h"

Audio::Audio(bool needInit) {
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
    //Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_OpenAudio(44100, AUDIO_S16, 2, 4096);

    click = Mix_LoadWAV("..\\..\\Source\\Music\\click_001.wav");
    eat = Mix_LoadWAV("..\\..\\Source\\Music\\eatCandy.wav");
    footSound = Mix_LoadWAV("..\\..\\Source\\Music\\footstep03.wav");
    doorOpen = Mix_LoadWAV("..\\..\\Source\\Music\\doorOpen_1.wav");

    //music = Mix_LoadMUS("..\\..\\Source\\Music\\Mozart.mp3");
    music = Mix_LoadMUS("..\\..\\Source\\Music\\3.mp3");

    setMusicVolume(3);
    setEffectVolume(click, 5);
    setEffectVolume(eat, 20);
    setEffectVolume(footSound, 1);
    setEffectVolume(doorOpen, 20);
}

void Audio::setMusicVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

void Audio::playPausedMusic(Mix_Music *music)
{
    if(Mix_PlayingMusic() == 0)
        Mix_PlayMusic(music, -1);
    else
    {
        if(Mix_PausedMusic() == 1)
            Mix_ResumeMusic();
        else
            Mix_PauseMusic();
    }
}

void Audio::stopMusic(Mix_Music *music)
{
     if(Mix_PlayingMusic() == 1)
        Mix_HaltMusic();
}


void Audio::setEffectVolume(Mix_Chunk *effect, int volume)
{
    Mix_VolumeChunk(effect, volume);
}

void Audio::playEffect(Mix_Chunk *effect)
{
    Mix_PlayChannel( -1, effect, 0 );
}
