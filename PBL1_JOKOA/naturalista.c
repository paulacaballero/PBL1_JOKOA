#include <SDL.h>
#include "props.h"
#include "inizializatu.h"
#include "marraztu.h"
#include "armero.h"
#include "update.h"
#include "dirua.h"
#include "vida.h"
#include "huella.h"

SDL_Surface* naturalistaS = NULL;

extern int t, diruKant, diruEKant, quit, huellaCarbono;
extern SDL_Surface* markoS;
extern SDL_Surface* bSalirArmero;

SDL_Surface* bDonar = NULL;

int naturalistaQuit = 0;
int azkenDonazioaT = 0;

void naturalistaMarraztu()
{
    int pausoa = t % 20;

    if (pausoa < 10) naturalistaS = loadMediaUnit(naturalistaS, ".//img//naturalista1.bmp");
    else if (pausoa < 20) naturalistaS = loadMediaUnit(naturalistaS, ".//img//naturalista2.bmp");

    zerbaitMarraztu(naturalistaS, 700, 100);
}

void landareakAldatu()
{
    diruEKant += diruKant / 5;
    diruKant = diruKant % 5;
}

int naturalistaEvents()
{
    int mouseX, mouseY;
    SDL_Event e;
    Uint32 buttonState = SDL_GetMouseState(&mouseX, &mouseY);

    int state = 0;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) quit = naturalistaQuit = 1;
    }

    if (mouseX > 453 && mouseX < 453 + 173 && mouseY > 200 && mouseY < 264)
    {
        state = 1;
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT) && t - azkenDonazioaT >= 20 && diruEKant > 0&& huellaCarbono>0)
        {
            azkenDonazioaT = t;
            diruEKant -= 1;
            huellaCarbono -= 1;
        }
    }
    else if (mouseX > 710 && mouseX < 771 && mouseY > 120 && mouseY < 181)
    {
        state = 2;
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) naturalistaQuit = 1;
    }
    else if (mouseX > 453 && mouseX < 453 + 173 && mouseY > 360 && mouseY < 424)
    {
        state = 3;
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT) && t - azkenDonazioaT >= 20 && diruKant >= 5)
        {
            azkenDonazioaT = t;
            diruKant -= 5;
            diruEKant++;
        }
    }
    else state = 0;

    return state;
}

void menuNaturalista()
{
    int donarX, donarY, aldatuX, aldatuY;
    bDonar = loadMediaUnit(bDonar, ".//img//bDonar.bmp");
    while (!naturalistaQuit)
    {
        donarX = 453;
        donarY = 200;
        aldatuX = 453;
        aldatuY = 360;
        switch (naturalistaEvents())
        {
        case 0:
            bSalirArmero = loadMediaUnit(bSalirArmero, ".//img//bX1.bmp");
            break;
        case 1:
            donarX += 5;
            donarY -= 5;
            break;
        case 2:
            bSalirArmero = loadMediaUnit(bSalirArmero, ".//img//bX2.bmp");
            break;
        case 3:
            aldatuX += 5;
            aldatuY -= 5;
            break;
        }
        pantailaGarbitu();
        zerbaitMarraztu(markoS, 290, 100);
        zerbaitMarraztu(bSalirArmero, 710, 120);

        textuaIdatzi("Dirua eman zure CO2", 320, 120);
        textuaIdatzi("aztarna jaisteko:", 320, 150);
        zerbaitMarraztu(bDonar, donarX, donarY);

        textuaIdatzi("5 landare txanpon", 320, 280);
        textuaIdatzi("batengatik aldatu:", 320, 310);
        zerbaitMarraztu(bDonar, aldatuX, aldatuY);

        marraztuDirua();
        vidaMarraztu();
        huellaMarraztu();
        pantailaBerriztu();
        SDL_Delay(10);
        t++;
    }
}