#include <SDL.h>

int mapaX = 1;
int mapaY = 2;

extern SDL_Surface* background;
extern SDL_Surface* backgroundCopy;

extern int posX, posY;
int ipar=0, eki = 0,mende = 0,hego = 0;



void mapak()
{
    SDL_FreeSurface(background);
    SDL_FreeSurface(backgroundCopy);
    switch (mapaY)
    {
    case 1:
        //dendak
        switch (mapaX)
        {
        case 2:
            background = SDL_LoadBMP(".//img//bg.bmp");
         
            backgroundCopy = SDL_LoadBMP(".//img//bg.bmp");
            
            hego = 1;
            break;
        case 3:
            background = SDL_LoadBMP(".//img//bg.bmp");
            
            backgroundCopy = SDL_LoadBMP(".//img//bg.bmp");
            
            hego = 1;
            break;
        }
    case 2:
        switch (mapaX)
        {
        case 1:
            //hasiera
            background = SDL_LoadBMP(".//img//bg.bmp");
            backgroundCopy = SDL_LoadBMP(".//img//bg.bmp");
            eki = 1;
            break;
        case 2:
            //lobby 1
            background = SDL_LoadBMP(".//img//sala_segura_1.bmp");
            if (background == NULL)
            {
                printf("Unable to load image bg.bmp! SDL Error: %s\n", SDL_GetError());
            }

            backgroundCopy = SDL_LoadBMP(".//img//sala_segura_1.bmp");
            if (backgroundCopy == NULL)
            {
                printf("Unable to load image bg.bmp! SDL Error: %s\n", SDL_GetError());
            }
            ipar = eki = mende = hego = 1;
            break;
        case 3:
            //lobby 2
            background = SDL_LoadBMP(".//img//sala_segura_1.bmp");
            backgroundCopy = SDL_LoadBMP(".//img//sala_segura_1.bmp");
           
            ipar = eki = mende = hego = 1;
            break;
        case 4:
            //final boss
            mende = 1;
            break;
        }

    case 3:
        switch (mapaX)
        {
        case 2:
            //minijuegos 1
            ipar = 1;
            break;
        case 3:
            //minijuegos 2
            ipar = 1;
            break;
        }
    }


}
/*
int ateak() {
    if (posY >= 200 && posY <= 250) {
        if (mapaX != 1 && mapaY != 1 && mapaY != 3) {
            //puerta izquierda
            if (posX <= 100) {
                mapaX -= 1;
                posX = 900;
                return 1;
            }
        }
        if (mapaY != 1 && mapaY != 4) {
            //puerta derecha
            //if (!giltza) popup(BLOCKED_DOOR); else{
            if (posX >= 910) {
                mapaX += 1;
                posX = 110;
                return 1;
            }
        }
    }

    if (posX >= 480 && posX <= 550) {
        if (mapaX != 1) {
            if (mapaY != 1) {
                //puerta arriba
                if (posY <= 50) {
                    mapaY -= 1;
                    posY = 380;
                    return 1;
                }
            }
            if (mapaY != 3) {
                //puerta abajo
                if (posY >= 388) {
                    mapaY += 1;
                    posY = 60;
                    return 1;
                }
            }
        }
    }
    mapak();

    return 0;
}

*/


void ateak()
{
    if (posY < 250 && posY>200)
    {
        if (posX < 70)
        {
            mapaX -= 1;
            posX = 908;
        }
        if (posX > 940)
        {
            mapaX += 1;
            posX = 102;
        }
    }
    if (posX < 550 && posX>480)
    {
        if (posY < 20)
        {
            mapaY -= 1;
            posY = 390;
        }
        if (posY > 420)
        {
            mapaY += 1;
            posY = 102;
        }
    }
    mapak();
}
