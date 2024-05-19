#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Board.hpp"
#include "Partida.h"

class Renderizador
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    uint8_t scale = 75;

    void* partida;

    SDL_Texture* brancas, * negras;
    SDL_Color color1;
    SDL_Color color2;
    SDL_Color colorh;

    // DragNDrop
    Pecas pecaDragNDrop;

    SDL_Texture* carregarTextura(const char* path);
    void renderizaSprite(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst);
    void renderizaRetangulo(SDL_Rect* rec, SDL_Color* color);
    void desenhaPeca(Pecas peca, int x, int y, bool tabuleiro = true);
    void desenhaPecaDragMouse();
    void desenhaTodasPecas();
    void desenhaTabuleiro();

public:
    Renderizador(const char* title, void* partida, int largura, int altura);
    ~Renderizador();

    void RenderizaFrame();
};