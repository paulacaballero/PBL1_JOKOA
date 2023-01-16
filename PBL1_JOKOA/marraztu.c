#include <SDL.h>
#include <SDL_ttf.h>

extern int t;

extern int mugitzen;

extern SDL_Window* window;
extern SDL_Surface* screenSurface;
extern SDL_Surface* playerP1;
extern SDL_Surface* playerP2;
extern SDL_Surface* playerP3;
extern SDL_Surface* playerP4;
extern SDL_Surface* playerP5;
extern SDL_Surface* playerP6;
extern SDL_Surface* background;
extern SDL_Surface* bala;
extern SDL_Surface* marko;
extern SDL_Surface* mezua;
extern SDL_Surface* fondomenu;
extern SDL_Surface* fondomenuCopy;

TTF_Font* font = NULL;
SDL_Color black = { 0, 0, 0 };

SDL_Rect player_posicion;
SDL_Rect bala_posicion;
SDL_Rect marko_posicion;

void irudiaMarraztu(SDL_Surface* irudia, SDL_Rect posizioa)
{
    SDL_BlitSurface(irudia, NULL, background, &posizioa);
    //SDL_UpdateWindowSurface(window);
}

void jokalariaMarraztu()
{
    if (mugitzen)
    {
        int pausoa = t % 30;
        if (pausoa < 5) irudiaMarraztu(playerP2, player_posicion);
        else if (pausoa < 10) irudiaMarraztu(playerP3, player_posicion);
        else if (pausoa < 15) irudiaMarraztu(playerP4, player_posicion);
        else if (pausoa < 20) irudiaMarraztu(playerP5, player_posicion);
        else if (pausoa < 25) irudiaMarraztu(playerP6, player_posicion);
        else irudiaMarraztu(playerP1, player_posicion);
    }
    else
    {
        irudiaMarraztu(playerP1, player_posicion);
    }
}
void alerta(char* textua)
{
    mezua = TTF_RenderText_Solid(font, textua, black);
    irudiaMarraztu(marko, marko_posicion);
    irudiaMarraztu(mezua, marko_posicion);
}
/*
void menuaMarraztu() {

    fondomenu = SDL_LoadBMP(".//img//bg.bmp");
    fondomenuCopy = SDL_LoadBMP(".//img//bg.bmp");
    //SDL_FreeSurface(fondomenu);
    //SDL_FreeSurface(fondomenuCopy);
}
void menua() {

    SDL_ShowCursor(SDL_ENABLE);
    menuaMarraztu();

}
*/
