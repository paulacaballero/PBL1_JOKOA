#include <SDL.h>
#include "props.h"
#include "inizializatu.h"
#include "marraztu.h"

SDL_Surface* naturalistaS = NULL;

extern int t, diruKant, diruEKant;

void naturalistaMarraztu()
{
    int pausoa = t % 20;

    if (pausoa < 10) naturalistaS = loadMediaUnit(naturalistaS, ".//img//naturalista1.bmp");
    else if (pausoa < 20) naturalistaS = loadMediaUnit(naturalistaS, ".//img//naturalista2.bmp");

    zerbaitMarraztu(naturalistaS, 700, 100);
}

void landareakAldatu()
{
    diruEKant += diruKant / 5;
    diruKant = diruKant % 5;
}