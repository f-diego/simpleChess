#pragma once
#include "Board.h"

class Render {
public:
  Render() = delete;
  Render(sf::RenderWindow &refWindow, Board &refBoard) : window(refWindow), board(refBoard) {
    this->texWh.loadFromFile("res/defwh.png");
    this->texBk.loadFromFile("res/defbk.png");
    this->font.loadFromFile("res/Monaco.ttf");
  }
  ~Render() {}

  void drawPiece(int piece, int x, int y) {
    sf::Sprite sprPiece;
    if (piece < 0) {
      sprPiece.setTexture(texBk);
      piece *= -1;
    } else
      sprPiece.setTexture(texWh);
    if (y == grabbedPiece[0] && x == grabbedPiece[1])
      sprPiece.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) - sf::Vector2f(75 / 2, 75 / 2));
    else
      sprPiece.setPosition(sf::Vector2f(75 + 75 * x, 75 + 75 * y));
    sprPiece.setTextureRect(sf::IntRect(75 * (piece - 1), 0, 75, 75));
    window.draw(sprPiece);
  }

  void draw() {
    std::string debugtx;
    using namespace std;
    debugtx = "mouse: " + to_string(cursorPos[0]) + ", " + to_string(cursorPos[1]) + " grab: " + to_string(grabbedPiece[0]) + ", " + to_string(grabbedPiece[1]);
    window.setTitle(debugtx);
    sf::RectangleShape fig(sf::Vector2f(75, 75));
    sf::Color color;
    sf::Text texto;
    texto.setFont(font);
    texto.setCharacterSize(16);
    for (int j = 0; j < 8; j++) {
      for (int i = 0; i < 8; i++) {
        //desenha os quadrados alternando cores
        color = (color == color1) ? color2 : color1;
        fig.setFillColor(color);
        fig.setPosition(sf::Vector2f(75 + 75 * i, 75 + 75 * j));
        window.draw(fig);
        //Notacao de casas
        if (i == 7) {
          texto.setPosition(sf::Vector2f(75 + 75 * i + 65, 75 + 75 * j));
          texto.setString((char)(56 - j));
          texto.setFillColor((color == color1) ? color2 : color1);
          window.draw(texto);
        }
        if (j == 7) {
          texto.setPosition(sf::Vector2f(75 + 75 * i + 60, 75 + 75 * j + 55));
          texto.setString((char)(97 + i));
          texto.setFillColor((color == color1) ? color2 : color1);
          window.draw(texto);
        }
      }
      color = (color == color1) ? color2 : color1;
    }
    for (uint8_t y = 0; y < 8; y++)
      for (uint8_t x = 0; x < 8; x++) {
        drawPiece(board.readPieceAt(x, y), x, y);
      }
  }

  void highlightCursor() {
    sf::RectangleShape fig(sf::Vector2f(75, 75));
    fig.setFillColor(colorh);
    fig.setPosition(sf::Vector2f(cursorPos[1] * 75, cursorPos[0] * 75));
    window.draw(fig);
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
    if (cursorPos[0] == -1 || cursorPos[1] == -1)
      return false;
    return true;
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
  sf::Color colorh = sf::Color(255, 255, 255, 150);
  sf::Font font;
};