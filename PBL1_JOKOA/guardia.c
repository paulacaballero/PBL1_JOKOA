#include "guardia.h"
#include "inizializatu.h"
#include "marraztu.h"
#include "props.h"
#include "colisiones.h"
#include <SDL.h>

extern int enemigosKop;
extern int mapaY, mapaX;
extern int t;

SDL_Surface* guardia = NULL;

void guardiaMarraztu()
{
	int pausoa = t % 20;

	if (pausoa < 10) guardia = loadMediaUnit(guardia, ".//img//soldado1.bmp");
	else if (pausoa < 20) guardia = loadMediaUnit(guardia, ".//img//soldado2.bmp");

	if ((mapaX == 2 && enemigosKop < 100) || (mapaX == 3 && enemigosKop < 200)) {
		zerbaitMarraztu(guardia, 905, 255);
		jokalariKolizioKarratua(905, 965, 285, 330);
	}
	else {
		zerbaitMarraztu(guardia, 905, 180);
		jokalariKolizioKarratua(905, 965, 210, 240);
	}
	
}
int dialogoGuardia() {
	int ireki = 1;
	if (mapaX==2) {
		if (enemigosKop < 100) {
			ireki = 0;
			popup(ALERTALB1);
			alerta(ALERTALB1, 0, 250);
		}
	}
	if (mapaX == 3) {
		if (enemigosKop < 200) {
			ireki = 0;
			popup(ALERTALB2);
			alerta(ALERTALB2, 0, 250);
		}
	}

	return ireki;
}
void ateaBlokeatu(char* mezua) {
	alerta(mezua, 0, 250);
}