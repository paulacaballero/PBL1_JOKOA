#include <SDL.h>
#include <stdlib.h>
#include <math.h>
#include "marraztu.h"
#include "props.h"
#include "inizializatu.h"
#include "colisiones.h"
#include "enemigos.h"
#include "tiroak.h" 

SDL_Surface* bossImage = NULL;
SDL_Surface* bossTiro = NULL;
extern SDL_Surface* vidaUBoss;

extern int t, dañoBoss, vidaBoss;
extern SDL_Surface* vidaU;
extern SDL_Surface* recuadroVida;

int bossGela = 0;

extern int enemigoDim, enemigoX[], enemigoY[], enemigoHP[];
extern SDL_Rect enemigo_posicion;
extern SDL_Surface* enemigo_irudia;

extern int enemigoHpMax, dañoEnemigos, enemigoAbiadura, hp, quit, died, azkenDamageT;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

float disparoX[11], disparoY[11], disparoA[11], destX[11], destY[11];
int disparoDim = 0;
extern int posX, posY;

int fase = 1;

enum direkzioak { BEHERA, GORA, EZK, ESK };

void marraztuBoss(int px, int py)
{
    int pausoa = t % 20;
    if (pausoa < 5) bossImage = loadMediaUnit(bossImage, ".//img//nube1.bmp");
    else if (pausoa < 10) bossImage = loadMediaUnit(bossImage, ".//img//nube2.bmp");
    else if (pausoa < 15) bossImage = loadMediaUnit(bossImage, ".//img//nube3.bmp");
    else if (pausoa < 20) bossImage = loadMediaUnit(bossImage, ".//img//nube4.bmp");
    zerbaitMarraztu(bossImage, px, py);
    //jokalariKolizioKarratua(px, px + 303, py, py + 186); 
}

void barraVidaBoss(int px, int py)
{
    int i;
    SDL_Rect posizioa;

    posizioa.x = px;
    posizioa.y = py;

    recuadroVida = loadMediaUnit(recuadroVida, ".//img//vida_nube.bmp");
    irudiaMarraztu(recuadroVida, posizioa);

    posizioa.x = px + 40;
    posizioa.y = py + 6;
    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVida.bmp");

    for (i = 0; i < 100; i++)
    {
        irudiaMarraztu(recuadroVida, posizioa);
        posizioa.x += 10;
    }

    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVidaFinal.bmp");
    irudiaMarraztu(recuadroVida, posizioa);

    posizioa.x = px + 40;
    posizioa.y = py + 10;

    for (i = 0; i < vidaBoss; i++)
    {
        irudiaMarraztu(vidaUBoss, posizioa);
        posizioa.x += 1;
    }
}

void miniBossMarraztu()
{
    int i;
    for (i = 0; i < enemigoDim; i++)
    {
        enemigo_posicion.x = enemigoX[i];
        enemigo_posicion.y = enemigoY[i];
        int pausoa = t % 20;
        if (pausoa < 5) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//spawn1.bmp");
        else if (pausoa < 10) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//spawn2.bmp");
        else if (pausoa < 15) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//spawn3.bmp");
        else if (pausoa < 20) enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//spawn4.bmp");
        irudiaMarraztu(enemigo_irudia, enemigo_posicion);
    }
}

void spawnMiniBoss()
{
    bat_mugitu(enemigoX, enemigoDim);
    bat_mugitu(enemigoY, enemigoDim);
    bat_mugitu(enemigoHP, enemigoDim);

    enemigoX[0] = 500;
    enemigoY[0] = 280;
    enemigoHP[0] = rand() % enemigoHpMax + 1;

    enemigoDim++;
}

void miniBoss()
{
    enemigoHpMax = 150;
    dañoEnemigos = 5;
    enemigoAbiadura = 3;
    if (t % 200 == 0 && enemigoDim < 20) spawnMiniBoss();
    moveEnemy();
    miniBossMarraztu();
}

void bossTiroEgin()
{
    bat_mugitu(disparoX, disparoDim);
    bat_mugitu(disparoY, disparoDim);
    bat_mugitu(disparoA, disparoDim);
    bat_mugitu(destX, disparoDim);
    bat_mugitu(destY, disparoDim);

    disparoX[0] = 524;
    disparoY[0] = 288;
    disparoA[0] = 1;
    destX[0] = posX + 38 - disparoX[0];
    destY[0] = posY + 80 - disparoY[0];

    float modulo = sqrt(pow(destX[0], 2) + pow(destY[0], 2));
    destX[0] /= modulo;
    destY[0] /= modulo;

    if (disparoDim < 10) disparoDim++;
}

void disparoKolisioak(int i)
{
    if (disparoX[i] < 70 || disparoX[i] > 980)
    {
        disparoA[i] = 0;
    }
    else if (disparoY[i] < 80 || disparoY[i] > SCREEN_HEIGHT - 100)
    {
        disparoA[i] = 0;
    }

    if (fabs(disparoX[i] - posX - 22) < 25 && fabs(disparoY[i] - posY - 64) < 25 && t - azkenDamageT > 30)
    {
        disparoA[i] = 0;
        hp -= 5;
        azkenDamageT = t;

        if (hp <= 0)
        {
            quit = 1;
            died = 1;
        }
    }
}

void disparoakMugitu()
{
    int i;
    for (i = 0; i < disparoDim; i++)
    {
        disparoX[i] += 4 * destX[i];
        disparoY[i] += 4 * destY[i];
        disparoKolisioak(i);
    }
}

void disparoBossMarraztu()
{
    int pausoa, i;
    pausoa = t % 15;

    for (i = 0; i < disparoDim; i++)
    {
        if (disparoA[i])
        {
            if (pausoa < 5) bossTiro = loadMediaUnit(bossTiro, ".//img//bala_boss1.bmp");
            else if (pausoa < 10) bossTiro = loadMediaUnit(bossTiro, ".//img//bala_boss2.bmp");
            else if (pausoa < 15) bossTiro = loadMediaUnit(bossTiro, ".//img//bala_boss3.bmp");
            zerbaitMarraztu(bossTiro, disparoX[i], disparoY[i]);
        }
    }
}

void disparosBoss()
{
    if (t % 20 == 0) bossTiroEgin();
    disparoakMugitu();
    disparoBossMarraztu();
}

void combateBoss()
{
    if (bossGela)
    {
        if (vidaBoss < 500) fase = 2;
        if (fase == 2) miniBoss();
        if (fase == 1) disparosBoss();
        marraztuBoss(388, 211);
        barraVidaBoss(20, 550);
        bossKolisioak(388, 211);
    }
}