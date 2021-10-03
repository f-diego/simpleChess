#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Board.hpp"

class App {
public:
  App(const char *title, int largura, int altura);
  SDL_Texture *carregarTextura(const char *path);
  void finalizar();
  void limpar();
  void renderSprite(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst);
  void renderRect(SDL_Rect* rec, SDL_Color* color);
  void drawAll();
  void drawBoard();
  void drawPiece(int8_t piece, int x, int y);
  void display();
  void setChessGame(ChessGame* cg);
  void aumentar();
  void diminuir();
  uint8_t t = 75;

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  ChessGame *chessgame = nullptr;
};