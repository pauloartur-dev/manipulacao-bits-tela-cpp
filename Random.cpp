// Random.cpp
#include "Random.h"
#include <cstdlib> // rand, srand
#include <ctime>   // time

// Semente para o gerador pseudo-aleatório
void srand32()
{
    // Usa time(NULL) como semente
    srand((unsigned int) time(NULL));
}

// Gera 32 bits usando a técnica do enunciado:
// 1 bit, 15 bits, 1 bit, 15 bits  -> concatena para 32 bits
unsigned int rand32()
{
    // rand() retorna 0..32767 (15 bits)
    unsigned int a = (unsigned int) (rand() & 0x7FFF); // 15 bits
    unsigned int b = (unsigned int) (rand() & 0x7FFF); // 15 bits
    unsigned int bit0 = (unsigned int) (rand() & 0x1); // 1 bit
    unsigned int bit1 = (unsigned int) (rand() & 0x1); // 1 bit

    // Construir: [bit0 (1)] [a (15)] [bit1 (1)] [b (15)]
    unsigned int result = 0;
    result |= (bit0 & 0x1u) << 31;
    result |= (a & 0x7FFFu) << 16;
    result |= (bit1 & 0x1u) << 15;
    result |= (b & 0x7FFFu);

    return result;
}
