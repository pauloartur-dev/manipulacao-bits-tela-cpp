// main.cpp
#include <iostream>
#include <bitset>
#include <string>
#include <thread>
#include <chrono>

#include "Bits.h"
#include "Tela.h"
#include "Random.h"

using namespace std;

/*
  Estrutura geral:
  - Mostra a tela toda ligada
  - Modo de teste automático (10 imagens aleatórias usando rand32())
  - Desliga a tela e entra em loop de comandos:
      L n  -> ligar bit n (0..7) na fita
      D n  -> desligar bit n
      T    -> ligar todos os bits da fita
      N    -> desligar todos os bits da fita
      E n  -> enviar fita para linha n (0..3)
      S    -> sair -> finalização hacker
*/

int main()
{
    // inicializa gerador rand (NAO no main usamos srand aqui chamando a função
    srand32();

    // --- inicialização: tela com todos os 32 pixels ligados ---
    unsigned int estadoTela = 0xFFFFFFFFu; // todos os 32 bits ligados
    cout << "Tela inicial (todos os pixels ligados):" << endl;
    tela(estadoTela);

    // espera 1.5s antes do modo de teste automático
    this_thread::sleep_for(chrono::milliseconds(1500));

    // --- modo de teste automático: 10 imagens aleatórias ---
    cout << endl << "Entrando no modo de teste automatico (10 imagens aleatorias):" << endl;
    for (int i = 0; i < 10; i++)
    {
        unsigned int valor = rand32();
        cout << "Teste " << (i+1) << ":" << endl;
        tela(valor);
        // pausa de 1 segundo entre cada troca
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "------------------------" << endl;
    }

    // --- após os testes, desligar todos os pixels e mostrar interface ---
    unsigned int estado = 0x00000000u;
    unsigned int &estadoTelaRef = estadoTela; // keep original variable name for later use
    estadoTela = 0x00000000u;
    cout << endl << "Testes concluídos. Tela desligada." << endl;
    tela(estadoTela);

    unsigned char fitaBits = 0x00;

    cout << endl;
    cout << "Comandos disponíveis:" << endl;
    cout << " L n  -> ligar bit n (0..7) na fita" << endl;
    cout << " D n  -> desligar bit n (0..7) na fita" << endl;
    cout << " T    -> ligar todos os bits da fita" << endl;
    cout << " N    -> desligar todos os bits da fita" << endl;
    cout << " E n  -> enviar fita para linha n (0..3)" << endl;
    cout << " S    -> sair e executar finalizacao (hack)" << endl;

    char op;
    cout << endl << "Digite um comando: ";
    cin >> op;

    while (op != 'S')
    {
        if (op == 'L') // ligar bit
        {
            int n;
            cin >> n;
            if (n >= 0 && n <= 7)
            {
                fitaBits = ligarBit(fitaBits, n);
            }
            else
            {
                cout << "Numero de bit invalido (deve ser 0..7)." << endl;
            }
        }
        else if (op == 'D') // desligar bit
        {
            int n;
            cin >> n;
            if (n >= 0 && n <= 7)
            {
                fitaBits = desligarBit(fitaBits, n);
            }
            else
            {
                cout << "Numero de bit invalido (deve ser 0..7)." << endl;
            }
        }
        else if (op == 'T') // todos
        {
            fitaBits = 0xFF;
        }
        else if (op == 'N') // nenhum
        {
            fitaBits = 0x00;
        }
        else if (op == 'E') // enviar para uma linha
        {
            int linhaNum;
            cin >> linhaNum;
            if (linhaNum >= 0 && linhaNum <= 3)
            {
                estadoTela = atualizar(estadoTela, fitaBits, linhaNum);
            }
            else
            {
                cout << "Numero de linha invalido (deve ser 0..3)." << endl;
            }
        }
        else
        {
            cout << "Comando desconhecido." << endl;
        }

        // redesenha a tela e fita a cada comando
        cout << endl << "Tela atual:" << endl;
        tela(estadoTela);
        cout << endl << "Fita atual: ";
        fita(fitaBits);

        cout << endl << "Digite um comando: ";
        cin >> op;
    }

    // --- finalização: modo hacker ---
    cout << endl << "Finalizando... modo HACKER!" << endl;

    // mostra o inteiro de 32 bits em formato binário (usa <bitset> conforme pedido)
    cout << "Estado da tela (32 bits): ";
    cout << bitset<32>(estadoTela) << endl;

    // separa em duas metades de 16 bits usando as funções da biblioteca Bits
    unsigned short altos = bitsAltos(estadoTela);
    unsigned short baixos = bitsBaixos(estadoTela);

    cout << endl << "Hackeando metade alta:" << endl;
    hackear(altos);

    cout << endl << "Hackeando metade baixa:" << endl;
    hackear(baixos);

    // mensagem do hacker e som BEL
    cout << endl << ">>> ACESSO NAO AUTORIZADO <<<" << endl;
    cout << '\a' << endl; // beep como no lab7q2

    return 0;
}
