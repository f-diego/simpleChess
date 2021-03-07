#include <SFML/Graphics.hpp>
#include <string>
#include "Board.h"

#define XOFF 75
#define YOFF 75

int main(){
  sf::RenderWindow window(sf::VideoMode(750, 750), "Xadrez do Jotinha", sf::Style::Titlebar | sf::Style::Close);
  sf::Color backgroundColor = sf::Color(22, 23, 35);
  Board board(&window);
  while(window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear(backgroundColor);
    board.draw();
    window.display();

  }
  return 0;
}