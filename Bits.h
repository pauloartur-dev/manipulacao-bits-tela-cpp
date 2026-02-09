// Bits.h
#ifndef BITS_H
#define BITS_H

// retorna os 16 bits mais altos (esquerda) de um inteiro de 32 bits
unsigned short bitsAltos(unsigned int valor);

// retorna os 16 bits mais baixos (direita) de um inteiro de 32 bits
unsigned short bitsBaixos(unsigned int valor);

// testa um bit (0..7) em um byte
bool testarBit(unsigned char flag, int bit);

// liga o bit (0..7) em um byte e retorna o novo byte
unsigned char ligarBit(unsigned char flag, int bit);

// desliga o bit (0..7) em um byte e retorna o novo byte
unsigned char desligarBit(unsigned char flag, int bit);

#endif // BITS_H
