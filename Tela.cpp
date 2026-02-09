// Tela.cpp
#include "Tela.h"
#include "Bits.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Sequências ANSI usadas:
// ON_COLOR  -> pixel ligado (fundo verde)
// OFF_COLOR -> pixel desligado (fundo preto)
// RESET     -> reset das cores
static const char* ON_COLOR  = "\033[42m"; // background green
static const char* OFF_COLOR = "\033[40m"; // background black
static const char* RESET     = "\033[0m";

// REPRESENTAÇÃO: cada pixel é um bloco colorido seguido de reset.
// Para compatibilidade textual (caso terminal não suporte cores), mostramos '*' e '.' também.

void linha(unsigned char valor)
{
    // borda lateral esquerda
    cout << "|";
    for (int b = 7; b >= 0; b--)
    {
        if (testarBit(valor, b))
        {
            cout << ON_COLOR << " " << RESET; // espaço com background
        }
        else
        {
            cout << OFF_COLOR << " " << RESET;
        }
    }
    cout << "|"; // borda direita

    // mostrar representação textual ao lado (útil se ANSI não visível)
    cout << "  ";
    for (int b = 7; b >= 0; b--)
    {
        cout << (testarBit(valor, b) ? '*' : '.');
    }

    cout << endl;
}

void fita(unsigned char valor)
{
    cout << "+------------------+" << endl;
    cout << " ";
    linha(valor);
    cout << "+------------------+" << endl;
}

void tela(unsigned int valor)
{
    // moldura superior
    cout << "+------------------+" << endl;
    for (int linhaNum = 0; linhaNum < 4; linhaNum++)
    {
        int shift = 8 * (3 - linhaNum);
        unsigned char byte = (unsigned char)((valor >> shift) & 0xFFu);
        // imprimimos a linha com bordas internas
        cout << "| ";
        for (int b = 7; b >= 0; b--)
        {
            if (testarBit(byte, b))
                cout << ON_COLOR << " " << RESET;
            else
                cout << OFF_COLOR << " " << RESET;
        }
        cout << " |  ";
        for (int b = 7; b >= 0; b--)
            cout << (testarBit(byte, b) ? '*' : '.');

        cout << endl;
    }
    // moldura inferior
    cout << "+------------------+" << endl;
}

unsigned int atualizar(unsigned int estadoTela, unsigned char fitaBits, int linhaNum)
{
    if (linhaNum < 0 || linhaNum > 3) return estadoTela;

    int shift = 8 * (3 - linhaNum);
    unsigned int mask = 0xFFu << shift;
    estadoTela &= ~mask; // zera a linha
    estadoTela |= ((unsigned int)fitaBits << shift); // coloca novo byte
    return estadoTela;
}

void linhaHacker(unsigned char valor)
{
    // Exibição "hacker": trocamos alguns pixels ligados por letras (mantendo cor original)
    // Mostramos também a versão textual ao lado.
    cout << "| ";
    for (int b = 7; b >= 0; b--)
    {
        if (!testarBit(valor, b))
        {
            cout << OFF_COLOR << " " << RESET;
        }
        else
        {
            // quando ligado, mostrar H ou * em background ON_COLOR
            if (b == 6 || b == 3)
                cout << ON_COLOR << "H" << RESET;
            else
                cout << ON_COLOR << " " << RESET;
        }
    }
    cout << " |  ";
    for (int b = 7; b >= 0; b--)
        cout << (testarBit(valor, b) ? '*' : '.');

    cout << endl;
}

void hackear(unsigned short metade)
{
    unsigned char alto = (unsigned char)((metade >> 8) & 0xFFu);
    unsigned char baixo = (unsigned char)(metade & 0xFFu);

    cout << "+------------------+" << endl;
    linhaHacker(alto);
    linhaHacker(baixo);
    cout << "+------------------+" << endl;
}
