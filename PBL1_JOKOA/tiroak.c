#include <SDL.h>
#include "marraztu.h"
#include "colisiones.h"

int balakX[10];
int balakY[10];
int balakNorabidea[10];
int balakA[10];
int balakDim = 0;

extern int posX, posY;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 608;

extern SDL_Surface *bala;
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
            irudiaMarraztu(bala, bala_posicion);
        }
    }
}