#include "Renderizador.h"

SDL_Texture* carregarTextura(SDL_Renderer* renderer, const char* path);
void desenhaRetangulo(Renderizador* renderizador, SDL_Rect* rec, SDL_Color* color);
void desenhaPeca(Renderizador* renderizador, Peca peca, int x, int y, bool tabuleiro = true);
void desenhaPecaDragMouse(Renderizador*);
void desenhaPecasTabuleiro(Renderizador* renderizador);
void desenhaTabuleiro(Renderizador* renderizador);

void inicializaRender(Renderizador* renderizador, const char* title, EstadoTabuleiro* partida, int largura, int altura)
{
    int wflags = SDL_WINDOW_SHOWN;
    renderizador->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largura, altura, wflags);
    if (!renderizador->window)
        printf("Falha ao criar janela, erro: %s\n", SDL_GetError());
    renderizador->sdlRenderer = SDL_CreateRenderer(renderizador->window, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);

    renderizador->brancas = carregarTextura(renderizador->sdlRenderer, "defwh.png");
    renderizador->negras = carregarTextura(renderizador->sdlRenderer, "defbka.png");
    renderizador->color1 = { 52, 95, 117, 255 };
    renderizador->color2 = { 164, 171, 189, 255 };
    renderizador->colorh = { 0, 255, 0, 100 };

    renderizador->partida = partida;
}

void encerra(Renderizador* renderizador) {
    SDL_DestroyWindow(renderizador->window);
}

SDL_Texture* carregarTextura(SDL_Renderer* renderer, const char* path)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, path);
    if (!texture)
        printf("Failed to load texture, error: %s\n", SDL_GetError());
    return texture;
}

void RenderizaFrame(Renderizador* renderizador)
{
    SDL_RenderClear(renderizador->sdlRenderer);
    desenhaTabuleiro(renderizador);
    desenhaPecasTabuleiro(renderizador);
    desenhaPecaDragMouse(renderizador);
    SDL_RenderPresent(renderizador->sdlRenderer);
}

void desenhaPeca(Renderizador* renderizador, Peca peca, int x, int y, bool tabuleiro)
{
    if (peca == VAZIO) 
        return;

    int scale = renderizador->scale;
    bool negras = (peca < 0);
    SDL_Rect destino;
    SDL_Texture* pieceTexture = negras ? renderizador->negras : renderizador->brancas;

    int xRecorteSprite = (int)peca * ((negras ? -1 : 1));

    SDL_Rect recorteSprite = { 75 * (xRecorteSprite - 1), 0, 75, 75 };

    if (tabuleiro) {
        destino = { scale * x, scale * y, scale, scale };
    }
    else {
        destino = { x - scale / 2, y - scale / 2, scale, scale };
    }

    SDL_RenderCopy(renderizador->sdlRenderer, pieceTexture, &recorteSprite, &destino);
}

void desenhaPecasTabuleiro(Renderizador* renderizador)
{
    for (int i = 0; i < 64; i++)
    {
        desenhaPeca(renderizador, renderizador->partida->posicao->Pecas[i], i % 8, i / 8);
    }
}

void desenhaPecaDragMouse(Renderizador* renderizador)
{
    EstadoTabuleiro* estado = renderizador->partida;

    desenhaPeca(renderizador, estado->pecaDragNDrop, estado->dragNDrop.x, estado->dragNDrop.y, false);
}

void desenhaRetangulo(Renderizador* renderizador, SDL_Rect* rect, SDL_Color* c)
{
    uint8_t r, g, b, a; //old color
    SDL_GetRenderDrawColor(renderizador->sdlRenderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(renderizador->sdlRenderer, c->r, c->g, c->b, c->a);
    SDL_RenderFillRect(renderizador->sdlRenderer, rect);
    SDL_SetRenderDrawColor(renderizador->sdlRenderer, r, g, b, a);
    //SDL_FillRect(dst, r, (Uint32)((c->r << 16) + (c->g << 8) + (c->b << 0));
}

void desenhaTabuleiro(Renderizador* renderizador)
{
    int scale = renderizador->scale;
    SDL_Rect quadrado = { 0, 0, scale, scale };
    for (uint8_t j = 0; j < 8; j++) {
        for (uint8_t i = 0; i < 8; i++) {
            quadrado.x = scale * i;
            quadrado.y = scale * j;
            //alterna cores
            desenhaRetangulo(renderizador, &quadrado, 
                ((i + j) % 2 == 0) 
                    ? &renderizador->color1 
                    : &renderizador->color2
            );
        }
    }
}