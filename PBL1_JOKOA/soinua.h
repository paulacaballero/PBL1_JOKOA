#ifndef SOINUA_H
#define SOINUA_H

#define MAX_SOUNDS 10
#define MAIN_MUSIC ".//music//main_theme.wav"
#define BATTLE_MUSIC ".//music//battle_theme.wav"
#define FINAL_MUSIC ".//music//finalboss_theme.wav"
#define DISPARO ".//music//slime_disparo.wav"
#define HIL ".//music//hit.wav"
#define PLANTA ".//music//coin.wav"

#include <SDL_mixer.h>

void audioInit();
int loadTheMusic(char* fileName);
int playMusic(void);
void musikaAldaketa(int soinua);
void soinuaDisparo();
void soinuaHil();
#endif 
