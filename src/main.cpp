#include <SDL.h>
#include <SDL_image.h>
#include "Renderizador.hpp"
#include "Board.hpp"

int main(int argv, char** args)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        printf("Falha em SDL_Init. Erro: %s\n", SDL_GetError());
    if (!(IMG_Init(IMG_INIT_PNG)))
        printf("Falha em IMG_init. Erro: %s\n", SDL_GetError());

    Partida* partida = new Partida();
    Renderizador* renderizador = new Renderizador("Partida", partida, 600, 600);

    bool appRodando = true;
    SDL_Event event;

    while (appRodando) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                appRodando = false;
            }
        }
        renderizador->RenderizaFrame();
    }

    delete renderizador;
    delete partida;
    SDL_Quit();
    return 0;
}