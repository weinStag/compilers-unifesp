#include "../../include/parse_table.h"

// Updated LL(1) Parse Table with refactored grammar
ParseTableEntry parseTable[NONTERMINAL_COUNT][TOKEN_COUNT];

// Initialize the LL(1) parse table
void initializeParseTable() {
    // program → declaration_list
    parseTable[NT_PROGRAM][TOKEN_INT].productionRule = 0;
    parseTable[NT_PROGRAM][TOKEN_VOID].productionRule = 0;

    // declaration_list → declaration declaration_list_prime
    parseTable[NT_DECLARATION_LIST][TOKEN_INT].productionRule = 1;
    parseTable[NT_DECLARATION_LIST][TOKEN_VOID].productionRule = 1;
    parseTable[NT_DECLARATION_LIST][TOKEN_EOF].productionRule = 2;

    // declaration_list_prime → ε | declaration declaration_list_prime
    parseTable[NT_DECLARATION_LIST_PRIME][TOKEN_INT].productionRule = 3;
    parseTable[NT_DECLARATION_LIST_PRIME][TOKEN_VOID].productionRule = 3;
    parseTable[NT_DECLARATION_LIST_PRIME][TOKEN_EOF].productionRule = 4;

    // declaration → var_declaration | fun_declaration
    parseTable[NT_DECLARATION][TOKEN_INT].productionRule = 5;
    parseTable[NT_DECLARATION][TOKEN_VOID].productionRule = 6;

    // var_declaration → type_specifier ID ; | type_specifier ID [ NUM ] ;
    parseTable[NT_VAR_DECLARATION][TOKEN_INT].productionRule = 7;
    parseTable[NT_VAR_DECLARATION][TOKEN_VOID].productionRule = 7;

    // type_specifier → int | void
    parseTable[NT_TYPE_SPECIFIER][TOKEN_INT].productionRule = 8;
    parseTable[NT_TYPE_SPECIFIER][TOKEN_VOID].productionRule = 9;

    // fun_declaration → type_specifier ID ( params ) compound_stmt
    parseTable[NT_FUN_DECLARATION][TOKEN_INT].productionRule = 10;
    parseTable[NT_FUN_DECLARATION][TOKEN_VOID].productionRule = 10;

    // params → param_list | void
    parseTable[NT_PARAMS][TOKEN_INT].productionRule = 11;
    parseTable[NT_PARAMS][TOKEN_VOID].productionRule = 12;

    // param_list → param param_list_prime
    parseTable[NT_PARAM_LIST][TOKEN_INT].productionRule = 13;
    parseTable[NT_PARAM_LIST][TOKEN_VOID].productionRule = 13;

    // param_list_prime → , param param_list_prime | ε
    parseTable[NT_PARAM_LIST_PRIME][TOKEN_COMMA].productionRule = 14;
    parseTable[NT_PARAM_LIST_PRIME][TOKEN_RPAREN].productionRule = 15;

    // param → type_specifier ID | type_specifier ID [ ]
    parseTable[NT_PARAM][TOKEN_INT].productionRule = 16;
    parseTable[NT_PARAM][TOKEN_VOID].productionRule = 16;

    // compound_stmt → { local_declarations statement_list }
    parseTable[NT_COMPOUND_STMT][TOKEN_LBRACE].productionRule = 17;

    // local_declarations → local_declarations_prime
    parseTable[NT_LOCAL_DECLARATIONS][TOKEN_INT].productionRule = 18;
    parseTable[NT_LOCAL_DECLARATIONS][TOKEN_VOID].productionRule = 18;
    parseTable[NT_LOCAL_DECLARATIONS][TOKEN_RBRACE].productionRule = 19;

    // statement_list → statement_list_prime
    parseTable[NT_STATEMENT_LIST][TOKEN_INT].productionRule = 20;
    parseTable[NT_STATEMENT_LIST][TOKEN_VOID].productionRule = 20;
    parseTable[NT_STATEMENT_LIST][TOKEN_IF].productionRule = 20;
    parseTable[NT_STATEMENT_LIST][TOKEN_WHILE].productionRule = 20;
    parseTable[NT_STATEMENT_LIST][TOKEN_RETURN].productionRule = 20;
    parseTable[NT_STATEMENT_LIST][TOKEN_ID].productionRule = 20;
    parseTable[NT_STATEMENT_LIST][TOKEN_LBRACE].productionRule = 20;
    parseTable[NT_STATEMENT_LIST][TOKEN_RBRACE].productionRule = 21;

    // statement → expression_stmt | compound_stmt | selection_stmt | iteration_stmt | return_stmt
    parseTable[NT_STATEMENT][TOKEN_INT].productionRule = 22;
    parseTable[NT_STATEMENT][TOKEN_VOID].productionRule = 22;
    parseTable[NT_STATEMENT][TOKEN_IF].productionRule = 24;
    parseTable[NT_STATEMENT][TOKEN_WHILE].productionRule = 25;
    parseTable[NT_STATEMENT][TOKEN_RETURN].productionRule = 26;
    parseTable[NT_STATEMENT][TOKEN_ID].productionRule = 22;
    parseTable[NT_STATEMENT][TOKEN_LBRACE].productionRule = 23;

    // expression_stmt → expression ; | ;
    parseTable[NT_EXPRESSION_STMT][TOKEN_ID].productionRule = 27;
    parseTable[NT_EXPRESSION_STMT][TOKEN_NUM].productionRule = 27;
    parseTable[NT_EXPRESSION_STMT][TOKEN_SEMICOLON].productionRule = 28;

    // selection_stmt → if ( expression ) statement selection_stmt_prime
    parseTable[NT_SELECTION_STMT][TOKEN_IF].productionRule = 29;
    
    // selection_stmt_prime → else statement | ε
    parseTable[NT_SELECTION_STMT_PRIME][TOKEN_ELSE].productionRule = 30;
    parseTable[NT_SELECTION_STMT_PRIME][TOKEN_RBRACE].productionRule = 31;
    
    // iteration_stmt → while ( expression ) statement
    parseTable[NT_ITERATION_STMT][TOKEN_WHILE].productionRule = 32;

    // return_stmt → return return_stmt_prime
    parseTable[NT_RETURN_STMT][TOKEN_RETURN].productionRule = 33;
    
    // return_stmt_prime → expression ; | ;
    parseTable[NT_RETURN_STMT_PRIME][TOKEN_ID].productionRule = 34;
    parseTable[NT_RETURN_STMT_PRIME][TOKEN_NUM].productionRule = 34;
    parseTable[NT_RETURN_STMT_PRIME][TOKEN_SEMICOLON].productionRule = 35;
}