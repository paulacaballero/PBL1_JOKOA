#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "gertaerak.h"
#include "tiroak.h"
#include "inizializatu.h"
#include "marraztu.h"
#include "update.h"
#include "menu.h"

extern int quit;
extern int t;
extern int start;

extern SDL_Rect player_posicion;

extern SDL_Surface *background;
extern SDL_Surface* backgroundCopy;


int main(int argc, char* args[])
{
    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
        close();
        return 0;
    }
    //Load media
    if (!loadMedia())
    {
        printf("Failed to load media!\n");
        close();
        return 0;
    }
   
    player_posicion.x = 300;
    player_posicion.y = 300;

    while (!quit)
    {
        /*
        *  while (!start) {
            handleEvents();
            menuaMarraztu();
        }
        */
       
        
        handleEvents();
        player_posicion = posizioaBerriztu(player_posicion);
        SDL_BlitSurface(backgroundCopy, NULL, background, NULL);
        jokalariaMarraztu();
        balakMugitu();
        balakMarraztu();
        pantailaBerriztu();
        SDL_Delay(10);
        t++;
    }

    close();

    return 0;
}
