#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "tiroak.h"
#include "marraztu.h"
#include "inizializatu.h"
#include <math.h>
#include "colisiones.h"

int diruKant = 0;
int diruEKant = 0;

int monedakX[20];
int monedakY[20];
int monedakA[20];
int monedakDim = 0;

extern int posX, posY, t;
extern SDL_Surface* moneda;
extern SDL_Surface* monedaE;

extern TTF_Font* font;
extern SDL_Color black;
extern SDL_Surface* mezua;

void marraztuMoneda(int px, int py)
{
    SDL_Rect posizioa;
    posizioa.x = px;
    posizioa.y = py;
    int pausoa = t % 50;
    if (pausoa < 25) moneda = loadMediaUnit(moneda, ".//img//planta1.bmp");
    else if (pausoa < 50) moneda = loadMediaUnit(moneda, ".//img//planta2.bmp");
    irudiaMarraztu(moneda, posizioa);
}

void marraztuMonedaE(int px, int py)
{
    SDL_Rect posizioa;
    posizioa.x = px;
    posizioa.y = py;

    int pausoa = t % 30;
    if (pausoa < 5) monedaE = loadMediaUnit(monedaE, ".//img//moneda1.bmp");
    else if (pausoa < 10) monedaE = loadMediaUnit(monedaE, ".//img//moneda2.bmp");
    else if (pausoa < 15) monedaE = loadMediaUnit(monedaE, ".//img//moneda3.bmp");
    else if (pausoa < 20) monedaE = loadMediaUnit(monedaE, ".//img//moneda4.bmp");
    else if (pausoa < 25) monedaE = loadMediaUnit(monedaE, ".//img//moneda5.bmp");
    else if (pausoa < 30) monedaE = loadMediaUnit(monedaE, ".//img//moneda6.bmp");

    irudiaMarraztu(monedaE, posizioa);
}

void spawnMoneda(int px, int py)
{
    bat_mugitu(monedakX, monedakDim);
    bat_mugitu(monedakY, monedakDim);
    bat_mugitu(monedakA, monedakDim);

    monedakX[0] = px;
    monedakY[0] = py;
    monedakA[0] = 1;

    if (monedakDim < 20) monedakDim++;
}

void marraztuDirua()
{
    SDL_Rect posizioa;
    char textua[20];

    marraztuMoneda(900, 10);
    marraztuMonedaE(895, 60);

    posizioa.x = 980;
    posizioa.y = 15;

    sprintf(textua, "%d", diruKant);
    SDL_FreeSurface(mezua);
    mezua = TTF_RenderText_Solid(font, textua, black);
    irudiaMarraztu(mezua, posizioa);

    posizioa.y = 65;
    sprintf(textua, "%d", diruEKant);
    SDL_FreeSurface(mezua);
    mezua = TTF_RenderText_Solid(font, textua, black);
    irudiaMarraztu(mezua, posizioa);
}

void monedakf()
{
    int i;

    for (i = 0; i < monedakDim; i++)
    {
        if (monedakA[i])
        {
            marraztuMoneda(monedakX[i], monedakY[i]);
            monedakKolizioak(i);
        }
    }

    marraztuDirua();
}

void resetMonedas()
{
    monedakDim = 0;
}
