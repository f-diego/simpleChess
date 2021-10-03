#pragma once
#include "Board.hpp"

class Render {
public:
  Render() = delete;
  Render(sf::RenderWindow &refWindow, Board &refBoard) : window(refWindow), board(refBoard) {
    texWh.loadFromFile("res/defwh.png");
    texBk.loadFromFile("res/defbk.png");
    font.loadFromFile("res/Monaco.ttf");
  }
  ~Render() {}

  void draw() {
    showDebugInfo();
    drawBoard();
    drawAllPieces();
    highlightSquare();
    drawMousePiece();
  }

  void highlightSquare(int8_t x, int8_t y) {
    sf::RectangleShape fig(sf::Vector2f(75, 75));
    fig.setFillColor(colorh);
    fig.setPosition(sf::Vector2f(x * 75, y * 75));
    window.draw(fig);
  }

  void highlightSquare() {
    highlightSquare(cursorPos[1], cursorPos[0]);
  }

  void getCursorSquare() {
    sf::Vector2i mousepos = sf::Mouse::getPosition(window);
    mousepos.x = mousepos.x / 75;
    mousepos.y = mousepos.y / 75;
    if (mousepos.x > 0 && mousepos.y > 0 && mousepos.x < 9 && mousepos.y < 9)
      cursorPos[0] = mousepos.y, cursorPos[1] = mousepos.x;
    else
      cursorPos[0] = -1, cursorPos[1] = -1;
  }

  bool mouseInsideBoard() {
    return !(cursorPos[0] == -1 || cursorPos[1] == -1);
  }

  void mouseGrab() {
    grabbedPiece[0] = cursorPos[0] - 1;
    grabbedPiece[1] = cursorPos[1] - 1;
  }

  void mouseRelease() {
    grabbedPiece[0] = -1, grabbedPiece[1] = -1;
  }

private:
  sf::RenderWindow &window;
  Board &board;
  int8_t cursorPos[2];
  int8_t grabbedPiece[2] = {-1, -1};
  sf::Texture texWh, texBk;
  sf::Color color1 = sf::Color(164, 171, 189);
  sf::Color color2 = sf::Color(52, 95, 117);
  sf::Color colorh = sf::Color(0, 255, 0, 100);
  sf::Font font;

  void drawPiece(int piece, int x, int y);
  void drawPiece(int piece, sf::Vector2i);
  void drawAllPieces();
  void drawBoard();
  void showDebugInfo();
  void drawMousePiece();
};