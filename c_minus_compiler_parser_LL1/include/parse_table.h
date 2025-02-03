#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H

#include "grammar.h"

#define NONTERMINAL_COUNT 40  // Updated based on refactored grammar
#define TOKEN_COUNT 26        // Number of recognized tokens

// Structure for the LL(1) parse table entry
typedef struct {
    int productionRule;  // Index of the production rule in the grammar
} ParseTableEntry;

// LL(1) Parse Table Declaration
extern ParseTableEntry parseTable[NONTERMINAL_COUNT][TOKEN_COUNT];

// Function to initialize the LL(1) parse table
void initializeParseTable();

#endif // PARSE_TABLE_H