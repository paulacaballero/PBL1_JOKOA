#include <SDL.h>
#include <SDL_ttf.h>
#include "inizializatu.h"
#include "update.h"
extern int t;

extern int mugitzen;

extern int t;

extern int mugitzen, player_dir;

extern SDL_Window* window;
extern SDL_Surface* screenSurface;
extern SDL_Surface* playerP1;
extern SDL_Surface* background;
extern SDL_Surface* bala;
extern SDL_Surface* marko;
extern SDL_Surface* mezua;
extern SDL_Surface* backgroundCopy;
extern SDL_Surface* bala_rota;

extern SDL_Surface* fondomenu;
extern SDL_Surface* fondomenuCopy;

TTF_Font* font = NULL;
SDL_Color black = { 0, 0, 0 };

SDL_Rect player_posicion;
SDL_Rect bala_posicion;
SDL_Rect marko_posicion;

enum direkzioak { BEHERA, GORA, EZK, ESK };

void irudiaMarraztu(SDL_Surface* irudia, SDL_Rect posizioa)
{
    SDL_BlitSurface(irudia, NULL, background, &posizioa);
    //SDL_UpdateWindowSurface(window);
}

void jokalariaMarraztu()
{
    player_posicion = posizioaBerriztu(player_posicion);
    switch (player_dir)
    {
    case ESK:
        if (mugitzen)
        {
            int pausoa = t % 30;
            if (pausoa < 5) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_1.bmp");
            else if (pausoa < 10) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_2.bmp");
            else if (pausoa < 15) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_3.bmp");
            else if (pausoa < 20) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_4.bmp");
            else if (pausoa < 25) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_5.bmp");
            else if (pausoa < 30) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_6.bmp");
        }
        else
        {
            playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_1.bmp");
        }
        break;
    case EZK:
        if (mugitzen)
        {
            int pausoa = t % 30;
            if (pausoa < 5) playerP1 = loadMediaUnit(playerP1, ".//img//e_aurretik_1.bmp");
            else if (pausoa < 10) playerP1 = loadMediaUnit(playerP1, ".//img//e_aurretik_2.bmp");
            else if (pausoa < 15) playerP1 = loadMediaUnit(playerP1, ".//img//e_aurretik_3.bmp");
            else if (pausoa < 20) playerP1 = loadMediaUnit(playerP1, ".//img//e_aurretik_4.bmp");
            else if (pausoa < 25) playerP1 = loadMediaUnit(playerP1, ".//img//e_aurretik_5.bmp");
            else if (pausoa < 30) playerP1 = loadMediaUnit(playerP1, ".//img//e_aurretik_6.bmp");
        }
        else
        {
            playerP1 = loadMediaUnit(playerP1, ".//img//e_aurretik_1.bmp");
        }
        break;
    case BEHERA:
        if (mugitzen)
        {
            int pausoa = t % 30;
            if (pausoa < 5) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_1.bmp");
            else if (pausoa < 10) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_2.bmp");
            else if (pausoa < 15) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_3.bmp");
            else if (pausoa < 20) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_4.bmp");
            else if (pausoa < 25) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_5.bmp");
            else if (pausoa < 30) playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_6.bmp");
        }
        else
        {
            playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_1.bmp");
        }
        break;
    case GORA:
        if (mugitzen)
        {
            int pausoa = t % 25;
            if (pausoa < 5) playerP1 = loadMediaUnit(playerP1, ".//img//gora1.bmp");
            else if (pausoa < 10) playerP1 = loadMediaUnit(playerP1, ".//img//gora2.bmp");
            else if (pausoa < 15) playerP1 = loadMediaUnit(playerP1, ".//img//gora3.bmp");
            else if (pausoa < 20) playerP1 = loadMediaUnit(playerP1, ".//img//gora4.bmp");
            else if (pausoa < 25) playerP1 = loadMediaUnit(playerP1, ".//img//gora5.bmp");
        }
        else
        {
            playerP1 = loadMediaUnit(playerP1, ".//img//gora1.bmp");
        }
        break;
    }
    irudiaMarraztu(playerP1, player_posicion);
}
void alerta(char* textua)
{
    //marko = SDL_LoadBMP(".//img//mezua.bmp");
    marko = loadMediaUnit(marko, ".//img//mezua(1).bmp");
    mezua = TTF_RenderText_Solid(font, textua, black);

    irudiaMarraztu(mezua, marko_posicion);
    irudiaMarraztu(marko, marko_posicion);
  
    
    
}
void pantailaGarbitu()
{
    SDL_BlitSurface(backgroundCopy, NULL, background, NULL);
}
void balaKolizioAnimazioa(int px, int py)
{
    SDL_Rect posicion;
    posicion.x = px;
    posicion.y = py;

    irudiaMarraztu(bala_rota, posicion);
}

