#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "colisiones.h"
#include "mapak.h"
#include "marraztu.h"
#include "update.h"
#include "tiroak.h"
#include "soinua.h"
#include "armero.h"
#include "menu.h"
#include "guardia.h"
#include "naturalista.h"


extern const int SCREEN_HEIGHT, SCREEN_WIDTH;

int posX = 510;
int posY = 240;
int quit = 0;
int abiadura = 3;
int mugitzen = 0;
int tiro = 0;
int t = 0;
int azkenTiroT = 0;

enum direkzioak { BEHERA, GORA, EZK, ESK };
int player_dir = BEHERA;

extern int menuQuit;
extern int mapaY, mapaX;
extern int armeroQuit;
extern int naturalistaQuit, enemigosKop;
extern int monedaKant;

extern SDL_Surface* background;
extern SDL_Surface* backgroundCopy;
extern SDL_Surface* markoS;
extern SDL_Surface* mezua;
extern TTF_Font* font;
extern SDL_Color black;
extern SDL_Rect testua_posicion;

void handleEvents()
{
    SDL_Event e;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) quit = 1;
    }

    if (keystates[SDL_SCANCODE_P]) {
        enemigosKop += 100;
    }
    if (keystates[SDL_SCANCODE_O]) {
        monedaKant += 100;
    }
    if (keystates[SDL_SCANCODE_ESCAPE])
    {
        menuQuit = 0;
        menu();
    }
    mugitzen = 0;

    if (keystates[SDL_SCANCODE_W])
    {
        posY -= abiadura;
        player_dir = GORA;
        mugitzen = 1;
    }
    else if (keystates[SDL_SCANCODE_S])
    {
        posY += abiadura;
        player_dir = BEHERA;
        mugitzen = 1;
    }

    if (keystates[SDL_SCANCODE_A])
    {
        posX -= abiadura;
        player_dir = EZK;
        mugitzen = 1;
    }
    else if (keystates[SDL_SCANCODE_D])
    {
        posX += abiadura;
        player_dir = ESK;
        mugitzen = 1;
    }
    jokalariKolizioak();
    if (keystates[SDL_SCANCODE_UP] && tiro)
    {
        tiroEgin(GORA);
        tiro = 0;
        azkenTiroT = t;
        soinuaDisparo();
    }
    else if (keystates[SDL_SCANCODE_DOWN] && tiro)
    {
        tiroEgin(BEHERA);
        tiro = 0;
        azkenTiroT = t;
        soinuaDisparo();
    }
    else if (keystates[SDL_SCANCODE_LEFT] && tiro)
    {
        tiroEgin(EZK);
        tiro = 0;
        azkenTiroT = t;
        soinuaDisparo();
    }
    else if (keystates[SDL_SCANCODE_RIGHT] && tiro)
    {
        tiroEgin(ESK);
        tiro = 0;
        azkenTiroT = t;
        soinuaDisparo();
    }

    if (t - azkenTiroT >= 15) tiro = 1;
    if (mapaY == 1)
    {
        if (posX + 59 > 290 && posX + 7 < 430 && posY + 51 < 300 && posY + 100 > 270)
        {
            if (keystates[SDL_SCANCODE_F])
            {
                armeroQuit = 0;
                SDL_BlitSurface(background, NULL, backgroundCopy, NULL);
                menuArmero();
            }
        }
        else if (posX + 59 > 700 && posX + 7 < 780 && posY + 51 < 200 && posY + 100 > 180)
        {
            if (keystates[SDL_SCANCODE_F])
            {
                naturalistaQuit = 0;
                SDL_BlitSurface(background, NULL, backgroundCopy, NULL);
                menuNaturalista();
            }
        }
    }
    else if (mapaY == 2 && ((mapaX == 2 && enemigosKop < 100) || (mapaX == 3 && enemigosKop < 200)))
    {
        if (posY + 80 > 285 && posY + 80 < 330 && posX + 38 > 855 && posX + 38 < 905)
        {
            if (keystates[SDL_SCANCODE_F])
            {

                zerbaitMarraztu(markoS, 290, 100);
                testua_posicion.x = 350;
                testua_posicion.y = 170;
                if (mapaX == 2) {
                    mezua = TTF_RenderText_Solid_Wrapped(font, MEZUA_GUARDIA_L1, black, 440);
                }
                if (mapaX == 3) {
                    mezua = TTF_RenderText_Solid_Wrapped(font, MEZUA_GUARDIA_L2, black, 500);
                }
                irudiaMarraztu(mezua, testua_posicion);
                char txt[20];
                sprintf(txt, "Hartu dituzu: %d", enemigosKop);
                textuaIdatzi(txt, 350, 370);
                jokalariaMarraztu();
                pantailaBerriztu();
                SDL_Delay(2000);
            }
        }
    }
}
