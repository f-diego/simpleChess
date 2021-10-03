#include "sdl_app.hpp"


App::App(const char *title, int largura, int altura) : window(nullptr), renderer(nullptr) {
  int wflags = SDL_WINDOW_SHOWN;
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largura, altura, wflags);
  if (!window)
    printf("Falha ao criar janela, erro: %s\n", SDL_GetError());
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);
}

SDL_Texture *App::carregarTextura(const char *path) {
  SDL_Texture *texture = nullptr;
  texture = IMG_LoadTexture(renderer, path);
  if (!texture)
    printf("Failed to load texture, error: ", SDL_GetError());
  return texture;
}

void App::finalizar() {
  SDL_DestroyWindow(window);
}
void App::limpar() {
  SDL_RenderClear(renderer);
}

void App::renderSprite(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst) {
  SDL_RenderCopy(renderer, texture, src, dst);
}

void App::renderRect(SDL_Rect* rect, SDL_Color* c) {
  uint8_t r,g,b,a; //old color
  SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
  SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, c->a);
  SDL_RenderFillRect(renderer, rect);
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  //SDL_FillRect(dst, r, (Uint32)((c->r << 16) + (c->g << 8) + (c->b << 0));
}

void App::drawAll(){

}
void App::drawBoard(){
  SDL_Rect square = {0, 0, t, t};
  SDL_Color c1 = chessgame->color1;
  SDL_Color c2 = chessgame->color2;
  for (uint8_t j = 0; j < 8; j++) {
    for (uint8_t i = 0; i < 8; i++) {
      square.x = t * i;
      square.y = t * j;
      //alternate colors
      renderRect(&square, ( (i+j)%2 == 0 ) ? &c2 : &c1);
    }
  }
}

void App::display() {
  SDL_RenderPresent(renderer);
}

void App::setChessGame(ChessGame* cg) {
  chessgame = cg;
}

void App::aumentar(){
  int *w = new int();
  int *h = new int();
  SDL_GetWindowSize(window, w, h);
  int newsize = (t+1) * 8;
  if(newsize <= *h && newsize <= *w)
    t++;
}

void App::diminuir(){
  if (t>9)
    t--;
}