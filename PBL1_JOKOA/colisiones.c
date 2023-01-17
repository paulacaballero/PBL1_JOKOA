#include <SDL.h>
#include "mapak.h"
#include "marraztu.h"
#include "update.h"

#define MEZUA_ATEA "atea"

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int balakX[], balakY[], balakA[], balakDim;
extern int ipar, eki, hego, mende;
extern int posX, posY;
extern int mapaX, mapaY;

void balaKolizioak(int i)
{
    if (balakX[i] < 70 || balakX[i] > 980)
    {
        if (balakA[i]) balaKolizioAnimazioa(balakX[i], balakY[i]);
        balakA[i] = 0;
    }
    else if (balakY[i] < 80 || balakY[i] > SCREEN_HEIGHT - 100)
    {
        if (balakA[i]) balaKolizioAnimazioa(balakX[i], balakY[i]);
        balakA[i] = 0;
    }
}

void jokalariKolizioak()
{
    if (posX < 100)
    {
        if (mende)
        {
            if (posY < 190 || posY > 250) posX += 5;
        }
        else posX += 5;
    }

    if (posX > SCREEN_WIDTH - 170)
    {
        if (eki)
        {
            if (posY > 250 || posY < 190) posX -= 5;
        }
        else posX -= 5;
    }

    if (posY < 45)
    {
        if (ipar)
        {
            if (posX < 470 || posX > 560) posY += 5;
        }
        else posY += 5;
    }

    if (posY > SCREEN_HEIGHT - 215)
    {
        if (hego)
        {
            if (posX < 470 || posX > 560) posY -= 5;
        }
        else posY -= 5;
    }
    ateak();
}

void mezuaAgertu() {
    if (mapaX == 2 && mapaY == 2) {
        if ((posX < 470 && posX>280) && (posY < 393 && posY>280)) {
            alerta(MEZUA_ATEA);
        }
    }
}


