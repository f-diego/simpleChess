#include "Renderizador.h"

void Renderizador::RenderizaFrame()
{
    SDL_RenderClear(this->sdlRenderer);
    desenhaTabuleiro();
    desenhaPecasTabuleiro();
    desenhaPecaDragMouse();
    SDL_RenderPresent(this->sdlRenderer);
}

SDL_Texture* Renderizador::carregarTextura(const char* path)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(this->sdlRenderer, path);
    if (!texture)
        printf("Failed to load texture, error: %s\n", SDL_GetError());
    return texture;
}

void Renderizador::desenhaPeca(Piece* peca, int x, int y, bool tabuleiro)
{
    if (peca == nullptr) 
        return;

    SDL_Rect destino;
    SDL_Texture* pieceTexture = (peca->color == PieceColor::WHITE) ? this->brancas : this->negras ;

    int xRecorteSprite = (int)peca->shape;
    SDL_Rect recorteSprite = { 75 * (xRecorteSprite - 1), 0, 75, 75 };

    if (tabuleiro) {
        destino = { scale * x, scale * y, scale, scale };
    }
    else {
        destino = { x - scale / 2, y - scale / 2, scale, scale };
    }

    SDL_RenderCopy(this->sdlRenderer, pieceTexture, &recorteSprite, &destino);
}

void Renderizador::desenhaPecasTabuleiro()
{
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            desenhaPeca(this->partida.PosicaoAtual().getPieceAt(x, y), x, y);
}

void Renderizador::desenhaPecaDragMouse()
{
    desenhaPeca(this->partida.pecaDragNDrop, this->partida.dragNDrop.x, this->partida.dragNDrop.y, false);
}

void Renderizador::desenhaRetangulo(SDL_Rect* rect, SDL_Color* c)
{
    uint8_t r, g, b, a; //old color
    SDL_GetRenderDrawColor(this->sdlRenderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(this->sdlRenderer, c->r, c->g, c->b, c->a);
    SDL_RenderFillRect(this->sdlRenderer, rect);
    SDL_SetRenderDrawColor(this->sdlRenderer, r, g, b, a);
    //SDL_FillRect(dst, r, (Uint32)((c->r << 16) + (c->g << 8) + (c->b << 0));
}

void Renderizador::desenhaTabuleiro()
{
    SDL_Rect quadrado = { 0, 0, scale, scale };
    for (uint8_t j = 0; j < 8; j++) {
        for (uint8_t i = 0; i < 8; i++) {
            quadrado.x = scale * i;
            quadrado.y = scale * j;
            //alterna cores
            desenhaRetangulo(&quadrado, 
                ((i + j) % 2 == 0) 
                    ? &this->color1 
                    : &this->color2
            );
        }
    }
}