#include <SDL.h>
#include "inizializatu.h"
#include "soinua.h"

int mapaX = 1;
int mapaY = 2;

extern SDL_Surface* background;
extern SDL_Surface* backgroundCopy;

extern int posX, posY;
int ipar, eki,mende,hego;

extern int enemigoGela;

void mapak()
{
    ipar = 0;
    hego = 0;
    eki = 0;
    mende = 0;
    enemigoGela = 0;
    switch (mapaY)
    {
    case 1:
        //dendak
        switch (mapaX)
        {
        case 2:
            background = loadMediaUnit(background, ".//img//tienda_3.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//tienda_3.bmp");
            hego = 1;
            break;
        case 3:
            background = loadMediaUnit(background, ".//img//tienda_3.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//tienda_3.bmp");
            hego = 1;
            break;
        }
        break;
    case 2:
        switch (mapaX)
        {
        case 1:
            //hasiera
            background = loadMediaUnit(background, ".//img//bg.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//bg.bmp");
            eki = 1;
            break;
        case 2:
            //lobby 1
            background = loadMediaUnit(background, ".//img//sala_segura_1.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//sala_segura_1.bmp");
            ipar = eki = mende = hego = 1;
            break;
        case 3:
            //lobby 2
            background = loadMediaUnit(background, ".//img//sala_segura_1.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//sala_segura_1.bmp");
            ipar = eki = mende = hego = 1;
            break;
        case 4:
            //final boss
            mende = 1;
            break;
        }
        break;
    case 3:
        switch (mapaX)
        {
        case 2:
            //minijuegos 1
            background = loadMediaUnit(background, ".//img//cueva_v0.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//cueva_v0.bmp");
            audioTerminate();
            loadTheMusic(".//music//battle_theme.wav");
            ipar = 1;
            enemigoGela = 1;
            break;
        case 3:
            //minijuegos 2
            background = loadMediaUnit(background, ".//img//cueva_v0.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//cueva_v0.bmp");
            ipar = 1;
            enemigoGela = 1;
            break;
        }
        break;
    }
}

void ateak()
{
    if (posY < 250 && posY>190)
    {
        if (posX < 40)
        {
            mapaX -= 1;
            posX = 959;
        }
        if (posX > 961)
        {
            mapaX += 1;
            posX = 50;
        }
    }
    if (posX < 560 && posX>470)
    {
        if (posY < 0)
        {
            mapaY -= 1;
            posY = 450;
        }
        if (posY > 460)
        {
            mapaY += 1;
            posY = 20;
        }
    }
    mapak();
    
}
