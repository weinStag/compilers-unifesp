#ifndef DFA_H
#define DFA_H

#include "token.h"

// Número máximo de estados e caracteres possíveis
#define MAX_STATES 50
#define MAX_CHARS 128

// Estrutura do DFA
typedef struct {
    int transitions[MAX_STATES][MAX_CHARS]; // Matriz de transições [estado][char]
    TokenType finalStates[MAX_STATES]; // Define se o estado é final e qual token representa
} DFA;

void initDFA(DFA *dfa); // Inicializa a tabela de transições
int nextState(DFA *dfa, int currentState, char input); // Retorna o próximo estado

#endif