# library name
NAME = libmx.a

# directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# compiler and flags
CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic

# source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: install

install: $(NAME)

# creating the library
$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

# compiling .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

# creating the obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $@

# cleaning object files
clean:
	@rm -rf $(OBJ_DIR)

# delete library
uninstall: clean
	@rm -f $(NAME)

# rebuild library
reinstall: uninstall install
