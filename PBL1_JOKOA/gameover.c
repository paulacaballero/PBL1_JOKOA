#include <SDL.h>
#include "marraztu.h"
#include "update.h"
#include "inizializatu.h"

int died = 0;
int gameOverQuit = 0;

extern SDL_Surface* bSalir;
extern SDL_Surface* gameOverTitulo;
extern SDL_Surface* background;
extern SDL_Surface* backgroundCopy;

extern int final;

void gameOverEvents()
{
    int mouseX, mouseY;
    SDL_Event e;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    Uint32 buttonState = SDL_GetMouseState(&mouseX, &mouseY);

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) gameOverQuit = 1;
    }

    if (keystates[SDL_SCANCODE_ESCAPE]) gameOverQuit = 1;
    if (keystates[SDL_SCANCODE_RETURN]) gameOverQuit = 1;
    if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) gameOverQuit = 1;
}

void gameOverScreen()
{
    if (died)
    {
        while (!gameOverQuit)
        {
            pantailaGarbitu();
            gameOverEvents();
            zerbaitMarraztu(gameOverTitulo, 357, 200);
            pantailaBerriztu();
        }
    }
    else if (final)
    {
        while (!gameOverQuit)
        {
            pantailaGarbitu();
            gameOverEvents();
            switch (final)
            {
            case 1:
                background = loadMediaUnit(background, ".//img//finalMalo.bmp");
                backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//finalMalo.bmp");
                break;
            case 2:
                background = loadMediaUnit(background, ".//img//finalBueno.bmp");
                backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//finalBueno.bmp");
                break;
            }
            pantailaBerriztu();
        }
    }
}
