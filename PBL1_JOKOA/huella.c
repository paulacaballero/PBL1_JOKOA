#include <SDL.h>
#include "marraztu.h"
#include "inizializatu.h"

int huellaCarbono = 50;
int huellaMax = 70;

extern int t;

extern SDL_Surface* recuadroVida;

extern SDL_Surface* huellaU;

void huellaIgo()
{
    if (t % 600 == 0) huellaCarbono++;
}

void huellaMarraztu()
{
    int i;
    SDL_Rect posizioa;

    posizioa.x = 20;
    posizioa.y = 20;

    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroHuellaInicio.bmp");
    irudiaMarraztu(recuadroVida, posizioa);

    posizioa.x = 60;
    posizioa.y = 26;
    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVida.bmp");

    for (i = 0; i < huellaMax / 2; i++)
    {
        irudiaMarraztu(recuadroVida, posizioa);
        posizioa.x += 10;
    }

    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVidaFinal.bmp");
    irudiaMarraztu(recuadroVida, posizioa);

    posizioa.x = 60;
    posizioa.y = 30;

    for (i = 0; i < huellaCarbono; i++)
    {
        irudiaMarraztu(huellaU, posizioa);
        posizioa.x += 5;
    }
}