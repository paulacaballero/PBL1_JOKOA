#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern int quit;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* playerP1 = NULL;
SDL_Surface* background = NULL;
SDL_Surface* backgroundCopy = NULL;
SDL_Surface* bala = NULL;
SDL_Surface* markoL = NULL;
SDL_Surface* markoS = NULL;
SDL_Surface* mezua = NULL;
SDL_Surface* enemigo_irudia = NULL;
SDL_Surface* bala_rota = NULL;
SDL_Surface* titulo = NULL;
SDL_Surface* bStart = NULL;
SDL_Surface* bSalir = NULL;
SDL_Surface* bMejorarArma = NULL;
SDL_Surface* bSalirArmero = NULL;
SDL_Surface* vidaU = NULL;
SDL_Surface* recuadroVida = NULL;
SDL_Surface* moneda = NULL;
SDL_Surface* monedaE = NULL;
SDL_Surface* mejoraU = NULL;
SDL_Surface* huellaU = NULL;
SDL_Surface* puestito = NULL;
SDL_Surface* mejoraArmaImagen = NULL;
SDL_Surface* gameOverTitulo = NULL;
SDL_Surface* fondoDialogo = NULL;
SDL_Surface* vidaUBoss = NULL;
SDL_Surface* mejoraVidaImagen = NULL;
SDL_Surface* bControls = NULL;

extern TTF_Font* font;
extern SDL_Rect player_posicion;
extern SDL_Rect marko_posicion;

SDL_Surface* loadMediaUnit(SDL_Surface* surface, char path[])
{
    SDL_FreeSurface(surface);
    surface = SDL_LoadBMP(path);
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
    if (surface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        quit = 1;
    }

    return surface;
}

int init()
{
    int success = 1;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = 0;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = 0;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}

void close()
{
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_FreeSurface(playerP1);
    playerP1 = NULL;

    SDL_Quit();
}

int loadMedia()
{
    int success = 1;

    playerP1 = loadMediaUnit(playerP1, ".//img//aurretik_1.bmp");
    bala = loadMediaUnit(bala, ".//img//bala_abajo.bmp");
    background = loadMediaUnit(background, ".//img//bg.bmp");
    backgroundCopy = loadMediaUnit(backgroundCopy, ".//img//bg.bmp");
    enemigo_irudia = loadMediaUnit(enemigo_irudia, ".//img//basura1.bmp");
    bala_rota = loadMediaUnit(bala_rota, ".//img//bala_rota.bmp");
    titulo = loadMediaUnit(titulo, ".//img//logo.bmp");
    bStart = loadMediaUnit(bStart, ".//img//botonStart.bmp");
    bSalir = loadMediaUnit(bSalir, ".//img//botonSalir.bmp");
    vidaU = loadMediaUnit(vidaU, ".//img//vida.bmp");
    recuadroVida = loadMediaUnit(recuadroVida, ".//img//recuadroVida.bmp");
    moneda = loadMediaUnit(moneda, ".//img//moneda.bmp");
    monedaE = loadMediaUnit(monedaE, ".//img//moneda4.bmp");
    bMejorarArma = loadMediaUnit(bMejorarArma, ".//img//bMas1.bmp");
    bSalirArmero = loadMediaUnit(bSalirArmero, ".//img//bX1.bmp");
    mejoraU = loadMediaUnit(mejoraU, ".//img//mejoraU2.bmp");
    huellaU = loadMediaUnit(huellaU, ".//img//huellaU.bmp");
    puestito = loadMediaUnit(puestito, ".//img//puestito1.bmp");
    mejoraArmaImagen = loadMediaUnit(mejoraArmaImagen, ".//img//mejoraArmaImagen.bmp");
    gameOverTitulo = loadMediaUnit(gameOverTitulo, ".//img//gameOver.bmp");
    markoL = loadMediaUnit(markoL, ".//img//dialogo2.bmp");
    markoS = loadMediaUnit(markoS, ".//img//marco_v0.bmp");
    fondoDialogo = loadMediaUnit(fondoDialogo, ".//img//fondoinicio.bmp");
    mejoraVidaImagen = loadMediaUnit(mejoraVidaImagen, ".//img//mejora_vida.bmp");
    bControls = loadMediaUnit(bControls, ".//img//botonControls.bmp");
    vidaUBoss = loadMediaUnit(vidaUBoss, ".//img//vidaUBoss.bmp");
    font = TTF_OpenFont(".//fonts//sans.ttf", 35);

    if (font == NULL)
    {
        printf("Unable to load font Sans.ttf! SDL Error: %s\n", SDL_GetError());
        success = 0;
    }

    return success;
}

void inizializazioa()
{
    if (!init())
    {
        printf("Failed to initialize!\n");
        quit = 1;
    }
    //Load media
    TTF_Init();
    if (!loadMedia())
    {
        printf("Failed to load media!\n");
        quit = 1;
    }

    player_posicion.x = 590;
    player_posicion.y = 304;

    marko_posicion.x = 300;
    marko_posicion.y = 300;
}