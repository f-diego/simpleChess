#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define XOFF 75
#define YOFF 75

class Board {
public:
  Board() = delete;
  Board(sf::RenderWindow *windowReference) {
    window = windowReference;
    this->readFen("rnbqkbnr / pppppppp / 8 / 8 / 8 / 8 / PPPPPPPP / RNBQKBNR");
    this->texWh.loadFromFile("res/defwh.png");
    this->texBk.loadFromFile("res/defbk.png");
    this->font.loadFromFile("res/Monaco.ttf");
  }
  ~Board() {}
  void printHistory() {
    std::cout << "Moves: " << moveHistory << "\n";
  }
  const std::string getHistory() {
    return moveHistory;
  }
  void getCursorSquare() {
    sf::Vector2i mousepos = sf::Mouse::getPosition(*window);
    mousepos.x = mousepos.x / 75;
    mousepos.y = mousepos.y / 75;
    if (mousepos.x > 0 && mousepos.y > 0 && mousepos.x < 9 && mousepos.y < 9)
      curx = mousepos.x, cury = mousepos.y;
  }

  void highlightCursor() {
    sf::RectangleShape fig(sf::Vector2f(75, 75));
    fig.setFillColor(colorh);
    fig.setPosition(sf::Vector2f(75 + curx * 75, 75 + cury * 75));
    window->draw(fig);
  }

  void printBoard();
  uint8_t indexPos(std::string);
  uint8_t move(std::string);
  void readFen(std::string FEN);
  void draw();

private:
  int8_t boardPosition[8][8] = {0};
  uint8_t curx, cury;
  sf::RenderWindow *window;
  sf::Texture texWh, texBk;
  std::string moveHistory;
  sf::Font font;
  sf::Color color1 = sf::Color(164, 171, 189);
  sf::Color color2 = sf::Color(52, 95, 117);
  sf::Color colorh = sf::Color(255, 0, 0, 100);
  void drawOverlay(int);
  void drawPiece(int, int, int);
};