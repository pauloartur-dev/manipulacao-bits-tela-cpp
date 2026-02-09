// Tela.h
#ifndef TELA_H
#define TELA_H

// desenha uma linha de 8 pixels a partir de um byte (bits 7..0)
void linha(unsigned char valor);

// desenha a "fita" (uso da função linha), com adornos
void fita(unsigned char valor);

// desenha a tela de 32 bits (4 linhas)
void tela(unsigned int valor);

// atualiza a linha 'linhaNum' (0..3) da tela com os bits da fita (byte) e retorna novo estado da tela
unsigned int atualizar(unsigned int estadoTela, unsigned char fitaBits, int linhaNum);

// versão hacker: desenha uma linha "personalizada" (pode mostrar algo diferente)
void linhaHacker(unsigned char valor);

// hackear: recebe 16 bits e mostra duas linhas hackeadas
void hackear(unsigned short metade);

#endif // TELA_H
