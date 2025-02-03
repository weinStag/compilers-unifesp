#include "../../include/grammar.h"

// Define the updated grammar rules based on the refactored grammar
const int rule1[] = {NT_DECLARATION_LIST};
const int rule2[] = {NT_DECLARATION, NT_DECLARATION_LIST_PRIME};
const int rule3[] = {NT_EMPTY};
const int rule4[] = {NT_VAR_DECLARATION};
const int rule5[] = {NT_FUN_DECLARATION};
const int rule6[] = {NT_TYPE_SPECIFIER, TOKEN_ID, TOKEN_SEMICOLON};
const int rule7[] = {NT_TYPE_SPECIFIER, TOKEN_ID, TOKEN_LBRACKET, TOKEN_NUM, TOKEN_RBRACKET, TOKEN_SEMICOLON};
const int rule8[] = {TOKEN_INT};
const int rule9[] = {TOKEN_VOID};
const int rule10[] = {NT_TYPE_SPECIFIER, TOKEN_ID, TOKEN_LPAREN, NT_PARAMS, TOKEN_RPAREN, NT_COMPOUND_STMT};
const int rule11[] = {NT_PARAM_LIST};
const int rule12[] = {TOKEN_VOID};
const int rule13[] = {NT_PARAM, NT_PARAM_LIST_PRIME};
const int rule14[] = {TOKEN_COMMA, NT_PARAM, NT_PARAM_LIST_PRIME};
const int rule15[] = {NT_EMPTY};
const int rule16[] = {NT_TYPE_SPECIFIER, TOKEN_ID};
const int rule17[] = {NT_TYPE_SPECIFIER, TOKEN_ID, TOKEN_LBRACKET, TOKEN_RBRACKET};
const int rule18[] = {TOKEN_LBRACE, NT_LOCAL_DECLARATIONS, NT_STATEMENT_LIST, TOKEN_RBRACE};
const int rule19[] = {NT_VAR_DECLARATION, NT_LOCAL_DECLARATIONS_PRIME};
const int rule20[] = {NT_EMPTY};
const int rule21[] = {NT_STATEMENT, NT_STATEMENT_LIST_PRIME};
const int rule22[] = {NT_EMPTY};
const int rule23[] = {NT_EXPRESSION_STMT};
const int rule24[] = {NT_COMPOUND_STMT};
const int rule25[] = {NT_SELECTION_STMT};
const int rule26[] = {NT_ITERATION_STMT};
const int rule27[] = {NT_RETURN_STMT};
const int rule28[] = {NT_EXPRESSION, TOKEN_SEMICOLON};
const int rule29[] = {TOKEN_SEMICOLON};
const int rule30[] = {TOKEN_IF, TOKEN_LPAREN, NT_EXPRESSION, TOKEN_RPAREN, NT_STATEMENT, NT_SELECTION_STMT_PRIME};
const int rule31[] = {TOKEN_ELSE, NT_STATEMENT};
const int rule32[] = {NT_EMPTY};
const int rule33[] = {TOKEN_WHILE, TOKEN_LPAREN, NT_EXPRESSION, TOKEN_RPAREN, NT_STATEMENT};
const int rule34[] = {TOKEN_RETURN, NT_RETURN_STMT_PRIME};
const int rule35[] = {NT_EXPRESSION, TOKEN_SEMICOLON};
const int rule36[] = {TOKEN_SEMICOLON};
const int rule37[] = {NT_VAR, NT_ASSIGN_EXPR};
const int rule38[] = {NT_SIMPLE_EXPRESSION};
const int rule39[] = {TOKEN_ID, NT_VAR_PRIME};
const int rule40[] = {TOKEN_LBRACKET, NT_EXPRESSION, TOKEN_RBRACKET};
const int rule41[] = {NT_EMPTY};
const int rule42[] = {NT_ADDITIVE_EXPRESSION, NT_SIMPLE_EXPRESSION_PRIME};
const int rule43[] = {NT_RELOP, NT_ADDITIVE_EXPRESSION};
const int rule44[] = {NT_EMPTY};
const int rule45[] = {TOKEN_LTE};
const int rule46[] = {TOKEN_LT};
const int rule47[] = {TOKEN_GT};
const int rule48[] = {TOKEN_GTE};
const int rule49[] = {TOKEN_EQ};
const int rule50[] = {TOKEN_NEQ};
const int rule51[] = {NT_TERM, NT_ADDITIVE_EXPRESSION_PRIME};
const int rule52[] = {NT_ADDOP, NT_TERM, NT_ADDITIVE_EXPRESSION_PRIME};
const int rule53[] = {NT_EMPTY};
const int rule54[] = {TOKEN_PLUS};
const int rule55[] = {TOKEN_MINUS};
const int rule56[] = {NT_FACTOR, NT_TERM_PRIME};
const int rule57[] = {NT_MULOP, NT_FACTOR, NT_TERM_PRIME};
const int rule58[] = {NT_EMPTY};
const int rule59[] = {TOKEN_MULT};
const int rule60[] = {TOKEN_DIV};
const int rule61[] = {TOKEN_LPAREN, NT_EXPRESSION, TOKEN_RPAREN};
const int rule62[] = {NT_VAR};
const int rule63[] = {NT_CALL};
const int rule64[] = {TOKEN_NUM};
const int rule65[] = {TOKEN_ID, TOKEN_LPAREN, NT_ARGS, TOKEN_RPAREN};
const int rule66[] = {NT_ARG_LIST};
const int rule67[] = {NT_EMPTY};
const int rule68[] = {NT_EXPRESSION, NT_ARG_LIST_PRIME};
const int rule69[] = {TOKEN_COMMA, NT_EXPRESSION, NT_ARG_LIST_PRIME};
const int rule70[] = {NT_EMPTY};

