#define _CRT_SECURE_NO_WARNINGS
#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "marraztu.h"
#include "inizializatu.h"
#include "update.h"
#include "colisiones.h"
#include "dirua.h"
#include "vida.h"
#include "huella.h"

extern SDL_Surface* markoS;
extern SDL_Surface* bMejorarArma;
extern SDL_Surface* bSalirArmero;
extern SDL_Surface* mejoraU;
extern SDL_Surface* mezua;
extern SDL_Surface* puestito;
extern SDL_Surface* mejoraArmaImagen;
extern SDL_Surface* mejoraVidaImagen;
extern TTF_Font* font;
extern SDL_Color black;
SDL_Color red = { 255, 0, 0 };

int armeroQuit = 0;
extern int quit, t, diruEKant, daño, hp, hpMax;

int nivelArma = 1;
int mejoraKostua = 10;
int azkenMejoraT = 0;

int nivelVida = 1;
int mejoraKostuaVida = 10;

extern int mapaX, mapaY;

void textuaIdatzi(char* txt, int px, int py)
{
    SDL_FreeSurface(mezua);
    mezua = TTF_RenderText_Solid(font, txt, black);
    zerbaitMarraztu(mezua, px, py);
}

void mejorarArma()
{
    nivelArma++;
    diruEKant -= mejoraKostua;
    mejoraKostua += 5;
    daño += 1;
}

void mejorarVida()
{
    nivelVida++;
    diruEKant -= mejoraKostuaVida;
    mejoraKostuaVida += 5;
    hpMax += 2;
    hp = hpMax;
}

void marraztuNivelMejora(int px, int py)
{
    int i;
    int nivelDeMejora;

    if (mapaX == 2) nivelDeMejora = nivelArma;
    else nivelDeMejora = nivelVida;

    mejoraU = loadMediaUnit(mejoraU, ".//img//mejoraU2.bmp");
    for (i = 0; i < nivelDeMejora; i++)
    {
        zerbaitMarraztu(mejoraU, px, py);
        px += 12;
    }

    mejoraU = loadMediaUnit(mejoraU, ".//img//mejoraU1.bmp");
    for (i = nivelDeMejora; i < 10; i++)
    {
        zerbaitMarraztu(mejoraU, px, py);
        px += 12;
    }
}

int armeroEvents()
{
    int mouseX, mouseY;
    SDL_Event e;
    Uint32 buttonState = SDL_GetMouseState(&mouseX, &mouseY);

    int state = 0;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) quit = armeroQuit = 1;
    }

    if (mouseX > 570 && mouseX < 570 + 61 && mouseY > 270 && mouseY < 331)
    {
        state = 1;
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT) && t - azkenMejoraT >= 30)
        {
            if (mapaX == 2 && diruEKant >= mejoraKostua && nivelArma < 10) mejorarArma();
            else if (mapaX == 3 && diruEKant >= mejoraKostuaVida && nivelVida < 10) mejorarVida();
            azkenMejoraT = t;
        }
    }
    else if (mouseX > 710 && mouseX < 771 && mouseY > 120 && mouseY < 181)
    {
        state = 2;
        if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT)) armeroQuit = 1;
    }
    else state = 0;

    return state;
}

void menuArmero()
{
    while (!armeroQuit)
    {
        pantailaGarbitu();
        switch (armeroEvents())
        {
        case 0:
            bMejorarArma = loadMediaUnit(bMejorarArma, ".//img//bMas1.bmp");
            bSalirArmero = loadMediaUnit(bSalirArmero, ".//img//bX1.bmp");
            break;
        case 1:
            bMejorarArma = loadMediaUnit(bMejorarArma, ".//img//bMas2.bmp");
            break;
        case 2:
            bSalirArmero = loadMediaUnit(bSalirArmero, ".//img//bX2.bmp");
            break;
        }
        zerbaitMarraztu(markoS, 290, 100);
        zerbaitMarraztu(bMejorarArma, 570, 270);
        textuaIdatzi("Zure dirua:", 330, 130);

        char txt[10];
        sprintf(txt, "%d", diruEKant);
        textuaIdatzi(txt, 550, 130);

        textuaIdatzi("Kostua:", 330, 280);

        if (mapaX == 2)
        {
            zerbaitMarraztu(mejoraArmaImagen, 477, 180);
            sprintf(txt, "%d", mejoraKostua);
        }
        else {
            zerbaitMarraztu(mejoraVidaImagen, 477, 180);
            sprintf(txt, "%d", mejoraKostuaVida);
        }

        textuaIdatzi(txt, 475, 280);
        zerbaitMarraztu(bSalirArmero, 710, 120);
        marraztuNivelMejora(650, 270);
        marraztuDirua();
        vidaMarraztu();
        huellaMarraztu();
        pantailaBerriztu();
        SDL_Delay(10);
        t++;
    }
}

void marraztuPuesto()
{
    int pausoa = t % 40;
    if (pausoa < 20) puestito = loadMediaUnit(puestito, ".//img//puestito1.bmp");
    else if (pausoa < 40) puestito = loadMediaUnit(puestito, ".//img//puestito2.bmp");
    zerbaitMarraztu(puestito, 270, 80);
    jokalariKolizioKarratua(290, 430, 100, 270);
}