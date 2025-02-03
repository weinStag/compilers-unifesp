#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Estrutura para representar um nó da árvore sintática
typedef struct ASTNode {
    char *name;
    struct ASTNode **children;
    int num_children;
} ASTNode;

// Função para iniciar o analisador sintático
ASTNode *parse(Lexer *lexer, DFA *dfa); // Update prototype

// Função para exibir a árvore sintática
void print_ast(ASTNode *node, int level);

// Função para lidar com erros sintáticos
void syntax_error(Token token);

// Função para liberar a memória da AST
void free_ast(ASTNode *node);

#endif // PARSER_H