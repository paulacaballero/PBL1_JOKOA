#include <SDL.h>

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;

extern SDL_Surface* fondomenu;
extern SDL_Surface* fondomenuCopy;
/*
*/
void menuaMarraztu() {
	SDL_FreeSurface(fondomenu);
	SDL_FreeSurface(fondomenuCopy);
	fondomenu = SDL_LoadBMP(".//img//menuprueba.bmp");
	fondomenuCopy = SDL_LoadBMP(".//img//menuprueba.bmp");
	
}
void menua() {

	SDL_ShowCursor(SDL_ENABLE);
	menuaMarraztu();
	
}