#include <SDL.h>
#include "marraztu.h"
#include "update.h"

int died = 0;
int gameOverQuit = 0;

extern SDL_Surface* bSalir;
extern SDL_Surface* gameOverTitulo;

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

    if (mouseX > 363 && mouseX < 363 + 354 && mouseY > 300 && mouseY < 364)
    {
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) gameOverQuit = 1;
    }
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
}