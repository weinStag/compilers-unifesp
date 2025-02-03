#include "../../include/dfa.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Inicializa o DFA com estados de erro (-1)
void initDFA(DFA *dfa) {
    memset(dfa->transitions, -1, sizeof(dfa->transitions));
    memset(dfa->finalStates, -1, sizeof(dfa->finalStates));

    // --- NÚMEROS ---
    dfa->transitions[0]['0'] = 1;  // Número "0" isolado
    for (char c = '1'; c <= '9'; c++) dfa->transitions[0][(int)c] = 2; // Início de um número
    for (char c = '0'; c <= '9'; c++) dfa->transitions[2][(int)c] = 2; // Continuação de um número
    dfa->finalStates[1] = TOKEN_NUMBER;
    dfa->finalStates[2] = TOKEN_NUMBER;

    // --- IDENTIFICADORES E PALAVRAS-CHAVE ---
    for (char c = 'a'; c <= 'z'; c++) dfa->transitions[0][(int)c] = 3;
    for (char c = 'A'; c <= 'Z'; c++) dfa->transitions[0][(int)c] = 3;
    dfa->transitions[0]['_'] = 3;
    for (char c = 'a'; c <= 'z'; c++) dfa->transitions[3][(int)c] = 3;
    for (char c = 'A'; c <= 'Z'; c++) dfa->transitions[3][(int)c] = 3;
    for (char c = '0'; c <= '9'; c++) dfa->transitions[3][(int)c] = 3;
    dfa->transitions[3]['_'] = 3;
    dfa->finalStates[3] = TOKEN_IDENTIFIER;

    // --- OPERADORES ---
    dfa->transitions[0]['+'] = 4;
    dfa->transitions[0]['-'] = 5;
    dfa->transitions[0]['*'] = 6;
    dfa->transitions[0]['/'] = 7;
    dfa->transitions[0]['<'] = 8;
    dfa->transitions[0]['>'] = 9;
    dfa->transitions[0]['='] = 10;
    dfa->transitions[0]['!'] = 11;

    dfa->finalStates[4] = TOKEN_PLUS;
    dfa->finalStates[5] = TOKEN_MINUS;
    dfa->finalStates[6] = TOKEN_MULT;
    
    // Comparadores e operadores compostos
    dfa->transitions[8]['='] = 12; dfa->finalStates[8] = TOKEN_LT;   // < ou <=
    dfa->transitions[9]['='] = 13; dfa->finalStates[9] = TOKEN_GT;   // > ou >=
    dfa->transitions[10]['='] = 14; dfa->finalStates[10] = TOKEN_ASSIGN; // = ou ==
    dfa->transitions[11]['='] = 15; dfa->finalStates[11] = TOKEN_ERROR; // ! ou !=
    dfa->finalStates[12] = TOKEN_LTE;
    dfa->finalStates[13] = TOKEN_GTE;
    dfa->finalStates[14] = TOKEN_EQ;
    dfa->finalStates[15] = TOKEN_NEQ;

    // --- COMENTÁRIOS ---
    dfa->transitions[7]['/'] = 16;  // "//" -> Comentário de linha
    dfa->transitions[7]['*'] = 17;  // "/*" -> Comentário de bloco
    dfa->finalStates[7] = TOKEN_DIV;  // "/" isolado

    // Comentário de linha continua até \n
    for (int i = 0; i < MAX_CHARS; i++) dfa->transitions[16][i] = 16;
    dfa->transitions[16]['\n'] = -1;
    dfa->finalStates[16] = TOKEN_COMMENT;

    // Comentário de bloco
    for (int i = 0; i < MAX_CHARS; i++) dfa->transitions[17][i] = 17;
    dfa->transitions[17]['*'] = 18;
    dfa->transitions[18]['/'] = -1;
    dfa->finalStates[17] = TOKEN_COMMENT;

    // --- SÍMBOLOS ESPECIAIS ---
    dfa->transitions[0][';'] = 19; dfa->finalStates[19] = TOKEN_SEMICOLON;
    dfa->transitions[0][','] = 20; dfa->finalStates[20] = TOKEN_COMMA;
    dfa->transitions[0]['('] = 21; dfa->finalStates[21] = TOKEN_LPAREN;
    dfa->transitions[0][')'] = 22; dfa->finalStates[22] = TOKEN_RPAREN;
    dfa->transitions[0]['{'] = 23; dfa->finalStates[23] = TOKEN_LBRACE;
    dfa->transitions[0]['}'] = 24; dfa->finalStates[24] = TOKEN_RBRACE;
    dfa->transitions[0]['['] = 25; dfa->finalStates[25] = TOKEN_LBRACKET;
    dfa->transitions[0][']'] = 26; dfa->finalStates[26] = TOKEN_RBRACKET;

    // --- ESPAÇOS EM BRANCO ---
    dfa->transitions[0][' '] = 27;
    dfa->transitions[0]['\t'] = 27;
    dfa->transitions[0]['\n'] = 27;
    dfa->transitions[0]['\r'] = 27;
    dfa->finalStates[27] = TOKEN_WHITESPACE;

    // --- ERROS ---
    for (int i = 0; i < MAX_CHARS; i++) {
        if (dfa->transitions[0][i] == -1) {
            dfa->transitions[0][i] = 28; // Qualquer caractere inválido vai para o estado de erro
        }
    }
    dfa->finalStates[28] = TOKEN_ERROR;
}

// Retorna o próximo estado baseado no caractere de entrada
int nextState(DFA *dfa, int currentState, char input) {
    return dfa->transitions[currentState][(int)input];
}
