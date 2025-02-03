#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lexer.h"
#include "../include/parser.h"

// Função auxiliar para imprimir o nome do token
const char* getTokenName(TokenType type) {
    switch (type) {
        case TOKEN_IF: return "IF";
        case TOKEN_ELSE: return "ELSE";
        case TOKEN_WHILE: return "WHILE";
        case TOKEN_RETURN: return "RETURN";
        case TOKEN_INT: return "INT";
        case TOKEN_VOID: return "VOID";
        case TOKEN_PLUS: return "PLUS";
        case TOKEN_MINUS: return "MINUS";
        case TOKEN_MULT: return "MULT";
        case TOKEN_DIV: return "DIV";
        case TOKEN_LT: return "LT";
        case TOKEN_LTE: return "LTE";
        case TOKEN_GT: return "GT";
        case TOKEN_GTE: return "GTE";
        case TOKEN_EQ: return "EQ";
        case TOKEN_NEQ: return "NEQ";
        case TOKEN_ASSIGN: return "ASSIGN";
        case TOKEN_SEMICOLON: return "SEMICOLON";
        case TOKEN_COMMA: return "COMMA";
        case TOKEN_LPAREN: return "LPAREN";
        case TOKEN_RPAREN: return "RPAREN";
        case TOKEN_LBRACE: return "LBRACE";
        case TOKEN_RBRACE: return "RBRACE";
        case TOKEN_LBRACKET: return "LBRACKET";
        case TOKEN_RBRACKET: return "RBRACKET";
        case TOKEN_NUMBER: return "NUMBER";
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_COMMENT: return "COMMENT";
        case TOKEN_WHITESPACE: return "WHITESPACE";
        case TOKEN_EOF: return "EOF";
        case TOKEN_ERROR: return "ERROR";
        case TOKEN_ID: return "ID";
        case TOKEN_NUM: return "NUM";
        default: return "UNKNOWN";
    }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo-fonte> [-p]\n", argv[0]);
        return EXIT_FAILURE;
    }

    Lexer lexer;
    DFA dfa;
    
    initDFA(&dfa);                // Inicializa o DFA com os estados
    initLexer(&lexer, argv[1]);   // Inicializa o Lexer com o arquivo de entrada

    if (argc > 2 && (strcmp(argv[2], "-p") == 0 || strcmp(argv[2], "-P") == 0)) {
        // Análise sintática e impressão da árvore sintática
        ASTNode *ast = parse(&lexer, &dfa); // Pass both lexer and dfa
        print_ast(ast, 0);
        free_ast(ast);
    } else {
        // Análise léxica
        printf("Tokens reconhecidos:\n");
        Token token;
        do {
            token = getNextToken(&lexer, &dfa);
            printf("<%s> \"%s\" [linha: %d, coluna: %d]\n", getTokenName(token.type), token.lexeme, token.line, token.column);
        } while (token.type != TOKEN_EOF);
    }

    closeLexer(&lexer); // Fecha o arquivo
    return EXIT_SUCCESS;
}