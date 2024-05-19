#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <stdint.h>
#include "Pecas.h"

class Board {
private:
    Pecas board[8][8];
public:
    int8_t get(uint8_t x, uint8_t y) const
    {
        return board[y][x];
    }
    void printBoard() const
    {
        for (uint8_t y = 0; y < 8; y++) {
            for (uint8_t x = 0; x < 8; x++)
                printf("[%3d]", board[y][x]);
            printf("\n");
        }
    }
};