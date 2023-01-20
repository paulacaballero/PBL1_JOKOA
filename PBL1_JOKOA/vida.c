#include <SDL.h>
#include "marraztu.h"
#include "inizializatu.h"

int hp = 10;
int hpMax = 10;
extern SDL_Surface* vidaU;
extern SDL_Surface* recuadroVida;

void vidaMarraztu()
{
    int i;
    SDL_Rect posizioa;

    posizioa.x = 20;
    posizioa.y = 65;

    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVidaInicio.bmp");
    irudiaMarraztu(recuadroVida, posizioa);

    posizioa.x = 60;
    posizioa.y = 71;
    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVida.bmp");

    for (i = 0; i < hpMax; i++)
    {
        irudiaMarraztu(recuadroVida, posizioa);
        posizioa.x += 10;
    }

    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVidaFinal.bmp");
    irudiaMarraztu(recuadroVida, posizioa);

    posizioa.x = 60;
    posizioa.y = 75;

    for (i = 0; i < hp; i++)
    {
        irudiaMarraztu(vidaU, posizioa);
        posizioa.x += 10;
    }
}