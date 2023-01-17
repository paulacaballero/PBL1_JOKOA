#ifndef INIZIALIZATU
#define INIZIALIZATU

#include <SDL.h>

int init();
void close();
int loadMedia();
SDL_Surface* loadMediaUnit(SDL_Surface* surface, char path[]);
void inizializazioa();

#endif