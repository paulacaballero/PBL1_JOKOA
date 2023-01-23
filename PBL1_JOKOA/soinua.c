#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include "soinua.h"


Mix_Chunk* disparo;
Mix_Chunk* hil;
char karga[MAX_SOUNDS];
int soinuKop = 0;
Mix_Music* musika = NULL;
int battleMusicOn = 1;
int mainMusicOn = 0;
int finalMusicOn = 1;
int id;
int loadD = 0;
int loadH = 0;
void soinuaDisparo() {
    
    if (loadH == 0) {
        hil = Mix_LoadWAV(DISPARO);
        loadH = 1;
    }
    Mix_PlayChannel(-1, disparo, 0);
}
void soinuaHil() {
    if (loadH == 0) {
        hil = Mix_LoadWAV(HIL);
        loadH = 1;
    }
    Mix_PlayChannel(-1, hil, 0);
}

void musikaAldaketa(int soinua) {
    
    if (soinua == 2) {
        if (finalMusicOn != 1) {
            audioInit();
            loadTheMusic(FINAL_MUSIC);
            playMusic();
            mainMusicOn = 0;
            battleMusicOn = 0;
            finalMusicOn = 1;
        }
    }
    if (soinua == 1) {
        if (mainMusicOn!=1) {
            audioInit();
            loadTheMusic(MAIN_MUSIC);
            playMusic();
            mainMusicOn = 1;
            battleMusicOn = 0;
            finalMusicOn = 0;
        }
    }
    if (soinua == 0) {
        if (battleMusicOn!=1) {
            audioInit();
            loadTheMusic(BATTLE_MUSIC);
            playMusic();
            mainMusicOn = 0;
            battleMusicOn = 1;
            finalMusicOn = 0;
        }
    }
}

void audioInit()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}
int loadTheMusic(char* fileName)
{
    int wasPlaying = 0;

    if (musika != NULL)
    {
        wasPlaying = (Mix_PlayingMusic() != 1);
        Mix_HaltMusic();
        //Mix_FreeMusic(musika);
    }
    if ((musika = Mix_LoadMUS(fileName)) == NULL) return 0;
    if (wasPlaying)  Mix_PlayMusic(musika, -1);
    return 1;
}
int playMusic(void)
{
    if (musika != NULL)
    {
        Mix_PlayMusic(musika, -1);
        return 1;
    }
    return 0;
}

