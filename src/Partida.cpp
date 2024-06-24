#include "Partida.h"

static const char novaLinha = '/';
static Peca char2Peca(char& c);

Posicao* setPosicao(EstadoTabuleiro* partida, std::string fen) {
    Posicao* posicao = new Posicao;
    bool fenInvalido = false;

    int i = 0;
    for(char& c : fen) {
        if (i >= 64) {
            break;
        }  

        if (c == novaLinha) {
            int linhaAtual = ( ( i - 1) / 8 );
            int novaLinha = linhaAtual + 1;
            i = (novaLinha * 8);
            continue;
        }

        if (c > '0' && c < '9') {
            int espacosVazios = (c - 48);
            for (int j = 0; j < espacosVazios; j++)
            {
                posicao->Pecas[i++] = VAZIO;
            }
            continue;
        }

        Peca peca = char2Peca(c);

        if (peca != INVALIDA) {
            posicao->Pecas[i++] = peca;
        }      
    }

    if (fenInvalido) {
        delete posicao;
        return nullptr;
    }

    delete partida->posicao;
    partida->posicaoFixa = partida->posicao = posicao;
    return posicao;
}

Posicao* setPosicaoInicial(EstadoTabuleiro* partida) 
{ 
    return setPosicao(partida, fenPosicaoInicial); 
}

Peca char2Peca(char& c) {
    switch (c)
    {
    case 'k':
        return pREI;   
    case 'q':
        return pDAMA;   
    case 'r':
        return pTORRE;   
    case 'b':
        return pBISPO;   
    case 'n':
        return pCAVALO;   
    case 'p':
        return pPEAO; 

    case 'K':
        return bREI;   
    case 'Q':
        return bDAMA;   
    case 'R':
        return bTORRE;   
    case 'B':
        return bBISPO;   
    case 'N':
        return bCAVALO;   
    case 'P':
        return bPEAO;

    default:
        return INVALIDA;
    }
}