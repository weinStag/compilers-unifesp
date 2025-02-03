#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H

#include "grammar.h"

#define NONTERMINAL_COUNT 25  // Número de não terminais (ajuste conforme necessário)
#define TOKEN_COUNT 26        // Número de tokens reconhecidos

// Definição da entrada da tabela LL(1)
typedef struct {
    int productionRule;  // Índice da regra de produção na gramática
} ParseTableEntry;

// Matriz da tabela de parsing
extern ParseTableEntry parseTable[NONTERMINAL_COUNT][TOKEN_COUNT];

// Inicializa a tabela de parsing LL(1)
void initializeParseTable();

#endif // PARSE_TABLE_H
