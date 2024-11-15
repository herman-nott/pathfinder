# pathfinder name
NAME = pathfinder

# library name
LIBMX = libmx.a

# directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# compiler and flags
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
	@make -C ./libmx
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(SRC_DIR)/*.c $(SRC_DIR)/utils/*.c -L ./libmx -lmx -o $(NAME)

# cleaning object files
clean:
	@rm -rf $(OBJ_DIR)

# delete pathfinder
uninstall: clean
	@rm -rf $(LIBMX)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make uninstall -C ./libmx

# rebuild pathfinder
reinstall: uninstall install
