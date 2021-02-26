#include "Board.h"

void Board::readFen(std::string FEN) {
        int i = 0; // i = position of board from 0 to 63
        for (char& c : FEN) {
            if (c > 48 && c < 57) //if c is a number
                for (int j = c - 48; j > 0; j--)
                    boardPosition[i++] = -1;
            if ((c > 64 && c < 91) || (c > 96 && c < 123))
                boardPosition[i++] = c;
        }
    }

void Board::drawPiece(char piece, int x, int y, sf::Texture &ChessSet, sf::RenderWindow* window) {
    int pieceno;
    switch(piece){
    case 'K': pieceno=0; break;
    case 'Q': pieceno=1; break;
    case 'R': pieceno=2; break;
    case 'B': pieceno=3; break;
    case 'N': pieceno=4; break;
    case 'P': pieceno=5; break;
    case 'k': pieceno=6; break;
    case 'q': pieceno=7; break;
    case 'r': pieceno=8; break;
    case 'b': pieceno=9; break;
    case 'n': pieceno=10; break;
    case 'p': pieceno=11; break;

    default:
        return;
    }
    sf::Sprite sprPiece(ChessSet);
    sprPiece.setPosition(sf::Vector2f(XOFF + 75 * x, YOFF + 75 * y));
    sprPiece.setTextureRect(sf::IntRect(75 * pieceno, 0, 75, 75));
    window->draw(sprPiece);
}

void Board::draw(){
        sf::RectangleShape fig(sf::Vector2f(75, 75));
        sf::Color color;
        sf::Text texto;
        texto.setFont(font);
        texto.setCharacterSize(16);
        for (int j = 0; j < 8; j++) {
            for (int i = 0; i < 8; i++)
            {
                //desenha os quadrados alternando cores
                color = (color == color1) ? color2 : color1;
                fig.setFillColor(color);
                fig.setPosition(sf::Vector2f(XOFF + 75 * i, YOFF + 75 * j));
                window->draw(fig);
                //Notacao de casas
                if (i == 7) {
                    texto.setPosition(sf::Vector2f(XOFF + 75 * i + 65, YOFF + 75 * j));
                    texto.setString((char)(56 - j));
                    texto.setFillColor((color == color1) ? color2 : color1);
                    window->draw(texto);
                }
                if (j == 7) {
                    texto.setPosition(sf::Vector2f(XOFF + 75 * i + 60, YOFF + 75 * j + 55));
                    texto.setString((char)(97 + i));
                    texto.setFillColor((color == color1) ? color2 : color1);
                    window->draw(texto);
                }
            }
            color = (color == color1) ? color2 : color1;
        }
        //drawpieces
        int x = 0, y = 0;
          for (int i = 0; i < 64; i++) {
              if (x > 7) {
                  x = 0;
                  y++;
              }
              drawPiece(boardPosition[i], x++, y, ChessSet, window);
          }
    }