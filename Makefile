NAME = pathfinder

LIBMX = libmx.a

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
	@make -C ./libmx
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(SRC_DIR)/*.c -L ./libmx -lmx -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

uninstall: clean
	@rm -rf $(LIBMX)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make uninstall -C ./libmx

reinstall: uninstall install
