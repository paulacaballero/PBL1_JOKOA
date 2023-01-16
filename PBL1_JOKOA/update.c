#include <SDL.h>

extern int posX, posY;

extern SDL_Surface *background;
extern SDL_Surface *screenSurface;
extern SDL_Surface *window;

SDL_Rect posizioaBerriztu(SDL_Rect posizioa)
{
    posizioa.x = posX;
    posizioa.y = posY;
    return posizioa;
}

void pantailaBerriztu()
{
    SDL_BlitSurface(background, NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface(window);
}