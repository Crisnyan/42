NAME = pipex
LIB = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INLCUDES = pipex.h
SRCS = pipex.c
OBJ = $(SRCS:.c=.o)

%.o: %.c $(INCLUDES) libft/libft.a
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "build complete"

$(NAME): $(OBJ) LIB Makefile
	@echo "Creating program: $@"
	cp libft/libft.a .
	$(CC) $(OBJ) $(LIB) -o $(NAME) $(CFLAGS)

LIB: 
	make -C libft

clean:
	rm -rf $(OBJ)
	make -C libft clean
	@echo "Cleaning up"

fclean: clean
	rm -rf $(NAME) libft.a
	make -C libft fclean
	@echo "Force cleaning"

re: fclean all

.PHONY: fclean all clean re
