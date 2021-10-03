#include "Render.hpp"

void Render::drawPiece(int piece, int x, int y) {
  sf::Sprite sprPiece;
  if (piece < 0) {
    sprPiece.setTexture(texBk);
    piece *= -1;
  } else
    sprPiece.setTexture(texWh);
  if (y != grabbedPiece[0] || x != grabbedPiece[1]) {
    sprPiece.setPosition(sf::Vector2f(75 + 75 * x, 75 + 75 * y));
    sprPiece.setTextureRect(sf::IntRect(75 * (piece - 1), 0, 75, 75));
    window.draw(sprPiece);
  }
}

void Render::drawPiece(int piece, sf::Vector2i mouse) {
  sf::Sprite sprPiece;
  if (piece < 0) {
    sprPiece.setTexture(texBk);
    piece *= -1;
  } else
    sprPiece.setTexture(texWh);
  sprPiece.setPosition(mouse.x - 75 / 2, mouse.y - 75 / 2);
  sprPiece.setTextureRect(sf::IntRect(75 * (piece - 1), 0, 75, 75));
  window.draw(sprPiece);
}

void Render::drawAllPieces() {
  for (uint8_t y = 0; y < 8; y++)
    for (uint8_t x = 0; x < 8; x++)
      drawPiece(board.readPieceAt(x, y), x, y);
}

void Render::drawMousePiece() {
  int8_t x = grabbedPiece[1], y = grabbedPiece[0];
  if (x != -1 && y != -1)
    drawPiece(board.readPieceAt(x, y), sf::Mouse::getPosition(window));
}

void Render::drawBoard() {
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
}
void Render::showDebugInfo() {
  std::string debugtx;
  using namespace std;
  debugtx = "mouse: " + to_string(cursorPos[0]) + ", " + to_string(cursorPos[1]) + " grab: " + to_string(grabbedPiece[0]) + ", " + to_string(grabbedPiece[1]) + " Score: " + to_string(board.getScore());
  window.setTitle(debugtx);
}