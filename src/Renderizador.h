#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Partida.h"

typedef struct Renderizador {
    SDL_Window* window;
    SDL_Renderer* sdlRenderer;
    EstadoTabuleiro* partida;
    uint8_t scale = 75;
    SDL_Texture *brancas, *negras;

    SDL_Color color1;
    SDL_Color color2;
    SDL_Color colorh;
} Renderizador;

void inicializaRender(Renderizador* renderizador, const char* title, EstadoTabuleiro* partida, int largura, int altura);
void RenderizaFrame(Renderizador* renderizador);
