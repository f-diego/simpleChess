#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameState.h"

class Renderizador
{
private:
    SDL_Window* window;
    SDL_Renderer* sdlRenderer;
    GameState& partida;
    uint8_t scale = 75;
    SDL_Texture* brancas, * negras;

    SDL_Color color1;
    SDL_Color color2;
    SDL_Color colorh;

    SDL_Texture* carregarTextura(const char* path);
    void desenhaRetangulo(SDL_Rect* rec, SDL_Color* color);
    void desenhaPeca(Piece* peca, int x, int y, bool tabuleiro = true);
    void desenhaPecaDragMouse();
    void desenhaPecasTabuleiro();
    void desenhaTabuleiro();

public:
	Renderizador(const char* title, GameState& partida, int largura, int altura);
	~Renderizador();

    void RenderizaFrame();
};

Renderizador::Renderizador(const char* title, GameState& partida, int largura, int altura)
{
    int wflags = SDL_WINDOW_SHOWN;
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largura, altura, wflags);
    if (!this->window)
        printf("Falha ao criar janela, erro: %s\n", SDL_GetError());
    this->sdlRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);

    this->brancas = carregarTextura("defwh.png");
    this->negras = carregarTextura("defbka.png");
    this->color1 = { 52, 95, 117, 255 };
    this->color2 = { 164, 171, 189, 255 };
    this->colorh = { 0, 255, 0, 100 };

    this->partida = partida;
}

Renderizador::~Renderizador()
{
    SDL_DestroyWindow(this->window);
}

