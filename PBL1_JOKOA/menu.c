#include <SDL.h>
#include "marraztu.h"
#include "update.h";

extern int quit;
int menuQuit = 0;
extern SDL_Surface* titulo;
extern SDL_Surface* bStart;
extern SDL_Surface* bSalir;

int menuButtonState = 0;

int botoiPosX = 363;

void menuEvents()
{
    int mouseX, mouseY;
    SDL_Event e;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    Uint32 buttonState = SDL_GetMouseState(&mouseX, &mouseY);

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) quit = menuQuit = 1;
    }

    //if (keystates[SDL_SCANCODE_ESCAPE]) quit = menuQuit = 1;

    if (mouseX > botoiPosX && mouseX < botoiPosX + 354)
    {
        if (mouseY > 300 && mouseY < 364)
        {
            menuButtonState = 1;
            if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) menuQuit = 1;
        }
        else if (mouseY > 400 && mouseY < 464)
        {
            menuButtonState = 2;
            if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) menuQuit = quit = 1;
        }
        else menuButtonState = 0;
    }
    else menuButtonState = 0;
}

void tituloaMarraztu(int px, int py)
{
    SDL_Rect posizioa;
    posizioa.x = px;
    posizioa.y = py;

    irudiaMarraztu(titulo, posizioa);
}

//Botoiak marrazten ditu: 2 botoi daude "state" aldagaiak definitzen du botoi horietakoren batean hover
void botoiakMarraztu(int state)
{
    SDL_Rect bSalirPos;
    SDL_Rect bStartPos;

    bStartPos.x = botoiPosX;
    bStartPos.y = 300;
    bSalirPos.x = botoiPosX;
    bSalirPos.y = 400;

    switch (state)
    {
    case 1:
        bStartPos.x += 5;
        bStartPos.y -= 5;
        break;
    case 2:
        bSalirPos.x += 5;
        bSalirPos.y -= 5;
        break;
    }

    irudiaMarraztu(bStart, bStartPos);
    irudiaMarraztu(bSalir, bSalirPos);
}

void menuaMarraztu()
{
    tituloaMarraztu(349, 130);
    botoiakMarraztu(menuButtonState);
}

void menu()
{
    while (!menuQuit)
    {
        pantailaGarbitu();
        menuEvents();
        menuaMarraztu();
        pantailaBerriztu();
    }
}