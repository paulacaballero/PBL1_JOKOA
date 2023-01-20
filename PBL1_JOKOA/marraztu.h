#ifndef MARRAZTU
#define MARRAZTU

#include <SDL.h>

void irudiaMarraztu(SDL_Surface* irudia, SDL_Rect posizioa);
void jokalariaMarraztu();
void alerta(char* textua, int x, int y);
void pantailaGarbitu();
void balaKolizioAnimazioa(int px, int py);
void zerbaitMarraztu(SDL_Surface* irudia, int px, int py);

#endif