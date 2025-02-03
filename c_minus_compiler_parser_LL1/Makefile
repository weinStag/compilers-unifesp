# Define directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LEXER_OBJ_DIR = $(OBJ_DIR)/lexer
PARSER_OBJ_DIR = $(OBJ_DIR)/parser

# Define source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/lexer/lexer.c $(SRC_DIR)/lexer/dfa.c $(SRC_DIR)/parser/parser.c $(SRC_DIR)/parser/parse_table.c $(SRC_DIR)/parser/grammar.c
OBJ_FILES = $(OBJ_DIR)/main.o $(LEXER_OBJ_DIR)/lexer.o $(LEXER_OBJ_DIR)/dfa.o $(PARSER_OBJ_DIR)/parser.o $(PARSER_OBJ_DIR)/parse_table.o $(PARSER_OBJ_DIR)/grammar.o

# Define compiler and flags
CC = gcc
CFLAGS = -Wall -g -I$(INCLUDE_DIR)

# Define the executable name
EXEC = c_minus_compiler

# Default rule to build the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC)

# Rule for compiling .c files into .o files inside the lexer subdirectory
$(LEXER_OBJ_DIR)/%.o: $(SRC_DIR)/lexer/%.c
	@mkdir -p $(LEXER_OBJ_DIR)  # Create lexer object directory if it doesn't exist
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for compiling .c files into .o files inside the parser subdirectory
$(PARSER_OBJ_DIR)/%.o: $(SRC_DIR)/parser/%.c
	@mkdir -p $(PARSER_OBJ_DIR)  # Create parser object directory if it doesn't exist
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for compiling main.c into main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up the compiled files
clean:
	rm -f $(OBJ_DIR)/*.o $(LEXER_OBJ_DIR)/*.o $(PARSER_OBJ_DIR)/*.o $(EXEC)