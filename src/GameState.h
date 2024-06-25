#pragma once
#include <string>
#include <SDL_rect.h>
#include "Posicao.h"
#include <vector>

static const std::string fenPosicaoInicial = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

class GameState
{
public:
    Piece* pecaDragNDrop;
    SDL_Point dragNDrop;

    bool brancasJogam;

	GameState();

    Posicao& PosicaoAtual();
private:
    std::vector<Posicao> posicoes;
};

GameState::GameState()
{
    this->posicoes.push_back(Posicao());

    this->pecaDragNDrop = nullptr;
    this->dragNDrop = { 0, 0 };

    this->brancasJogam = true;
}

