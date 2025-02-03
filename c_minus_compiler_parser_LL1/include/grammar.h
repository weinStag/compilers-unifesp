#ifndef GRAMMAR_H
#define GRAMMAR_H

// Include token.h to use the TokenType enum
#include "token.h"

// Definição dos não terminais da gramática C-
typedef enum {
    NT_PROGRAM,
    NT_DECLARATION_LIST,
    NT_DECLARATION_LIST_PRIME, // Adicionado
    NT_DECLARATION,
    NT_VAR_DECLARATION,
    NT_TYPE_SPECIFIER,
    NT_FUN_DECLARATION,
    NT_PARAMS,
    NT_PARAM_LIST,
    NT_PARAM_LIST_PRIME, // Adicionado
    NT_PARAM,
    NT_COMPOUND_STMT,
    NT_LOCAL_DECLARATIONS,
    NT_LOCAL_DECLARATIONS_PRIME, // Adicionado
    NT_STATEMENT_LIST,
    NT_STATEMENT_LIST_PRIME, // Adicionado
    NT_STATEMENT,
    NT_EXPRESSION_STMT,
    NT_SELECTION_STMT,
    NT_SELECTION_STMT_PRIME, // Adicionado
    NT_ITERATION_STMT,
    NT_RETURN_STMT,
    NT_RETURN_STMT_PRIME, // Adicionado
    NT_EXPRESSION,
    NT_VAR,
    NT_VAR_PRIME, // Adicionado
    NT_SIMPLE_EXPRESSION,
    NT_SIMPLE_EXPRESSION_PRIME, // Adicionado
    NT_RELOP,
    NT_ADDITIVE_EXPRESSION,
    NT_ADDITIVE_EXPRESSION_PRIME, // Adicionado
    NT_ADDOP,
    NT_TERM,
    NT_TERM_PRIME, // Adicionado
    NT_MULOP,
    NT_FACTOR,
    NT_CALL,
    NT_ARGS,
    NT_ARG_LIST,
    NT_ARG_LIST_PRIME, // Adicionado
    NT_EMPTY // Adicionado NT_EMPTY para epsilon-produções
} NonTerminalType;

// Declare grammar rules and their sizes
extern const int *grammar_rules[];
extern const int grammar_rule_sizes[];

#endif // GRAMMAR_H