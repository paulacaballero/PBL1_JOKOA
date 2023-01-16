#include <SDL.h>
#include "colisiones.h"
#include "mapak.h"

#define BLOCKED_DOOR "Ate hau itxita dago. Giltza nonbait egon beharko du..."

extern const int SCREEN_HEIGHT, SCREEN_WIDTH;
extern SDL_Window* window;
int posX = 300;
int posY = 300;
int quit = 0;
int start = 0;
int abiadura = 3;
int mugitzen = 0;
int tiro = 0;
int t = 0;
int azkenTiroT = 0;

enum direkzioak { BEHERA, GORA, EZK, ESK };
int player_dir = BEHERA;

void tiroEgin(int direkzioa);

void handleEvents()
{
    SDL_Event e;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    SDL_Rect mouse;
    SDL_GetMouseState(&mouse.x, &mouse.y);
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) quit = 1;
        /*
         if (start==0) {
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if ((mouse.x > 420 && mouse.x < 675)&&(mouse.y>257&&mouse.y<335)) {
                    start = 1;
                }
            }
        }
        */
       
    }

    if (keystates[SDL_SCANCODE_ESCAPE]) quit = 1;

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
    }
    else if (keystates[SDL_SCANCODE_DOWN] && tiro)
    {
        tiroEgin(BEHERA);
        tiro = 0;
        azkenTiroT = t;
    }
    else if (keystates[SDL_SCANCODE_LEFT] && tiro)
    {
        tiroEgin(EZK);
        tiro = 0;
        azkenTiroT = t;
    }
    else if (keystates[SDL_SCANCODE_RIGHT] && tiro)
    {
        tiroEgin(ESK);
        tiro = 0;
        azkenTiroT = t;
    }

    if (t - azkenTiroT >= 15) tiro = 1;
}
