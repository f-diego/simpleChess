#include "Renderizador.hpp"
#include "Pecas.h"

Renderizador::Renderizador(const char* title, void* partida, int largura, int altura)
{
    int wflags = SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largura, altura, wflags);
    if (!window)
        printf("Falha ao criar janela, erro: %s\n", SDL_GetError());
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);

    this->brancas = carregarTextura("defwh.png");
    this->negras = carregarTextura("defwh.png");

    this->color1 = { 52, 95, 117, 255 };
    this->color2 = { 164, 171, 189, 255 };
    this->colorh = { 0, 255, 0, 100 };
}

Renderizador::~Renderizador()
{
    this->destroiTela();
}

SDL_Texture* Renderizador::carregarTextura(const char* path)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, path);
    if (!texture)
        printf("Failed to load texture, error: %s\n", SDL_GetError());
    return texture;
}

void Renderizador::RenderizaFrame()
{
    limpaTela();
    desenhaTabuleiro();
    desenhaPecas();
    atualizaTela();
}

void Renderizador::destroiTela()
{
    SDL_DestroyWindow(window);
}

void Renderizador::limpaTela()
{
    SDL_RenderClear(renderer);
}

void Renderizador::renderizaSprite(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst)
{
    SDL_RenderCopy(renderer, texture, src, dst);
}

void Renderizador::desenhaPeca(int8_t piece, int x, int y)
{
    SDL_Texture* sprPiece;

    if (piece < 0) {
        sprPiece = negras;
        piece *= -1;
    }
    else {
        sprPiece = brancas;
    }

    SDL_Rect recorte = { 75 * (piece - 1), 0, 75, 75 };
    SDL_Rect destino = { scale + scale * x, scale + scale * y, scale, scale };
    renderizaSprite(sprPiece, &recorte, &destino);
}

void Renderizador::renderizaRetangulo(SDL_Rect* rect, SDL_Color* c)
{
    uint8_t r, g, b, a; //old color
    SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, c->a);
    SDL_RenderFillRect(renderer, rect);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    //SDL_FillRect(dst, r, (Uint32)((c->r << 16) + (c->g << 8) + (c->b << 0));
}

void Renderizador::desenhaPecas()
{
    desenhaPeca(Pecas::REI, 0, 0);
    return;
    for (uint8_t i = 0; i < 8; i++)
        desenhaPeca(i, i, i);
    for (uint8_t i = 0; i < 8; i++)
        desenhaPeca(i, 8 - i, i);
}


void Renderizador::desenhaTabuleiro()
{
    SDL_Rect quadrado = { 0, 0, scale, scale };
    for (uint8_t j = 0; j < 8; j++) {
        for (uint8_t i = 0; i < 8; i++) {
            quadrado.x = scale * i;
            quadrado.y = scale * j;
            //alternate colors
            renderizaRetangulo(&quadrado, ((i + j) % 2 == 0) ? &color1 : &color2);
        }
    }
}

void Renderizador::atualizaTela()
{
    SDL_RenderPresent(renderer);
}