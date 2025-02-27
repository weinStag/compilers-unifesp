#include "../../include/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Inicializa o lexer com um arquivo de entrada
void initLexer(Lexer *lexer, const char *filename)
{
    lexer->file = fopen(filename, "r");
    if (!lexer->file)
    {
        fprintf(stderr, "Erro ao abrir o arquivo: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    lexer->line = 1;
    lexer->column = 1;
    lexer->currentChar = fgetc(lexer->file);
}

// Fecha o arquivo associado ao lexer
void closeLexer(Lexer *lexer)
{
    if (lexer->file)
        fclose(lexer->file);
}

// Avança para o próximo caractere no arquivo
void advance_lexer(Lexer *lexer)
{
    if (lexer->currentChar == '\n')
    {
        lexer->line++;
        lexer->column = 1;
    }
    else
    {
        lexer->column++;
    }
    lexer->currentChar = fgetc(lexer->file);
}

TokenType checkReservedWord(const char *lexeme)
{
    if (strcmp(lexeme, "int") == 0)
        return TOKEN_INT;
    if (strcmp(lexeme, "if") == 0)
        return TOKEN_IF;
    if (strcmp(lexeme, "else") == 0)
        return TOKEN_ELSE;
    if (strcmp(lexeme, "return") == 0)
        return TOKEN_RETURN;
    if (strcmp(lexeme, "while") == 0)
        return TOKEN_WHILE;
    if (strcmp(lexeme, "void") == 0)
        return TOKEN_VOID;
    return TOKEN_IDENTIFIER; // Default to IDENTIFIER if not a keyword
}

// Obtém o próximo token da entrada
Token getNextToken(Lexer *lexer, DFA *dfa)
{
    Token token;
    token.type = TOKEN_ERROR;
    token.line = lexer->line;
    token.column = lexer->column;
    token.lexeme = (char *)malloc(100 * sizeof(char)); // Initial allocation of 100 bytes
    token.lexeme[0] = '\0';                            // Initialize lexeme as an empty string

    // Ignorar espaços em branco e novas linhas
    while (lexer->currentChar != EOF && isspace(lexer->currentChar))
    {
        advance_lexer(lexer);
    }

    if (lexer->currentChar == EOF)
    {
        token.type = TOKEN_EOF;
        strcpy(token.lexeme, "EOF");
        return token;
    }

    int state = 0;
    int next = 0;
    int lexemeLen = 0;
    int startColumn = lexer->column;

    // Start with an initial buffer size for lexeme
    int lexemeBufferSize = 100;
    char *lexeme = (char *)malloc(lexemeBufferSize * sizeof(char));

    while (lexer->currentChar != EOF)
    {
        next = nextState(dfa, state, lexer->currentChar);

        if (next == -1)
            break; // Stop if we hit an error state

        // Ensure there's enough space in lexeme buffer
        if (lexemeLen >= lexemeBufferSize - 1)
        {
            lexemeBufferSize *= 2; // Double the buffer size
            lexeme = (char *)realloc(lexeme, lexemeBufferSize * sizeof(char));
        }

        lexeme[lexemeLen++] = lexer->currentChar;
        lexeme[lexemeLen] = '\0'; // Null-terminate the string

        state = next;
        advance_lexer(lexer);
    }

    if (dfa->finalStates[state] != -1)
    {
        token.type = dfa->finalStates[state];

        // Reserved Word Check (Fix)
        if (token.type == TOKEN_IDENTIFIER)
        {
            token.type = checkReservedWord(lexeme);
        }

        token.lexeme = lexeme; // Assign dynamically allocated lexeme to token
    }
    else
    {
        token.type = TOKEN_ERROR;
        snprintf(token.lexeme, lexemeBufferSize, "ERRO LEXICO: \"%s\" INVALIDO [linha: %d], COLUNA %d.", lexeme, lexer->line, startColumn);
        free(lexeme); // Free the old lexeme buffer if it's used in error case
    }

    token.line = lexer->line;
    token.column = startColumn;
    return token;
}