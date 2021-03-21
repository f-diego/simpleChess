#include "Board.h"
#include <string>

void Board::readFen(std::string FEN) {
  int i = 0; // i = position of board from 0 to 63
  int evil;
  int8_t *pBoard = &boardPosition[0][0];
  for (char &c : FEN) {
    if (c > 48 && c < 57) //if c is a number
      for (int j = c - 48; j > 0; j--)
        pBoard[i++] = 0;
    if ((c > 64 && c < 91) || (c > 96 && c < 123)) {
      evil = 1;
      if (c > 96) { //if is lowercase
        evil = -1;
        c -= 32; //uppercases the char
      }
      switch (c) {
      case 'K': pBoard[i++] = 1 * evil; break;
      case 'Q': pBoard[i++] = 2 * evil; break;
      case 'R': pBoard[i++] = 3 * evil; break;
      case 'B': pBoard[i++] = 4 * evil; break;
      case 'N': pBoard[i++] = 5 * evil; break;
      case 'P': pBoard[i++] = 6 * evil; break;
      }
    }
  }
}

void Board::printBoard() {
  for (uint8_t y = 0; y < 8; y++) {
    for (uint8_t x = 0; x < 8; x++)
      printf("[%d]", boardPosition[y][x]);
    printf("\n");
  }
}

uint8_t Board::indexPos(std::string pos) {
  int index;
  if (pos.length() != 2)
    return -1;
  index = 8 * (56 - pos.at(1)) + (pos.at(0) - 97);
  return index;
}
//97 = a
uint8_t Board::move(std::string move) {
  int8_t *pBoard = &boardPosition[0][0];
  if (move.length() != 4)
    return 0;
  int from, to;
  from = indexPos(move.substr(0, 2));
  to = indexPos(move.substr(2, 2));
  pBoard[to] = pBoard[from];
  pBoard[from] = 0;
  if (moveHistory.length() > 0)
    moveHistory.append(" " + move);
  else
    moveHistory.append(move);
  return 1;
}
