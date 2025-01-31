# Define directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LEXER_OBJ_DIR = $(OBJ_DIR)/lexer

# Define source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/lexer/lexer.c $(SRC_DIR)/lexer/dfa.c
OBJ_FILES = $(OBJ_DIR)/main.o $(LEXER_OBJ_DIR)/lexer.o $(LEXER_OBJ_DIR)/dfa.o

# Define compiler and flags
CC = gcc
CFLAGS = -Wall -g -I$(INCLUDE_DIR)

# Define the executable name
EXEC = lexer

# Default rule to build the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC)

# Rule for compiling .c files into .o files inside the lexer subdirectory
$(LEXER_OBJ_DIR)/%.o: $(SRC_DIR)/lexer/%.c
	@mkdir -p $(LEXER_OBJ_DIR)  # Create lexer object directory if it doesn't exist
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for compiling main.c into main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up the compiled files
clean:
	rm -f $(OBJ_DIR)/*.o $(LEXER_OBJ_DIR)/*.o $(EXEC)
