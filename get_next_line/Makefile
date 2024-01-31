NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Werror -Wextra 

INCLUDES = get_next_line.h

SRC = get_next_line_utils.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "build complete"

$(NAME): $(OBJ)
	@echo "Creating library: $@"
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	@echo "Cleaning up"

fclean: clean
	rm -rf $(NAME)
	@echo "Force cleaning"

re: fclean all

.PHONY: fclean all clean re
