#include <SDL.h>
#include "mapak.h"

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int balakX[], balakY[], balakA[], balakDim,mapaX,mapaY;

extern int posX, posY;
int ipar;
int eki;
int mende;
int hego;
void balaKolizioak(int i)
{
    if (balakX[i] < 85 || balakX[i] > 980) balakA[i] = 0;
    else if (balakY[i] < 100 || balakY[i] > SCREEN_HEIGHT - 116) balakA[i] = 0;
}
void ateaDago() {

    ipar = eki = hego = mende = 0;
    switch (mapaY)
    {
    case 1:
        //dendak
        hego = 1;
        break;
    case 2:
        switch (mapaX)
        {
        case 1:
            //hasiera
            eki = 1;
            break;
        case 2:
            //lobby 1
            ipar = eki = hego = mende = 1;
            break;
        case 3:
            //lobby 2
            ipar = eki = hego = mende = 1;
            break;
        case 4:
            //final boss
            mende = 1;
            break;
        }

    case 3:
        switch (mapaX)
        {
            ipar = 1;
            break;
        }
    }

}
void jokalariKolizioak()
{
    ateaDago();
    if (posY > 250 || posY < 160) {
        if (posX < 100) posX += 5;
        if (posX > SCREEN_WIDTH - 170) posX -= 5;
        if (posX < 100) posX += 5;
        if (posX > SCREEN_WIDTH - 170) posX -= 5;
    }
    if (posX > 550 || posX < 480) {
        if (posY < 45) posY += 5;
        if(posY > SCREEN_HEIGHT - 215) posY -= 5;
    }
    /*
    if (posX < 100 && (posY > 250 ||  posY < 160)||gela.mende==1) posX += 5;
    if (posX > SCREEN_WIDTH - 170 && (posY > 250 || posY < 160)||gela.eki==1) posX -= 5;
    if (posY < 45&&(posX>550||posX<480)) posY += 5;
    if (posY > SCREEN_HEIGHT - 215 &&(posX > 550 || posX < 480)) posY -= 5;
    */
   
    ateak();
}
