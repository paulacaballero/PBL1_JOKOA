#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "soinua.h"

#define JOKOA_SOUND ".\\music\\main_theme.wav"

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int quit;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* playerP1 = NULL;
SDL_Surface* background = NULL;
SDL_Surface* backgroundCopy = NULL;
SDL_Surface* bala = NULL;
SDL_Surface* marko = NULL;
SDL_Surface* mezua = NULL;
SDL_Surface* enemigo_irudia = NULL;
SDL_Surface* bala_rota = NULL;

extern TTF_Font* font;
extern SDL_Rect player_posicion;
extern SDL_Rect marko_posicion;

SDL_Surface* loadMediaUnit(SDL_Surface* surface, char path[])
{
    SDL_FreeSurface(surface);
    surface = SDL_LoadBMP(path);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
    if (surface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        quit = 1;
    }

    return surface;
}

int init()
{
    int success = 1;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = 0;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = 0;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}

void close()
{
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_FreeSurface(playerP1);
    playerP1 = NULL;

    SDL_Quit();
}

int loadMedia()
{
    int success = 1;

    playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_1.bmp");
    bala = loadMediaUnit(bala, ".//img//bala_abajo.bmp");
    background = loadMediaUnit(background, ".//img//bg.bmp");
    backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//bg.bmp");
    enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//enemigo_zombi1.bmp");
    bala_rota = loadMediaUnit(bala_rota, ".//img//bala_rota.bmp");
    marko = loadMediaUnit(marko, ".//img//mezua.bmp");
    TTF_Init();
    font = TTF_OpenFont(".//fonts//sans.ttf", 24);
    if (font == NULL)
    {
        printf("Unable to load font Sans.ttf! SDL Error: %s\n", SDL_GetError());
        success = 0;
    }

    return success;
}
void inizializazioa(){
    if (!init())
    {
        printf("Failed to initialize!\n");
        quit = 1;
    }
    //Load media
    TTF_Init();
    if (!loadMedia())
    {
        printf("Failed to load media!\n");
        quit = 1;
    }
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();
    player_posicion.x = 300;
    player_posicion.y = 300;

    marko_posicion.x = 700;
    marko_posicion.y = 410;
}