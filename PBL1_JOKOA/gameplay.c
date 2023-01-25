#include <SDL.h>
#include "inizializatu.h"
#include "marraztu.h"
#include "update.h"

extern SDL_Surface* background;
extern SDL_Surface* backgroundCopy;
SDL_Surface* pasatuBotoia = NULL;

int azalpenX = 1;
int azalpenQuit = 0;

extern int quit, t, menuQuit;
extern int azkenMejoraT;

void gameplayEvents(int pasaEsk, int pasaEzk)
{
    int mouseX, mouseY;
    SDL_Event e;
    Uint32 buttonState = SDL_GetMouseState(&mouseX, &mouseY);

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) quit = azalpenQuit = menuQuit = 1;
    }

    if (mouseX > 10 && mouseX < 61 && mouseY > 279 && mouseY < 330 && pasaEzk && t - azkenMejoraT > 25)
    {
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) azalpenX -= 1;
        azkenMejoraT = t;
    }
    else if (mouseX > 1019 && mouseX < 1070 && mouseY > 279 && mouseY < 330 && pasaEsk && t - azkenMejoraT > 25)
    {
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) azalpenX += 1;
        azkenMejoraT = t;
    }

    if (azalpenX > 5)
    {
        background = loadMediaUnit(background, ".//img//fondo_menu.bmp");
        backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//fondo_menu.bmp");
        azalpenQuit = 1;
    }
}

void jolastenAzaldu()
{
    int pasaEzk, pasaEsk;
    azalpenQuit = 0;
    azalpenX = 1;
    while (!azalpenQuit)
    {
        pantailaGarbitu();

        pasaEsk = pasaEzk = 1;
        switch (azalpenX)
        {
        case 1:
            background = loadMediaUnit(background, ".//img//mugimenduaAzaldu.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//mugimenduaAzaldu.bmp");
            pasaEzk = 0;
            break;
        case 2:
            background = loadMediaUnit(background, ".//img//tiroakAzaldu.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//tiroakAzaldu.bmp");
            break;
        case 3:
            background = loadMediaUnit(background, ".//img//interakzioaAzaldu.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//interakzioaAzaldu.bmp");
            break;
        case 4:
            background = loadMediaUnit(background, ".//img//bizitzaAzaldu.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//bizitzaAzaldu.bmp");
            break;
        case 5:
            background = loadMediaUnit(background, ".//img//aztarnaAzaldu.bmp");
            backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//aztarnaAzaldu.bmp");
            break;
        }

        gameplayEvents(pasaEsk, pasaEzk);

        if (pasaEsk)
        {
            pasatuBotoia = loadMediaUnit(pasatuBotoia, ".//img//pasarSiguiente.bmp");
            zerbaitMarraztu(pasatuBotoia, 1019, 279);
        }

        if (pasaEzk)
        {
            pasatuBotoia = loadMediaUnit(pasatuBotoia, ".//img//pasarAnterior.bmp");
            zerbaitMarraztu(pasatuBotoia, 10, 279);
        }

        pantailaBerriztu();
        t++;
    }
}