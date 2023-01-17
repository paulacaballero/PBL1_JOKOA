#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "gertaerak.h"
#include "tiroak.h"
#include "inizializatu.h"
#include "marraztu.h"
#include "update.h"
#include "enemigos.h"
#include "colisiones.h"

extern int quit;
extern int t;

int main(int argc, char* args[])
{

    inizializazioa();

    while (!quit)
    {
        pantailaGarbitu();

        handleEvents();

        enemigoak();

        balakMugitu();
        balakMarraztu();

        jokalariaMarraztu();

        mezuaAgertu();

        pantailaBerriztu();

        SDL_Delay(10);
        t++;
    }
    close();

    return 0;
}
