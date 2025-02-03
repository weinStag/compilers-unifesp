program          → declaration_list
declaration_list → declaration declaration_list'
declaration_list' → declaration declaration_list' | ε

declaration      → var_declaration | fun_declaration
var_declaration  → type_specifier ID ; | type_specifier ID [ NUM ] ;
type_specifier   → int | void

fun_declaration  → type_specifier ID ( params ) compound_stmt
params           → param_list | void
param_list       → param param_list'
param_list'      → , param param_list' | ε
param            → type_specifier ID | type_specifier ID [ ]

compound_stmt    → { local_declarations statement_list }
local_declarations → var_declaration local_declarations'
local_declarations' → var_declaration local_declarations' | ε
statement_list   → statement statement_list'
statement_list'  → statement statement_list' | ε
statement        → expression_stmt | compound_stmt | selection_stmt | iteration_stmt | return_stmt

expression_stmt  → expression ; | ;
selection_stmt   → if ( expression ) statement selection_stmt'
selection_stmt'  → else statement | ε
iteration_stmt   → while ( expression ) statement
return_stmt      → return return_stmt'
return_stmt'     → expression ; | ;

expression       → var = expression | simple_expression
var             → ID var'
var'            → [ expression ] | ε
simple_expression → additive_expression simple_expression'
simple_expression' → relop additive_expression | ε
relop           → <= | < | > | >= | == | !=

additive_expression → term additive_expression'
additive_expression' → addop term additive_expression' | ε
addop           → + | -

term            → factor term'
term'           → mulop factor term' | ε
mulop           → * | /
factor          → ( expression ) | var | call | NUM

call            → ID ( args )
args            → arg_list | ε
arg_list        → expression arg_list'
arg_list'       → , expression arg_list' | ε
