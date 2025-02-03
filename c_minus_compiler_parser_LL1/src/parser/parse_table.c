#include "../../include/parse_table.h"

// Tabela de parsing LL(1)
ParseTableEntry parseTable[NONTERMINAL_COUNT][TOKEN_COUNT];

// Inicializa a tabela LL(1) com as regras da gramática
void initializeParseTable() {
    // program → declaration_list
    parseTable[NT_PROGRAM][TOKEN_INT].productionRule = 0;
    parseTable[NT_PROGRAM][TOKEN_VOID].productionRule = 0;

    // declaration_list → declaration declaration_list | ε
    parseTable[NT_DECLARATION_LIST][TOKEN_INT].productionRule = 1;
    parseTable[NT_DECLARATION_LIST][TOKEN_VOID].productionRule = 1;
    parseTable[NT_DECLARATION_LIST][TOKEN_EOF].productionRule = 2;

    // declaration → var_declaration | fun_declaration
    parseTable[NT_DECLARATION][TOKEN_INT].productionRule = 3;
    parseTable[NT_DECLARATION][TOKEN_VOID].productionRule = 4;

    // var_declaration → type_specifier ID ; | type_specifier ID [ NUM ] ;
    parseTable[NT_VAR_DECLARATION][TOKEN_INT].productionRule = 5;
    parseTable[NT_VAR_DECLARATION][TOKEN_VOID].productionRule = 5;

    // type_specifier → int | void
    parseTable[NT_TYPE_SPECIFIER][TOKEN_INT].productionRule = 6;
    parseTable[NT_TYPE_SPECIFIER][TOKEN_VOID].productionRule = 7;

    // fun_declaration → type_specifier ID ( params ) compound_stmt
    parseTable[NT_FUN_DECLARATION][TOKEN_INT].productionRule = 8;
    parseTable[NT_FUN_DECLARATION][TOKEN_VOID].productionRule = 8;

    // params → param_list | void
    parseTable[NT_PARAMS][TOKEN_INT].productionRule = 9;
    parseTable[NT_PARAMS][TOKEN_VOID].productionRule = 10;

    // param_list → param param_list’ 
    parseTable[NT_PARAM_LIST][TOKEN_INT].productionRule = 11;
    parseTable[NT_PARAM_LIST][TOKEN_VOID].productionRule = 11;

    // param_list’ → , param param_list’ | ε
    parseTable[NT_PARAM_LIST][TOKEN_COMMA].productionRule = 12;
    parseTable[NT_PARAM_LIST][TOKEN_RPAREN].productionRule = 13;

    // param → type_specifier ID | type_specifier ID [ ]
    parseTable[NT_PARAM][TOKEN_INT].productionRule = 14;
    parseTable[NT_PARAM][TOKEN_VOID].productionRule = 14;

    // compound_stmt → { local_declarations statement_list }
    parseTable[NT_COMPOUND_STMT][TOKEN_LBRACE].productionRule = 15;

    // local_declarations → local_declarations var_declaration | ε
    parseTable[NT_LOCAL_DECLARATIONS][TOKEN_INT].productionRule = 16;
    parseTable[NT_LOCAL_DECLARATIONS][TOKEN_VOID].productionRule = 16;
    parseTable[NT_LOCAL_DECLARATIONS][TOKEN_RBRACE].productionRule = 17;

    // statement_list → statement_list statement | ε
    parseTable[NT_STATEMENT_LIST][TOKEN_INT].productionRule = 18;
    parseTable[NT_STATEMENT_LIST][TOKEN_VOID].productionRule = 18;
    parseTable[NT_STATEMENT_LIST][TOKEN_IF].productionRule = 18;
    parseTable[NT_STATEMENT_LIST][TOKEN_WHILE].productionRule = 18;
    parseTable[NT_STATEMENT_LIST][TOKEN_RETURN].productionRule = 18;
    parseTable[NT_STATEMENT_LIST][TOKEN_ID].productionRule = 18;
    parseTable[NT_STATEMENT_LIST][TOKEN_LBRACE].productionRule = 18;
    parseTable[NT_STATEMENT_LIST][TOKEN_RBRACE].productionRule = 19;

    // statement → expression_stmt | compound_stmt | selection_stmt | iteration_stmt | return_stmt
    parseTable[NT_STATEMENT][TOKEN_INT].productionRule = 20;
    parseTable[NT_STATEMENT][TOKEN_VOID].productionRule = 20;
    parseTable[NT_STATEMENT][TOKEN_IF].productionRule = 22;
    parseTable[NT_STATEMENT][TOKEN_WHILE].productionRule = 23;
    parseTable[NT_STATEMENT][TOKEN_RETURN].productionRule = 24;
    parseTable[NT_STATEMENT][TOKEN_ID].productionRule = 20;
    parseTable[NT_STATEMENT][TOKEN_LBRACE].productionRule = 21;

    // expression_stmt → expression ; | ;
    parseTable[NT_EXPRESSION_STMT][TOKEN_ID].productionRule = 25;
    parseTable[NT_EXPRESSION_STMT][TOKEN_NUM].productionRule = 25;
    parseTable[NT_EXPRESSION_STMT][TOKEN_SEMICOLON].productionRule = 26;

    // selection_stmt → if ( expression ) statement | if ( expression ) statement else statement
    parseTable[NT_SELECTION_STMT][TOKEN_IF].productionRule = 27;
    parseTable[NT_SELECTION_STMT][TOKEN_ELSE].productionRule = 28;

    // iteration_stmt → while ( expression ) statement
    parseTable[NT_ITERATION_STMT][TOKEN_WHILE].productionRule = 29;

    // return_stmt → return ; | return expression ;
    parseTable[NT_RETURN_STMT][TOKEN_RETURN].productionRule = 30;
    parseTable[NT_RETURN_STMT][TOKEN_ID].productionRule = 31;
    parseTable[NT_RETURN_STMT][TOKEN_NUM].productionRule = 31;

    // expression → var = expression | simple_expression
    parseTable[NT_EXPRESSION][TOKEN_ID].productionRule = 32;
    parseTable[NT_EXPRESSION][TOKEN_NUM].productionRule = 33;

    // var → ID | ID [ expression ]
    parseTable[NT_VAR][TOKEN_ID].productionRule = 34;

    // simple_expression → additive_expression relop additive_expression | additive_expression
    parseTable[NT_SIMPLE_EXPRESSION][TOKEN_ID].productionRule = 35;
    parseTable[NT_SIMPLE_EXPRESSION][TOKEN_NUM].productionRule = 35;

    // relop → <= | < | > | >= | == | !=
    parseTable[NT_RELOP][TOKEN_LTE].productionRule = 36;
    parseTable[NT_RELOP][TOKEN_LT].productionRule = 37;
    parseTable[NT_RELOP][TOKEN_GT].productionRule = 38;
    parseTable[NT_RELOP][TOKEN_GTE].productionRule = 39;
    parseTable[NT_RELOP][TOKEN_EQ].productionRule = 40;
    parseTable[NT_RELOP][TOKEN_NEQ].productionRule = 41;

    // additive_expression → additive_expression addop term | term
    parseTable[NT_ADDITIVE_EXPRESSION][TOKEN_ID].productionRule = 42;
    parseTable[NT_ADDITIVE_EXPRESSION][TOKEN_NUM].productionRule = 42;

    // addop → + | -
    parseTable[NT_ADDOP][TOKEN_PLUS].productionRule = 43;
    parseTable[NT_ADDOP][TOKEN_MINUS].productionRule = 44;

    // term → term mulop factor | factor
    parseTable[NT_TERM][TOKEN_ID].productionRule = 45;
    parseTable[NT_TERM][TOKEN_NUM].productionRule = 45;

    // mulop → * | /
    parseTable[NT_MULOP][TOKEN_MULT].productionRule = 46;
    parseTable[NT_MULOP][TOKEN_DIV].productionRule = 47;

    // factor → ( expression ) | var | call | NUM
    parseTable[NT_FACTOR][TOKEN_LPAREN].productionRule = 48;
    parseTable[NT_FACTOR][TOKEN_ID].productionRule = 49;
    parseTable[NT_FACTOR][TOKEN_NUM].productionRule = 50;

    // call → ID ( args )
    parseTable[NT_CALL][TOKEN_ID].productionRule = 51;

    // args → arg_list | ε
    parseTable[NT_ARGS][TOKEN_ID].productionRule = 52;
    parseTable[NT_ARGS][TOKEN_NUM].productionRule = 52;
    parseTable[NT_ARGS][TOKEN_RPAREN].productionRule = 53;

    // arg_list → expression arg_list’
    parseTable[NT_ARG_LIST][TOKEN_ID].productionRule = 54;
    parseTable[NT_ARG_LIST][TOKEN_NUM].productionRule = 54;

    // arg_list’ → , expression arg_list’ | ε
    parseTable[NT_ARG_LIST][TOKEN_COMMA].productionRule = 55;
    parseTable[NT_ARG_LIST][TOKEN_RPAREN].productionRule = 56;
    parseTable[NT_FACTOR][TOKEN_NUM].productionRule = 58;

    // call → ID ( args )
    parseTable[NT_CALL][TOKEN_ID].productionRule = 59;

    // args → arg_list | ε
    parseTable[NT_ARGS][TOKEN_ID].productionRule = 60;
    parseTable[NT_ARGS][TOKEN_NUM].productionRule = 60;
    parseTable[NT_ARGS][TOKEN_RPAREN].productionRule = 61;

    // arg_list → expression arg_list’
    parseTable[NT_ARG_LIST][TOKEN_ID].productionRule = 62;
    parseTable[NT_ARG_LIST][TOKEN_NUM].productionRule = 62;

    // arg_list’ → , expression arg_list’ | ε
    parseTable[NT_ARG_LIST][TOKEN_COMMA].productionRule = 63;
    parseTable[NT_ARG_LIST][TOKEN_RPAREN].productionRule = 64;
}