// Define the grammar rules array
const int *grammar_rules[] = {
    rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9, rule10,
    rule11, rule12, rule13, rule14, rule15, rule16, rule17, rule18, rule19, rule20,
    rule21, rule22, rule23, rule24, rule25, rule26, rule27, rule28, rule29, rule30,
    rule31, rule32, rule33, rule34, rule35, rule36, rule37, rule38, rule39, rule40,
    rule41, rule42, rule43, rule44, rule45, rule46, rule47, rule48, rule49, rule50,
    rule51, rule52, rule53, rule54, rule55, rule56, rule57, rule58, rule59, rule60,
    rule61, rule62, rule63, rule64, rule65, rule66, rule67, rule68, rule69, rule70
};

// Define the grammar rule sizes array
const int grammar_rule_sizes[] = {
    sizeof(rule1) / sizeof(rule1[0]),
    sizeof(rule2) / sizeof(rule2[0]),
    sizeof(rule3) / sizeof(rule3[0]),
    sizeof(rule4) / sizeof(rule4[0]),
    sizeof(rule5) / sizeof(rule5[0]),
    sizeof(rule6) / sizeof(rule6[0]),
    sizeof(rule7) / sizeof(rule7[0]),
    sizeof(rule8) / sizeof(rule8[0]),
    sizeof(rule9) / sizeof(rule9[0]),
    sizeof(rule10) / sizeof(rule10[0]),
    // sizeof(rule11) / sizeof(rule11[0]),
    // sizeof(rule12) / sizeof(rule12[0]),
    // sizeof(rule13) / sizeof(rule13[0]),
    // sizeof(rule14) / sizeof(rule14[0]),
    // sizeof(rule15) / sizeof(rule15[0]),
    // sizeof(rule16) / sizeof(rule16[0]),
    // sizeof(rule17) / sizeof(rule17[0]),
    // sizeof(rule18) / sizeof(rule18[0]),
    // sizeof(rule19) / sizeof(rule19[0]),
    // sizeof(rule20) / sizeof(rule20[0]),
    // sizeof(rule21) / sizeof(rule21[0]),
    // sizeof(rule22) / sizeof(rule22[0]),
    // sizeof(rule23) / sizeof(rule23[0]),
    // sizeof(rule24) / sizeof(rule24[0]),
    // sizeof(rule25) / sizeof(rule25[0]),
    // sizeof(rule26) / sizeof(rule26[0]),
    // sizeof(rule27) / sizeof(rule27[0]),
    // sizeof(rule28) / sizeof(rule28[0]),
    // sizeof(rule29) / sizeof(rule29[0]),
    // sizeof(rule30) / sizeof(rule30[0]),
    // sizeof(rule31) / sizeof(rule31[0]),
    // sizeof(rule32) / sizeof(rule32[0]),
    // sizeof(rule33) / sizeof(rule33[0]),
    // sizeof(rule34) / sizeof(rule34[0]),
    // sizeof(rule35) / sizeof(rule35[0]),
    // sizeof(rule36) / sizeof(rule36[0]),
    // sizeof(rule37) / sizeof(rule37[0]),
    // sizeof(rule38) / sizeof(rule38[0]),
    // sizeof(rule39) / sizeof(rule39[0]),
    // sizeof(rule40) / sizeof(rule40[0]),
    // sizeof(rule41) / sizeof(rule41[0]),
    // sizeof(rule42) / sizeof(rule42[0]),
    // sizeof(rule43) / sizeof(rule43[0]),
    // sizeof(rule44) / sizeof(rule44[0]),
    // sizeof(rule45) / sizeof(rule45[0]),
    // sizeof(rule46) / sizeof(rule46[0]),
    // sizeof(rule47) / sizeof(rule47[0]),
    // sizeof(rule48) / sizeof(rule48[0]),
    // sizeof(rule49) / sizeof(rule49[0]),
    // sizeof(rule50) / sizeof(rule50[0]),
    // sizeof(rule51) / sizeof(rule51[0]),
    // sizeof(rule52) / sizeof(rule52[0]),
    // sizeof(rule53) / sizeof(rule53[0]),
    // sizeof(rule54) / sizeof(rule54[0]),
    // sizeof(rule55) / sizeof(rule55[0]),
    // sizeof(rule56) / sizeof(rule56[0]),
    // sizeof(rule57) / sizeof(rule57[0]),
    // sizeof(rule58) / sizeof(rule58[0]),
    // sizeof(rule59) / sizeof(rule59[0]),
    // sizeof(rule60) / sizeof(rule60[0]),
    // sizeof(rule61) / sizeof(rule61[0]),
    // sizeof(rule62) / sizeof(rule62[0]),
    // sizeof(rule63) / sizeof(rule63[0]),
    // sizeof(rule64) / sizeof(rule64[0]),
    // sizeof(rule65) / sizeof(rule65[0]),
    // sizeof(rule66) / sizeof(rule66[0]),
    // sizeof(rule67) / sizeof(rule67[0]),
    // sizeof(rule68) / sizeof(rule68[0]),
    // sizeof(rule69) / sizeof(rule69[0]),
    // sizeof(rule70) / sizeof(rule70[0])
};