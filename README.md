🖥️ Simulador de Tela de 32 Bits (C++)
Este projeto foi desenvolvido para a disciplina de [Nome da Disciplina] na UFERSA, focando em operações de baixo nível e representação visual de dados binários.

🚀 Funcionalidades Técnicas:
Manipulação de Registros: Implementação de funções para ligar, desligar e testar bits individuais em bytes e inteiros de 32 bits.

Interface ANSI: Criação de uma representação visual de "pixels" coloridos no terminal usando sequências de escape ANSI.

Geração Pseudo-Aleatória: Algoritmo personalizado para gerar números de 32 bits combinando múltiplos chamados de rand() para testes de tela.

Processamento de Comandos: Interpretador de comandos via terminal (L, D, T, N, E) para interação em tempo real com o estado da tela.

Modo Hacker: Finalização especial que utiliza std::bitset para exibição binária e processamento de metades de 16 bits (High/Low).

🛠️ Tecnologias Utilizadas:
C++ Moderno (Operadores bitwise: >>, |, &, ~).

Gerenciamento de Tempo: Uso de std::this_thread e std::chrono para animações.

Bibliotecas Padrão: <bitset>, <iostream> e <ctime>.
