#pragma once

enum PieceColor {
    WHITE,
    BLACK
};

enum PieceShape {
    KING = 1,
    QUEEN,
    ROOK,
    BISHOP,
    HORSEY,
    PAWN,
};

class Piece
{
public:
    Piece(PieceShape shape, PieceColor color);

    const PieceShape shape;
    const PieceColor color;
private:
};

Piece::Piece(PieceShape shape, PieceColor color) : shape(shape), color(color) {}
