#include <SDL.h>
#include <stdlib.h>
#include <math.h>
#include "tiroak.h"
#include "marraztu.h"
#include "inizializatu.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int t;

extern int posX, posY;

extern SDL_Surface* enemigo_irudia;

int enemigoGela = 0;

int enemigoX[20];
int enemigoY[20];
int enemigoA[20];
int enemigoHP[20];
int enemigoDim = 0;
int enemigoAbiadura = 1;

extern int balakX[10];
extern int balakY[10];
extern int balakA[10];

SDL_Rect enemigo_posicion;

enum direkzioak { BEHERA, GORA, EZK, ESK };

void batBorratu(int b[], int pos, int dim)
{
    int i;
    for (i = pos; i < dim - 1; i++)
    {
        b[i] = b[i + 1];
    }
}

void enemigoKolisioak(int i)
{
    int j;

    for (j = 0; j < 10; j++)
    {
        if (fabs(enemigoX[i] - balakX[j]) < 10 && fabs(enemigoY[i] - balakY[j]) < 10)
        {
            if (balakA[j]) balaKolizioAnimazioa(balakX[j], balakY[j]);

            enemigoHP[i] -= 1;
            balakA[j] = 0;
        }
    }

    if (enemigoHP[i] == 0)
    {
        batBorratu(enemigoX, i, enemigoDim);
        batBorratu(enemigoY, i, enemigoDim);
        batBorratu(enemigoHP, i, enemigoDim);
        enemigoDim--;
    }
}

void spawnEnemy()
{
    bat_mugitu(enemigoX, enemigoDim);
    bat_mugitu(enemigoY, enemigoDim);
    bat_mugitu(enemigoA, enemigoDim);
    bat_mugitu(enemigoHP, enemigoDim);

    enemigoX[0] = rand() % (SCREEN_WIDTH + 1);
    enemigoY[0] = rand() % 200 + SCREEN_HEIGHT + 200;
    enemigoHP[0] = rand() % 4 + 2;
    enemigoA[0] = 1;

    enemigoDim++;
}

void moveEnemy()
{
    int i;
    for (i = 0; i < enemigoDim; i++)
    {
        switch (direkzioaLortu(enemigoX[i], enemigoY[i]))
        {
        case GORA:
            enemigoY[i] += enemigoAbiadura;
            break;
        case BEHERA:
            enemigoY[i] -= enemigoAbiadura;
            break;
        case EZK:
            enemigoX[i] -= enemigoAbiadura;
            break;
        case ESK:
            enemigoX[i] += enemigoAbiadura;
            break;
        }

        enemigoKolisioak(i);
    }
}

int direkzioaLortu(int eX, int eY)
{
    int direkzioa;
    int difX = posX - eX;
    int difY = posY - eY;

    if (fabs(difX) >= fabs(difY))
    {
        if (difX < 0) direkzioa = EZK;
        else direkzioa = ESK;
    }
    else
    {
        if (difY < 0) direkzioa = BEHERA;
        else direkzioa = GORA;
    }

    return direkzioa;
}

void enemigoakMarraztu()
{
    int i;
    for (i = 0; i < enemigoDim; i++)
    {
        if (enemigoA[i])
        {
            enemigo_posicion.x = enemigoX[i];
            enemigo_posicion.y = enemigoY[i];
            int pausoa = t % 25;
            if (pausoa < 5) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//enemigo_zombi1.bmp");
            else if (pausoa < 10) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//enemigo_zombi2.bmp");
            else if (pausoa < 15) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//enemigo_zombi3.bmp");
            else if (pausoa < 20) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//enemigo_zombi4.bmp");
            else if (pausoa < 25) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//enemigo_zombi5.bmp");
            irudiaMarraztu(enemigo_irudia, enemigo_posicion);
        }
    }
}

void enemigoak()
{
    if (enemigoGela)
    {
        if (t % 50 == 0 && enemigoDim < 20) spawnEnemy();
        moveEnemy();
        enemigoakMarraztu();
    }
}