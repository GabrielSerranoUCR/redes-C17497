# Compiler settings
CC = g++
CFLAGS = -Wall -Wextra -g
ARGS = 
# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin
LOG_DIR = logs

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/subnetting

# Main rules
all: $(EXECUTABLE)

# Link
$(EXECUTABLE): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Run the program
run: $(EXECUTABLE)
ifeq ($(strip $(ARGS)),)
	./$(EXECUTABLE)
else
	./$(EXECUTABLE) "$(ARGS)"
endif

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Delete logs
delete_logs:
	rm -f $(LOG_DIR)/*.txt

# Phony targets
.PHONY: all clean run delete_logs