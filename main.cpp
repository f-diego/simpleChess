#include "Board.hpp"
#include "sdl_app.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argv, char **args) {
  if (SDL_Init(SDL_INIT_VIDEO) > 0)
    printf("HEY.. SDL_Init HAS FAILED. SDL_ERROR: %s\n", SDL_GetError());
  if (!(IMG_Init(IMG_INIT_PNG)))
    printf("IMG_init has failed. Error:  %s\n", SDL_GetError());

  App app("SDL-Chess", 1280, 720);
  ChessGame *chessgame = new ChessGame();
  app.setChessGame(chessgame);
  bool game = true;
  SDL_Event event;

  while (game) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        game = false;
      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_EQUALS:
          app.aumentar();
          break;
        case SDLK_MINUS:
          app.diminuir();
          break;
        default:
          break;
        }
      }
    }

    app.limpar();
    app.drawBoard();
    app.display();
  }
  app.finalizar();
  SDL_Quit();
  return 0;
}