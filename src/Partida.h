#pragma once
#include "Peca.h"
#include <string>
#include <SDL_rect.h>

static const std::string fenPosicaoInicial = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

typedef struct Posicao {
    Peca Pecas[64];
} Posicao;

typedef struct EstadoTabuleiro {
    Posicao* posicao = nullptr;
    Posicao* posicaoFixa = nullptr;
    Posicao* posicaoTemp = nullptr;

    Peca pecaDragNDrop = VAZIO;
    SDL_Point dragNDrop;
    
    bool brancasJogam = true;
} EstadoTabuleiro;



Posicao* setPosicao(EstadoTabuleiro* partida, std::string fen);
Posicao* setPosicaoInicial(EstadoTabuleiro* partida);