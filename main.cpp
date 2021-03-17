#include <SFML/Graphics.hpp>
#include <string>
#include "Board.h"
#include "fish.hpp"

#define XOFF 75
#define YOFF 75

int main(){
  sf::RenderWindow window(sf::VideoMode(750, 750), "Xadrez do Jotinha", sf::Style::Titlebar | sf::Style::Close);
  sf::Color backgroundColor = sf::Color(22, 23, 35);
  startFish("sf.exe");
  Board board(&window);
  board.move("e2e4");
  board.move("f7f5");
  //board.move("e4f5");
  board.printHistory();
  while(window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        }
        //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
        //  std::string minhajogada = fishMove(board.getHistory());
        //  board.move(minhajogada);
        //  board.printHistory();
    }
    
    window.clear(backgroundColor);
    board.draw();
    //board.highlightCursor();
    window.display();
//teste
  }
  return 0;
}