#pragma once
#include <SDL.h>
#include "Board.hpp"
#include "Renderizador.hpp"
#include <string>
#include <vector>

class Partida
{
private:
    std::vector<Board> board;
    Board* currentBoard;
    int8_t currentMove[4];

public:
    Partida();
    ~Partida();

    int8_t readPiece(uint8_t x, uint8_t y) const
    {
        return currentBoard->get(x, y);
    }
    int8_t indexPos(std::string);
};