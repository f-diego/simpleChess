#include "Board.hpp"

//converts a string position to numeric
int8_t ChessGame::indexPos(std::string pos ){
    int index;
    if(pos.length() != 2)
      return -1;
    index = 8 * (56 - pos.at(1)) + (pos.at(0) - 97);
    return index;
}