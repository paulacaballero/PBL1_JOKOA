#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "gertaerak.h"
#include "tiroak.h"
#include "inizializatu.h"
#include "marraztu.h"
#include "update.h"
#include "enemigos.h";
#include "menu.h"
#include "vida.h"
#include "dirua.h"
#include "armero.h"
#include "huella.h"
#include "colisiones.h"
#include "gameOver.h"

extern int quit;
extern int t;

int main(int argc, char* args[])
{

    inizializazioa();
    menu();

    while (!quit)
    {
        pantailaGarbitu();

        handleEvents();

        monedakf();

        enemigoak();

        balakMugitu();
        balakMarraztu();

        jokalariaMarraztu();

        vidaMarraztu();

        huellaIgo();
        huellaMarraztu();

       

        pantailaBerriztu();

        SDL_Delay(10);
        t++;
    }

    gameOverScreen();
    close();

    return 0;
}
