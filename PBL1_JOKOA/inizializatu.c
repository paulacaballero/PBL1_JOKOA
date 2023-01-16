#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int quit;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* playerP1 = NULL;
SDL_Surface* playerP2 = NULL;
SDL_Surface* playerP3 = NULL;
SDL_Surface* playerP4 = NULL;
SDL_Surface* playerP5 = NULL;
SDL_Surface* playerP6 = NULL;
SDL_Surface* background = NULL;
SDL_Surface* backgroundCopy = NULL;
SDL_Surface* bala = NULL;
SDL_Surface* marko = NULL;
SDL_Surface* mezua = NULL;
SDL_Surface* fondomenu = NULL;
SDL_Surface* fondomenuCopy = NULL;

extern TTF_Font *font;

SDL_Surface* loadMediaUnit(SDL_Surface* surface, char path[])
{
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
    //Loading success flag
    int success = 1;

    //Load splash image
    playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_1.bmp");
    playerP2 = loadMediaUnit(playerP2, ".//img//aurretik_2.bmp");
    playerP3 = loadMediaUnit(playerP3, ".//img//aurretik_3.bmp");
    playerP4 = loadMediaUnit(playerP4, ".//img//aurretik_4.bmp");
    playerP5 = loadMediaUnit(playerP5, ".//img//aurretik_5.bmp");
    playerP6 = loadMediaUnit(playerP6, ".//img//aurretik_6.bmp");
    bala = loadMediaUnit(bala, ".//img//bala.bmp");
    background = loadMediaUnit(background, ".//img//bg.bmp");
    backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//bg.bmp");
    fondomenu = loadMediaUnit(fondomenu, ".//img//menuprueba.bmp");
    fondomenuCopy = loadMediaUnit(fondomenuCopy, ".//img//menuprueba.bmp");

    TTF_Init();
    font = TTF_OpenFont(".//fonts//sans.ttf", 24);
    if (font == NULL)
    {
        printf("Unable to load font Sans.ttf! SDL Error: %s\n", SDL_GetError());
        success = 0;
    }

    return success;
}