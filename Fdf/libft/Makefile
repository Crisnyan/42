NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra 

INCLUDES = libft.h

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c \
		ft_strrchr.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  ft_putnbr_fd.c \
		get_next_line_utils_bonus.c get_next_line_bonus.c

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
