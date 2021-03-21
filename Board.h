#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define XOFF 75
#define YOFF 75

class Board {
public:
  Board() {
    this->readFen("rnbqkbnr / pppppppp / 8 / 8 / 8 / 8 / PPPPPPPP / RNBQKBNR");
  }
  ~Board() {}

  void printHistory() {
    std::cout << "Moves: " << moveHistory << "\n";
  }

  std::string getHistory() const {
    return moveHistory;
  }

  int8_t readPieceAt(uint8_t x, uint8_t y) const {
    return boardPosition[y][x];
  }

  void printBoard();
  uint8_t indexPos(std::string);
  uint8_t move(std::string);
  void readFen(std::string FEN);
  void draw();

private:
  int8_t boardPosition[8][8] = {0};
  sf::RenderWindow *window;
  sf::Texture texWh, texBk;
  std::string moveHistory;
  sf::Font font;
  sf::Color color1 = sf::Color(164, 171, 189);
  sf::Color color2 = sf::Color(52, 95, 117);
  sf::Color colorh = sf::Color(255, 255, 255, 150);
};