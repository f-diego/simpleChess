#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>

class Board{
private:
  int8_t board[8][8];
public:
  int8_t get(uint8_t x, uint8_t y) const{
    return board[y][x];
  }
  void printBoard() const{
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t x = 0; x < 8; x++)
        printf("[%3d]", board[y][x]);
      printf("\n");
    }
  }
};

class ChessGame
{
private:
  std::vector<Board> board;
  Board* currentBoard;
  int8_t currentMove[4];
  SDL_Texture *good, *bad;
  SDL_Color color1 = {52, 95, 117, 255};
  SDL_Color color2 = {164, 171, 189, 255};
  SDL_Color colorh = {0, 255, 0, 100};
public:
  ChessGame(){};
  ~ChessGame();

  int8_t readPiece(uint8_t x, uint8_t y) const{
    return currentBoard->get(x,y);
  }
  int8_t indexPos(std::string);
  
  friend class App;
};
