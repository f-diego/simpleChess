#pragma once
#include <SFML/Graphics.hpp>

#define XOFF 75
#define YOFF 75

class Board {
public:
    Board() = delete;
    Board(sf::RenderWindow* windowReference){
        window = windowReference;
        this->readFen("rnbqkbnr / pppppppp / 8 / 8 / 8 / 8 / PPPPPPPP / RNBQKBNR");
        this->ChessSet.loadFromFile("res/default.png");
        this->font.loadFromFile("res/Monaco.ttf");
    }
    ~Board() {}

    void readFen(std::string FEN);
    void draw();

private:
    char boardPosition[64] = {};
    sf::RenderWindow* window;
    sf::Texture ChessSet;
    sf::Font font;
    sf::Color color1 = sf::Color(164,171,189);
    sf::Color color2 = sf::Color(52, 95, 117);

    void drawPiece(char piece, int x, int y, sf::Texture &ChessSet, sf::RenderWindow* window);
};