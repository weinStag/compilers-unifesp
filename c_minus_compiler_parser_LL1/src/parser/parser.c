#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/parser.h"
#include "../../include/parse_table.h"
#include "../../include/grammar.h"

#define MAX_STACK_SIZE 1000
static int stack[MAX_STACK_SIZE];
static int top = -1;
static Token current_token;
static int error_count = 0;
static int last_nonterminal = -1;
static int last_rule_applied = -1;
static TokenType last_token_type = -1;
static int stagnation_count = 0;
#define MAX_STAGNATION 3 // Prevent infinite loop by limiting stagnation

void push(int symbol);
int pop();
int top_of_stack();
void synchronize(Lexer *lexer, DFA *dfa);
const char *token_expected_string(TokenType type);

void advance(Lexer *lexer, DFA *dfa) {
    current_token = getNextToken(lexer, dfa);
    printf("Advanced to token: %s (%d)\n", current_token.lexeme, current_token.type);
}

void match(Lexer *lexer, DFA *dfa, TokenType expected) {
    if (current_token.type == expected) {
        advance(lexer, dfa);
    } else {
        syntax_error(current_token);
        synchronize(lexer, dfa);
    }
}

ASTNode *parse(Lexer *lexer, DFA *dfa) {
    push(NT_PROGRAM);
    advance(lexer, dfa);

    while (top >= 0) {
        int X = pop();
        
        printf("Stack state: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\nProcessing symbol: %d\n", X);

        if (X >= TOKEN_INT && X <= TOKEN_EOF) {
            if (X == current_token.type) {
                advance(lexer, dfa);
                stagnation_count = 0; // Reset stagnation count on progress
            } else {
                syntax_error(current_token);
                synchronize(lexer, dfa);
            }
        } else {
            printf("Current Token: %d (%s)\n", current_token.type, current_token.lexeme);
            if (current_token.type == TOKEN_EOF) {
                printf("✅ Reached EOF, stopping parsing.\n");
                break;
            }
            
            int rule = parseTable[X][current_token.type].productionRule;

            if (rule == -1) {
                printf("🚨 No rule found for symbol %d with token %d\n", X, current_token.type);
                syntax_error(current_token);
                synchronize(lexer, dfa);
            } else {
                if (X == last_nonterminal && rule == last_rule_applied && current_token.type == last_token_type) {
                    stagnation_count++;
                    printf("⚠️ Potential infinite loop detected! Stagnation count: %d\n", stagnation_count);
                    if (stagnation_count >= MAX_STAGNATION) {
                        printf("🚨 Stagnation limit reached. Forcing parse exit.\n");
                        break; // Stop parsing if stuck
                    }
                } else {
                    stagnation_count = 0;
                }
                
                last_nonterminal = X;
                last_rule_applied = rule;
                last_token_type = current_token.type;
                
                printf("✅ Applying rule %d for symbol %d\n", rule, X);
                const int *production = grammar_rules[rule];
                int production_size = grammar_rule_sizes[rule];

                if (production_size == 1 && production[0] == NT_EMPTY) {
                    printf("⚠️ Empty production for symbol %d, skipping push.\n", X);
                    continue;
                }
                
                printf("🔁 Pushing symbols onto stack: ");
                for (int i = production_size - 1; i >= 0; i--) {
                    if (production[i] != -1) {
                        printf("%d ", production[i]);
                        push(production[i]);
                    }
                }
                printf("\n");
            }
        }
    }

    if (error_count > 0) {
        printf("Parsing finished with %d error(s).\n", error_count);
        return NULL;
    }

    ASTNode *root = (ASTNode *)malloc(sizeof(ASTNode));
    root->name = strdup("Program");
    root->num_children = 0;
    root->children = NULL;

    return root;
}

void free_ast(ASTNode *node) {
    if (node == NULL) return;
    for (int i = 0; i < node->num_children; ++i) {
        free_ast(node->children[i]);
    }
    free(node->children);
    free(node->name);
    free(node);
}

void push(int symbol) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = symbol;
    } else {
        fprintf(stderr, "Error: Parser stack overflow.\n");
        exit(EXIT_FAILURE);
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        fprintf(stderr, "Error: Parser stack underflow.\n");
        exit(EXIT_FAILURE);
    }
}

void syntax_error(Token token) {
    error_count++;
    printf("Syntax Error: \"%s\" invalid [line: %d, column: %d]. Expected: %s\n",
           token.lexeme, token.line, token.column,
           token_expected_string(token.type));
}

void synchronize(Lexer *lexer, DFA *dfa) {
    printf("Synchronizing...\n");
    while (current_token.type != TOKEN_SEMICOLON && current_token.type != TOKEN_EOF) {
        printf("Skipping token: %s\n", current_token.lexeme);
        advance(lexer, dfa);
    }
    advance(lexer, dfa);
}


void print_ast(ASTNode *node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; ++i) {
        printf("  ");
    }
    printf("%s\n", node->name);
    for (int i = 0; i < node->num_children; ++i) {
        print_ast(node->children[i], level + 1);
    }
}

const char *token_expected_string(TokenType type) {
    switch (type) {
    case TOKEN_INT: return "INT";
    case TOKEN_IF: return "IF";
    case TOKEN_ELSE: return "ELSE";
    case TOKEN_WHILE: return "WHILE";
    case TOKEN_RETURN: return "RETURN";
    case TOKEN_ID: return "IDENTIFIER";
    case TOKEN_NUM: return "NUMBER";
    case TOKEN_SEMICOLON: return "SEMICOLON";
    case TOKEN_EOF: return "EOF";
    default: return "UNKNOWN TOKEN";
    }
}