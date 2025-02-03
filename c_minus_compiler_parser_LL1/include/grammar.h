#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "token.h"

// Updated Non-Terminals to align with the LL(1) corrections
typedef enum {
    NT_PROGRAM,
    NT_DECLARATION_LIST,
    NT_DECLARATION_LIST_PRIME,
    NT_DECLARATION,
    NT_VAR_DECLARATION,
    NT_TYPE_SPECIFIER,
    NT_FUN_DECLARATION,
    NT_PARAMS,
    NT_PARAM_LIST,
    NT_PARAM_LIST_PRIME,
    NT_PARAM,
    NT_COMPOUND_STMT,
    NT_LOCAL_DECLARATIONS,
    NT_LOCAL_DECLARATIONS_PRIME,
    NT_STATEMENT_LIST,
    NT_STATEMENT_LIST_PRIME,
    NT_STATEMENT,
    NT_EXPRESSION_STMT,
    NT_SELECTION_STMT,
    NT_SELECTION_STMT_PRIME,
    NT_ITERATION_STMT,
    NT_RETURN_STMT,
    NT_RETURN_STMT_PRIME,
    NT_EXPRESSION,
    NT_ASSIGN_EXPR, // Introduced to remove left recursion
    NT_VAR,
    NT_VAR_PRIME,
    NT_SIMPLE_EXPRESSION,
    NT_SIMPLE_EXPRESSION_PRIME,
    NT_RELOP,
    NT_ADDITIVE_EXPRESSION,
    NT_ADDITIVE_EXPRESSION_PRIME,
    NT_ADDOP,
    NT_TERM,
    NT_TERM_PRIME,
    NT_MULOP,
    NT_FACTOR,
    NT_CALL,
    NT_ARGS,
    NT_ARG_LIST,
    NT_ARG_LIST_PRIME,
    NT_EMPTY // Epsilon productions
} NonTerminalType;

// Grammar rules declaration
extern const int *grammar_rules[];
extern const int grammar_rule_sizes[];

#endif // GRAMMAR_H
