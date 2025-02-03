#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/parser.h"
#include "../../include/parse_table.h"
#include "../../include/grammar.h" // Include grammar.h for grammar_rules and grammar_rule_sizes

// Pilha para a análise sintática LL(1)
#define MAX_STACK_SIZE 1000
static int stack[MAX_STACK_SIZE];
static int top = -1;

// Token atual
static Token current_token;
static int error_count = 0;

// Protótipos das funções auxiliares
void push(int symbol);
int pop();
int top_of_stack();
void synchronize(Lexer *lexer, DFA *dfa);          // Add DFA *dfa argument
const char *token_expected_string(TokenType type); // Update to const char *

// Avança para o próximo token
void advance(Lexer *lexer, DFA *dfa)
{                                                            // Add DFA *dfa argument
    current_token = getNextToken(lexer, dfa);                // Pass both lexer and dfa
    printf("Advanced to token: %s\n", current_token.lexeme); // Debug print
}

// Verifica se o token atual corresponde ao esperado
void match(Lexer *lexer, DFA *dfa, TokenType expected)
{ // Add DFA *dfa argument
    if (current_token.type == expected)
    {
        advance(lexer, dfa);
    }
    else
    {
        syntax_error(current_token);
        synchronize(lexer, dfa); // Add DFA *dfa argument
    }
}

// Inicia o parser usando a pilha
ASTNode *parse(Lexer *lexer, DFA *dfa)
{ // Add DFA *dfa argument
    push(NT_PROGRAM);
    advance(lexer, dfa);

    while (top >= 0)
    {
        int X = pop();
        printf("Processing symbol: %d\n", X); // Debug print

        if (X >= TOKEN_INT && X <= TOKEN_EOF)
        { // Se for terminal
            if (X == current_token.type)
            {
                advance(lexer, dfa);
            }
            else
            {
                syntax_error(current_token);
                synchronize(lexer, dfa); // Add DFA *dfa argument
            }
        }
        else
        { // Se for não terminal
            int rule = parseTable[X][current_token.type].productionRule;

            
            
            if (rule == -1)
            {
                syntax_error(current_token);
                synchronize(lexer, dfa); // Add DFA *dfa argument
            }
            else
            {
                const int *production = grammar_rules[rule];
                int production_size = grammar_rule_sizes[rule];
                for (int i = production_size - 1; i >= 0; i--)
                {
                    if (production[i] != -1)
                    { // -1 indica produção vazia (ε)
                        push(production[i]);
                    }
                }
            }
        }
    }

    if (error_count > 0)
    {
        printf("Parsing finalizado com %d erro(s).\n", error_count);
        return NULL;
    }

    // Create a dummy AST node for demonstration purposes
    ASTNode *root = (ASTNode *)malloc(sizeof(ASTNode));
    root->name = strdup("Program");
    root->num_children = 0;
    root->children = NULL;

    return root;
}

// Função para liberar a memória da AST
void free_ast(ASTNode *node)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < node->num_children; ++i)
    {
        free_ast(node->children[i]);
    }
    free(node->children);
    free(node->name);
    free(node);
}

// Empilha um símbolo na pilha
void push(int symbol)
{
    if (top < MAX_STACK_SIZE - 1)
    {
        stack[++top] = symbol;
    }
    else
    {
        fprintf(stderr, "Erro: Pilha do parser cheia.\n");
        exit(EXIT_FAILURE);
    }
}

// Desempilha um símbolo da pilha
int pop()
{
    if (top >= 0)
    {
        //print the stack
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        return stack[top--];
    }
    else
    {
        fprintf(stderr, "Erro: Pilha do parser vazia.\n");
        exit(EXIT_FAILURE);
    }
}

// Obtém o topo da pilha sem remover
int top_of_stack()
{
    if (top >= 0)
    {
        return stack[top];
    }
    else
    {
        fprintf(stderr, "Erro: Pilha do parser vazia.\n");
        exit(EXIT_FAILURE);
    }
}

// Função para imprimir erro sintático e registrar erro
void syntax_error(Token token)
{
    error_count++;
    printf("ERRO SINTATICO: \"%s\" INVALIDO [linha: %d], COLUNA %d. Esperado: %s\n",
           token.lexeme, token.line, token.column, // Use lexeme instead of value
           token_expected_string(token.type));
}

// Função de sincronização para recuperação de erro
void synchronize(Lexer *lexer, DFA *dfa)
{ // Add DFA *dfa argument
    while (current_token.type != TOKEN_SEMICOLON && current_token.type != TOKEN_EOF)
    {
        advance(lexer, dfa);
    }
    advance(lexer, dfa); // Avança para o próximo token válido
}

// Função para exibir a árvore sintática
void print_ast(ASTNode *node, int level)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < level; ++i)
    {
        printf("  "); // Indentação para representar a profundidade na árvore
    }
    printf("%s\n", node->name);
    for (int i = 0; i < node->num_children; ++i)
    {
        print_ast(node->children[i], level + 1);
    }
}

// Função auxiliar para obter uma string do nome do token esperado
const char *token_expected_string(TokenType type)
{ // Ensure return type matches declaration
    switch (type)
    {
    case TOKEN_INT:
        return "INT";
    case TOKEN_IF:
        return "IF";
    case TOKEN_ELSE:
        return "ELSE";
    case TOKEN_WHILE:
        return "WHILE";
    case TOKEN_RETURN:
        return "RETURN";
    case TOKEN_ID:
        return "IDENTIFICADOR";
    case TOKEN_NUM:
        return "NUMERO";
    case TOKEN_SEMICOLON:
        return "PONTO E VÍRGULA";
    case TOKEN_EOF:
        return "FIM DO ARQUIVO";
    default:
        return "TOKEN DESCONHECIDO";
    }
}