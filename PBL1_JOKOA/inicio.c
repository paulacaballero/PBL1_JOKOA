#include "inicio.h"
#include "marraztu.h"
#include "update.h"
#include "inizializatu.h"
#include <SDL.h>

extern int quit;
int scriptQuit = 0;
int pageCount = 1;

extern SDL_Surface* fondoDialogo;
void scriptInicio()
{
    while (scriptQuit==0)
    {
        pantailaGarbitu();
        scriptEvents();
        script();
        pantailaBerriztu();
    }
}
void script() {
    
    switch (pageCount) {
    case 1:
        fondoDialogo = loadMediaUnit(fondoDialogo, ".//img//bombaNuclear.bmp");
        zerbaitMarraztu(fondoDialogo, 0, 0);
        alerta(DIAG1, 0, 358);
        break;
    case 2:
        fondoDialogo = loadMediaUnit(fondoDialogo, ".//img//fondoBunker.bmp");
        zerbaitMarraztu(fondoDialogo, 0, 0);
        alerta(DIAG2, 0, 358);
        break; 
    case 3:
        fondoDialogo = loadMediaUnit(fondoDialogo, ".//img//plantasPorMonedas.bmp");
        zerbaitMarraztu(fondoDialogo, 0, 0);
        alerta(DIAG3, 0, 358);
        break;
    case 4:
        fondoDialogo = loadMediaUnit(fondoDialogo, ".//img//fondoinicio.bmp");
        zerbaitMarraztu(fondoDialogo, 0, 0);
        alerta(DIAG4, 0, 358);
        break;
    }
    
    
}
void scriptEvents() {

    int mouseX, mouseY;
    SDL_Event e;
    Uint32 buttonState = SDL_GetMouseState(&mouseX, &mouseY);
    int state = 0;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT) quit = 1;
        if (e.type == SDL_MOUSEBUTTONDOWN) pageCount++;
    }
    if (pageCount == 5) {
        scriptQuit = 1;
    }
   
    
}