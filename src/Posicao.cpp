#include <stdexcept>
#include "Posicao.h"

static const char novaLinha = '/';
static Piece char2Peca(char& c);

Piece* Posicao::getPieceAt(int x, int y)
{
    return this->Pecas[y][x];
}

Posicao::Posicao(std::string fen)
{
    int i = 0;
    for (char& c : fen) {
        if (i >= 64) {
            break;
        }

        if (c == novaLinha) {
            int linhaAtual = ((i - 1) / 8);
            int novaLinha = linhaAtual + 1;
            i = (novaLinha * 8);
            continue;
        }

        if (c > '0' && c < '9') {
            int espacosVazios = (c - 48);
            for (int j = 0; j < espacosVazios; j++)
            {
                this->Pecas[i++] = nullptr;
            }
            continue;
        }

        this->Pecas[i++] = char2Peca(c);
    }
}

Posicao::Posicao()
{
    Posicao(fenPosicaoInicial);
}

Piece char2Peca(char& c)
{
    switch (c)
    {
    case 'k':
        return Piece(PieceShape::KING, PieceColor::BLACK);
    case 'q':
        return Piece(PieceShape::QUEEN, PieceColor::BLACK);
    case 'r':
        return Piece(PieceShape::ROOK, PieceColor::BLACK);
    case 'b':
        return Piece(PieceShape::BISHOP, PieceColor::BLACK);
    case 'n':
        return Piece(PieceShape::HORSEY, PieceColor::BLACK);
    case 'p':
        return Piece(PieceShape::PAWN, PieceColor::BLACK);

    case 'K':
        return Piece(PieceShape::KING, PieceColor::WHITE);
    case 'Q':
        return Piece(PieceShape::QUEEN, PieceColor::WHITE);
    case 'R':
        return Piece(PieceShape::ROOK, PieceColor::WHITE);
    case 'B':
        return Piece(PieceShape::BISHOP, PieceColor::WHITE);
    case 'N':
        return Piece(PieceShape::HORSEY, PieceColor::WHITE);
    case 'P':
        return Piece(PieceShape::PAWN, PieceColor::WHITE);

    default:
        throw std::runtime_error("Error parsing FEN string");
    }
}