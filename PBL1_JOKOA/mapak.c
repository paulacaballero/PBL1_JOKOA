#include <SDL.h>
#include <stdio.h>
#include "inizializatu.h"
#include "armero.h"
#include "enemigos.h"
#include "dirua.h"
#include "soinua.h"
#include "colisiones.h"
#include "props.h"
#include "naturalista.h"
#include "guardia.h"
#include "mapak.h"

int mapaX = 1;
int mapaY = 2;

extern SDL_Surface* background;
extern SDL_Surface* backgroundCopy;

extern Mix_Music* musika;

extern int posX, posY,t;
int ipar, eki,mende,hego;

extern int enemigoGela,enemigosKop;
extern int bossGela;

void mapak()
{
    int soinua = 0;
    ipar = 0;
    hego = 0;
    eki = 0;
    mende = 0;
    enemigoGela = 0;
    bossGela = 0;
    
    switch (mapaY)
    {
    case 1:
        //denda
        switch (mapaX)
        {
        case 2:
            background = loadMediaUnit(background, ".//img//tienda_3.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//tienda_3.bmp");
            drawProp(".//img//planta.bmp", 120, 90);
            drawProp(".//img//caja3.bmp", 200, 100);
            drawProp(".//img//caja1.bmp", 120, 140);
            drawProp(".//img//caja2.bmp", 270, 180);
            drawProp(".//img//caja3.bmp", 400, 140);
            drawProp(".//img//caja2.bmp", 900, 370);
            drawProp(".//img//caja3.bmp", 840, 400);
            drawProp(".//img//caja3.bmp", 100, 350);
            drawProp(".//img//caja3.bmp", 200, 380);
            drawProp(".//img//caja3.bmp", 120, 400);
            drawProp(".//img//caja2.bmp", 290, 430);
            marraztuPuesto();
            drawProp(".//img//planta.bmp", 410, 200);
            drawProp(".//img//planta.bmp", 190, 170);
            drawProp(".//img//caja2.bmp", 750, 120);
            drawProp(".//img//planta.bmp", 650, 100);
            drawProp(".//img//caja3.bmp", 520, 120);
            drawProp(".//img//caja2.bmp", 500, 190);
            drawProp(".//img//barril.bmp", 700, 270);
            drawProp(".//img//caja2.bmp", 670, 340);
            naturalistaMarraztu();
            soinua = 1;
            hego = 1;
            break;
        case 3:
            background = loadMediaUnit(background, ".//img//tienda_3.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//tienda_3.bmp");
            drawProp(".//img//planta.bmp", 120, 90);
            drawProp(".//img//caja3.bmp", 200, 100);
            drawProp(".//img//caja1.bmp", 120, 140);
            drawProp(".//img//caja2.bmp", 270, 180);
            drawProp(".//img//caja3.bmp", 400, 140);
            drawProp(".//img//caja2.bmp", 900, 370);
            drawProp(".//img//caja3.bmp", 840, 400);
            drawProp(".//img//caja3.bmp", 100, 350);
            drawProp(".//img//caja3.bmp", 200, 380);
            drawProp(".//img//caja3.bmp", 120, 400);
            drawProp(".//img//caja2.bmp", 290, 430);
            marraztuPuesto();
            drawProp(".//img//planta.bmp", 410, 200);
            drawProp(".//img//planta.bmp", 190, 170);
            soinua = 1;
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

            drawProp(".//img//barril.bmp", 150, 280);
            drawProp(".//img//planta.bmp", 250, 330);
            drawProp(".//img//caja3.bmp", 175, 330);

            drawProp(".//img//caja1.bmp", 300, 120);
            drawProp(".//img//planta.bmp", 300, 150);
            drawProp(".//img//barril.bmp", 240, 120);

            drawProp(".//img//caja3.bmp", 570, 125);
            drawProp(".//img//caja3.bmp", 660, 145);
            drawProp(".//img//caja3.bmp", 600, 170);
            drawProp(".//img//caja2.bmp", 620, 135);

            drawProp(".//img//barril.bmp", 750, 380);
            drawProp(".//img//barril.bmp", 690, 380);
           
            eki = 1;
            soinua = 1;
            break;
        case 2:
            //lobby 1
            background = loadMediaUnit(background, ".//img//sala_segura_1.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//sala_segura_1.bmp");

            drawProp(".//img//caja3.bmp", 240, 120);
            drawProp(".//img//planta.bmp", 175, 120);
            drawProp(".//img//caja1.bmp", 175, 180);
            
            drawProp(".//img//planta.bmp", 600, 70);
           
            drawProp(".//img//caja3.bmp", 175, 340);
            drawProp(".//img//planta.bmp", 235, 370);

            drawProp(".//img//caja3.bmp", 735, 330);
            drawProp(".//img//barril.bmp", 690, 310);
            drawProp(".//img//caja2.bmp", 730, 390);
            
            ipar = eki = mende = hego = 1;
            resetEnemies();
            resetMonedas();
            guardiaMarraztu();
            mezuaAgertu(MEZUA_ATEA_L1, 600, 385);
            mezuaAgertu(MEZUA_GUARDIA_L1, 0, 250);
            soinua = 1;
            break;
        case 3:
            //lobby 2
            background = loadMediaUnit(background, ".//img//sala_segura_1.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//sala_segura_1.bmp");

            drawProp(".//img//planta.bmp", 350, 120);
            drawProp(".//img//caja3.bmp", 280, 120);
            drawProp(".//img//barril.bmp", 250, 120);


            drawProp(".//img//barril.bmp", 275, 315);
            drawProp(".//img//planta.bmp", 235, 370);

            drawProp(".//img//caja1.bmp", 750, 330);
            drawProp(".//img//caja2.bmp", 720, 370);

            drawProp(".//img//barril.bmp", 680, 100);
            drawProp(".//img//barril.bmp", 745, 100);

            ipar = eki = mende = hego = 1;
            resetEnemies();
            resetMonedas();
            guardiaMarraztu();
            mezuaAgertu(MEZUA_ATEA_L2, 600, 385);
            soinua = 1;
            break;
        case 4:
            //final boss
            background = loadMediaUnit(background, ".//img//sala_final.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//sala_final.bmp");
            bossGela = 1;
            mende = 1;
            soinua = 2;
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
            drawProp(".//img//caja2.bmp", 170, 120);
            drawProp(".//img//barril.bmp", 117, 90);
            drawProp(".//img//caja2.bmp", 117, 180);
            drawProp(".//img//caja3.bmp", 820, 100);
            drawProp(".//img//barril.bmp", 900, 120);
            drawProp(".//img//planta.bmp", 840, 180);
            ipar = 1;
            enemigoGela = 1;
            break;
        case 3:
            //minijuegos 2
            background = loadMediaUnit(background, ".//img//cueva_v0.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//cueva_v0.bmp");
            drawProp(".//img//caja2.bmp", 170, 120);
            drawProp(".//img//barril.bmp", 117, 90);
            drawProp(".//img//caja2.bmp", 117, 180);
            drawProp(".//img//caja3.bmp", 820, 100);
            drawProp(".//img//barril.bmp", 900, 120);
            drawProp(".//img//planta.bmp", 840, 180);
            ipar = 1;
            enemigoGela = 2;
            break;
        }
        break;
    }
    musikaAldaketa(soinua);
}

void ateak()
{
    int ireki;
    if (posY < 250 && posY>190)
    {
        if (posX < 40)
        {
            mapaX -= 1;
            posX = 959;
        }
        if (posX > 961)
        {
            ireki = dialogoGuardia();
            if (ireki) {

                mapaX += 1;
                posX = 50;
            }
            else {
                posX = 956;
            }
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
