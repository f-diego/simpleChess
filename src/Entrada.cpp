#include "Entrada.h"
#include "SDL_mouse.h"

void ProcessaInput(EstadoTabuleiro* partida, SDL_Event* event)
{
    SDL_GetMouseState(&partida->dragNDrop.x, &partida->dragNDrop.y);

    if (event->button.button == SDL_BUTTON_LEFT) {
        
    }
}