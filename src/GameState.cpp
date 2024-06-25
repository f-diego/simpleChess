#include "GameState.h"
#include <stdexcept>

Posicao& GameState::PosicaoAtual()
{
    return this->posicoes.back();
}