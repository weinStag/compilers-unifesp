#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lexer.h"
#include "../include/parser.h"

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
            printf("<%d> \"%s\" [linha: %d, coluna: %d]\n", token.type, token.lexeme, token.line, token.column);
        } while (token.type != TOKEN_EOF);
    }

    closeLexer(&lexer); // Fecha o arquivo
    return EXIT_SUCCESS;
}