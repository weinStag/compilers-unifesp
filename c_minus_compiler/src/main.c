#include <stdio.h>
#include <stdlib.h>
#include "../include/lexer.h"  // Agora inclui lexer.h, que já inclui o token.h e o dfa.h

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo-fonte>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Lexer lexer;
    DFA dfa;
    
    initDFA(&dfa);           // Inicializa o DFA com os estados
    initLexer(&lexer, argv[1]); // Inicializa o Lexer com o arquivo de entrada

    printf("Tokens reconhecidos:\n");

    Token token;
    do {
        token = getNextToken(&lexer, &dfa);  // Agora está correto
        printf("<%d> \"%s\" [linha: %d, coluna: %d]\n", token.type, token.lexeme, token.line, token.column);
    } while (token.type != TOKEN_EOF);

    closeLexer(&lexer); // Fecha o arquivo
    return EXIT_SUCCESS;
}
