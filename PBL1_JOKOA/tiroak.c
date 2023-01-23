#include <SDL.h>
#include "marraztu.h"
#include "colisiones.h"
#include "inizializatu.h"

int balakX[11];
int balakY[11];
int balakNorabidea[11];
int balakA[11];
int balakDim = 0;

extern int posX, posY;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 608;

extern SDL_Surface* bala;
extern SDL_Rect bala_posicion;

enum direkzioak { BEHERA, GORA, EZK, ESK };

void bat_mugitu(int b[], int dim)
{
    int i;
    for (i = dim; i > 0; i--)
    {
        b[i] = b[i - 1];
    }
}

void tiroEgin(int direkzioa)
{
    bat_mugitu(balakX, balakDim);
    bat_mugitu(balakY, balakDim);
    bat_mugitu(balakNorabidea, balakDim);
    bat_mugitu(balakA, balakDim);
    balakX[0] = posX + 30;
    balakY[0] = posY + 65;
    balakA[0] = 1;
    balakNorabidea[0] = direkzioa;
    if (balakDim < 10) balakDim++;
}

void balakMugitu()
{
    int i;
    for (i = 0; i < balakDim; i++)
    {
        if (balakA[i])
        {
            switch (balakNorabidea[i])
            {
            case GORA:
                balakY[i] -= 5;
                break;
            case BEHERA:
                balakY[i] += 5;
                break;
            case EZK:
                balakX[i] -= 5;
                break;
            case ESK:
                balakX[i] += 5;
                break;
            }
        }
        balaKolizioak(i);
    }
}

void balakMarraztu()
{
    int i;
    for (i = 0; i < balakDim; i++)
    {
        if (balakA[i])
        {
            bala_posicion.x = balakX[i];
            bala_posicion.y = balakY[i];
            switch (balakNorabidea[i])
            {
            case GORA:
                bala = loadMediaUnit(bala, ".//img//bala_arriba.bmp");
                break;
            case BEHERA:
                bala = loadMediaUnit(bala, ".//img//bala_abajo.bmp");
                break;
            case EZK:
                bala = loadMediaUnit(bala, ".//img//bala_izquierda.bmp");
                break;
            case ESK:
                bala = loadMediaUnit(bala, ".//img//bala_derecha.bmp");
                break;
            }
            irudiaMarraztu(bala, bala_posicion);
        }
    }
}