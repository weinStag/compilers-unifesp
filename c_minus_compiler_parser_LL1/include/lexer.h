#ifndef LEXER_H
#define LEXER_H

#include "dfa.h"  // Make sure this is included before using DFA
#include "token.h"  // TokenType and Token might be needed here

#include <stdio.h>

// Token structure and Lexer structure as usual
typedef struct {
    TokenType type;
    char *lexeme;  // Dynamically allocated memory for lexeme
    int line;
    int column;
} Token;

typedef struct {
    FILE *file;
    int line;
    int column;
    char currentChar;
} Lexer;

// Function declarations
void initLexer(Lexer *lexer, const char *filename);
void closeLexer(Lexer *lexer);
void advance_lexer(Lexer *lexer);
Token getNextToken(Lexer *lexer, DFA *dfa);  // Using DFA here

#endif
