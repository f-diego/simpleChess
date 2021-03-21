#include "Board.h"
#include "Render.hpp"
#include "fish.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#define XOFF 75
#define YOFF 75

int main() {
  sf::RenderWindow window(sf::VideoMode(750, 750), "Xadrez do Jotinha", sf::Style::Titlebar | sf::Style::Close);
  sf::Color backgroundColor(22, 23, 35);
  startFish("sf.exe");
  Board board;
  Render scrboard(window, board);
  board.move("e2e4");
  board.move("f7f5");
  //board.move("e4f5");
  board.printHistory();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      //if (event.type == sf::Event::MouseButtonPressed && board.mouseInsideBoard())
      //  board.mouseGrab();
      //if (event.type == sf::Event::MouseButtonReleased) {
      //  board.mouseRelease();
      //}
      //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
      //  std::string minhajogada = fishMove(board.getHistory());
      //  board.move(minhajogada);
      //  board.printHistory();
    }

    window.clear(backgroundColor);
    scrboard.draw();
    //board.draw();
    scrboard.getCursorSquare();
    //board.highlightCursor();
    window.display();
    //teste
  }
  return 0;
}