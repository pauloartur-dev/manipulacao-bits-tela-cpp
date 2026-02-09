// Bits.cpp
#include "Bits.h"

// Funções extras pedidas pelo TP1 (16 bits altos/baixos)
unsigned short bitsAltos(unsigned int valor)
{
    // desloca 16 para a direita para obter os 16 bits mais significativos
    return (unsigned short)((valor >> 16) & 0xFFFFu);
}

unsigned short bitsBaixos(unsigned int valor)
{
    // máscara com 0xFFFF para obter os 16 bits menos significativos
    return (unsigned short)(valor & 0xFFFFu);
}

// === implementações originais do seu lab7q5.cpp ===

unsigned char ligarBit(unsigned char flag, int bit)
{
    return flag | (1 << bit);
}

unsigned char desligarBit(unsigned char flag, int bit)
{
    return flag & ~(1 << bit);
}

bool testarBit(unsigned char flag, int bit)
{
    if (flag & (1 << bit))
        return true;
    else
        return false;
}
