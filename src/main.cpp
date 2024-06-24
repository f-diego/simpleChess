#include <SDL.h>
#include <SDL_image.h>
#include "Partida.h"
#include "Renderizador.h"
#include "Entrada.h"

int main(int argv, char** args)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        printf("Falha em SDL_Init. Erro: %s\n", SDL_GetError());
    if (!(IMG_Init(IMG_INIT_PNG)))
        printf("Falha em IMG_init. Erro: %s\n", SDL_GetError());

    EstadoTabuleiro partida;
    setPosicaoInicial(&partida);

    Renderizador renderizador;
    inicializaRender(&renderizador, "", &partida, 600, 600);

    SDL_Event event;
    bool stopApp = false;
    
    while (!stopApp) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                stopApp = true;
                break;
            }

            ProcessaInput(&partida, &event);
            RenderizaFrame(&renderizador);
        }
    }

    SDL_Quit();
    return 0;
}