#pragma once
#include "Peca.h"

class Posicao
{
public:
    Posicao();
    Posicao(std::string fen);

    Piece* getPieceAt(int x, int y);
private:
    Piece *Pecas[8][8];
};

