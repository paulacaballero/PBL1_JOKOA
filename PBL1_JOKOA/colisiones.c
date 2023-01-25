#include <SDL.h>
#include <math.h>
#include "mapak.h"
#include "marraztu.h"
#include "enemigos.h"
#include "dirua.h"
#include "soinua.h"
#include "props.h"


extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int balakX[], balakY[], balakA[], balakDim;
extern int ipar, eki, hego, mende;

extern int monedakA[], monedakX[], monedakY[], diruKant;

extern int enemigoX[], enemigoY[], enemigoHP[], enemigoDim;
extern int t, azkenDamageT, enemigoGela, bossGela;

extern int hp, invulnerable, quit, died;

extern int posX, posY,mapaX,mapaY;
extern SDL_Window* window;

int daño = 1;
int dañoEnemigos = 1;
int enemigosKop = 200;

int vidaBoss = 1000;
int dañoBoss = 10;

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

void karratutikAtera(int x0, int x1, int y0, int y1)
{
    if (fabs(posX + 59 - x0) <= 5) posX -= 5;
    else if (fabs(posX + 7 - x1) <= 5) posX += 5;
    else if (fabs(posY + 100 - y0) <= 5) posY -= 5;
    else if (fabs(posY + 51 - y1) <= 5) posY += 5;
}

void jokalariKolizioKarratua(int x0, int x1, int y0, int y1)
{
    if (posX + 59 > x0 && posX + 7 < x1 && posY + 100 > y0 && posY + 51 < y1)
    {
        karratutikAtera(x0, x1, y0, y1);
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

void monedakKolizioak(int i)
{
    if (fabs(monedakX[i] - posX - 24) < 35 && fabs(monedakY[i] - posY - 61) < 35 && monedakA[i])
    {
        monedakA[i] = 0;
        diruKant++;
        enemigosKop++;
    }
}

void enemigoKolisioak(int i)
{
    int j;
    int centrox = 0;
    int centroy = 0;
    int dif = 0;

    if (enemigoGela == 1)
    {
        centrox = -3;
        centroy = -28;
        dif = 35;
    }
    else if (enemigoGela == 2)
    {
        centrox = 3;
        centroy = 1;
        dif = 35;
    }
    else if (bossGela == 1)
    {
        centrox = -15;
        centroy = -49;
        dif = 25;
    }

    for (j = 0; j < balakDim; j++)
    {
        if (fabs(enemigoX[i] - balakX[j] + 21) < 30 && fabs(enemigoY[i] - balakY[j] + 37) < 30 && balakA[j])
        {
            balaKolizioAnimazioa(balakX[j], balakY[j]);

            enemigoHP[i] -= daño;
            balakA[j] = 0;
        }
    }

    if (fabs(enemigoX[i] - posX + centrox) < dif && fabs(enemigoY[i] - posY + centroy) < dif && !invulnerable)
    {
        hp -= dañoEnemigos;
        invulnerable = 1;
        azkenDamageT = t;

        if (bossGela)
        {
            enemigoHP[i] = 0;
            drawProp(".//img//puf.bmp", enemigoX[i], enemigoY[i]);
        }
        if (hp <= 0)
        {
            quit = 1;
            died = 1;
        }
    }

    if (t - azkenDamageT > 100) invulnerable = 0;

    if (enemigoHP[i] <= 0)
    {
        spawnMoneda(enemigoX[i], enemigoY[i]);
        batBorratu(enemigoX, i, enemigoDim);
        batBorratu(enemigoY, i, enemigoDim);
        batBorratu(enemigoHP, i, enemigoDim);
        enemigoDim--;
    }
}
void bossKolisioak(int bx, int by)
{
    int i;

    //colisiones de las balas con el boss
    for (i = 0; i < balakDim; i++)
    {
        if (fabs(bx + 137 - balakX[i]) < 100 && fabs(by + 82 - balakY[i]) < 80 && balakA[i])
        {
            balaKolizioAnimazioa(balakX[i], balakY[i]);
            balakA[i] = 0;
            vidaBoss -= daño;
        }
    }

    //colisiones con el jugador
    if (fabs(bx + 115 - posX) < 120 && fabs(by + 18 - posY) < 85 && !invulnerable)
    {
        hp -= dañoBoss;
        invulnerable = 1;
        azkenDamageT = t;

        if (hp <= 0)
        {
            quit = 1;
            died = 1;
        }
    }

    if (t - azkenDamageT > 100) invulnerable = 0;
}
void mezuaAgertu(char* mezua, int x, int y) {
    if ((mapaX == 2 ||mapaX==3) && mapaY == 2) {
        if ((posX < 470 && posX>280) && (posY < 400 && posY>350)) {
            alerta(mezua,x,y);
        }
    }
}
void popup(char* text) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Kontuz!", text, window);
}

