#include <SDL.h>
#include <stdlib.h>
#include <math.h>
#include "tiroak.h"
#include "marraztu.h"
#include "inizializatu.h"
#include "dirua.h"
#include "colisiones.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int t;

extern int posX, posY;

extern SDL_Surface* enemigo_irudia;

int enemigoGela = 0;

int enemigoX[20];
int enemigoY[20];
int enemigoHP[20];
int enemigoDim = 0;
int enemigoAbiadura = 1;

int enemigoHpMax = 5;

extern int balakX[10];
extern int balakY[10];
extern int balakA[10];
extern int hp;

int invulnerable = 0;
int azkenDamageT = 0;

SDL_Rect enemigo_posicion;

enum direkzioak { BEHERA, GORA, EZK, ESK };

extern int dañoEnemigos;

void batBorratu(int b[], int pos, int dim)
{
    int i;
    for (i = pos; i < dim - 1; i++)
    {
        b[i] = b[i + 1];
    }
}

void spawnEnemy()
{
    bat_mugitu(enemigoX, enemigoDim);
    bat_mugitu(enemigoY, enemigoDim);
    bat_mugitu(enemigoHP, enemigoDim);

    enemigoX[0] = rand() % (SCREEN_WIDTH - 200) + 100;
    enemigoY[0] = rand() % 200 + SCREEN_HEIGHT + 200;
    enemigoHP[0] = rand() % enemigoHpMax + 1;

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
    int difX = posX + 20 - eX;
    int difY = posY + 60 - eY;

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
        enemigo_posicion.x = enemigoX[i];
        enemigo_posicion.y = enemigoY[i];
        int pausoa = t % 20;
        if (pausoa < 5) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//basura1.bmp");
        else if (pausoa < 10) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//basura2.bmp");
        else if (pausoa < 15) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//basura3.bmp");
        else if (pausoa < 20) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//basura2.bmp");
        irudiaMarraztu(enemigo_irudia, enemigo_posicion);
    }
}

void enemigoakMarraztu2()
{
    int i;
    for (i = 0; i < enemigoDim; i++)
    {
        enemigo_posicion.x = enemigoX[i];
        enemigo_posicion.y = enemigoY[i];
        int pausoa = t % 20;
        int direkzioa = direkzioaLortu(enemigoX[i], enemigoY[i]);
        if (direkzioa == GORA || direkzioa == EZK)
        {
            if (pausoa < 5) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//e_minero1.bmp");
            else if (pausoa < 10) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//e_minero2.bmp");
            else if (pausoa < 15) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//e_minero3.bmp");
            else if (pausoa < 20) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//e_minero4.bmp");
        }
        else if (direkzioa == BEHERA || direkzioa == ESK)
        {
            if (pausoa < 5) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//minero1.bmp");
            else if (pausoa < 10) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//minero2.bmp");
            else if (pausoa < 15) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//minero3.bmp");
            else if (pausoa < 20) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//minero4.bmp");
        }
        irudiaMarraztu(enemigo_irudia, enemigo_posicion);
    }
}

void enemigoak()
{
    if (enemigoGela == 1)
    {
        enemigoHpMax = 5;
        dañoEnemigos = 1;
        enemigoAbiadura = 2;
        if (t % 50 == 0 && enemigoDim < 20) spawnEnemy();
        moveEnemy();
        enemigoakMarraztu();
    }
    else if (enemigoGela == 2)
    {
        enemigoHpMax = 20;
        dañoEnemigos = 3;
        enemigoAbiadura = 1;
        if (t % 25 == 0 && enemigoDim < 20) spawnEnemy();
        moveEnemy();
        enemigoakMarraztu2();
    }
}

void resetEnemies()
{
    enemigoDim = 0;
}