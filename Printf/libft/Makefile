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

OBJ = $(SRC:.c=.o)

all: $(NAME) Makefile
	@echo "========= BUILD FOR $(NAME) COMPLETE ========="

$(NAME): $(OBJ)
	@echo "======= CREATING LIBRARY $(NAME): $@ ========="
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	@echo "============== COMPILING $< =================="
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "============== CLEANING UP $(NAME) ==========="
	rm -rf $(OBJ)

fclean:
	@echo "============== CLEANING UP $(NAME) ==========="
	rm -rf $(OBJ)
	@echo "============== FORCE CLEANING $(NAME) ========"
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re
