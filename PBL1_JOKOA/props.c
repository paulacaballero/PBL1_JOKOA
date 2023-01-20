#include <SDL.h>
#include "inizializatu.h"
#include "marraztu.h"
#include "colisiones.h"

SDL_Surface* propS = NULL;

void drawProp(char* path, int px, int py)
{
    propS = loadMediaUnit(propS, path);
    zerbaitMarraztu(propS, px, py);
    jokalariKolizioKarratua(px, px + propS->w, py, py + propS->h);
}