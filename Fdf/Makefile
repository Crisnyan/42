SRCS		=	utils.c fdf.c
HEADERS		= 	fdf.h 
NAME		=	fdf
CC			=	clang -Wall -Wextra -Werror -g
FLAGS		=	-lm -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit

%.o: %.c $(HEADERS) libft/libft.a libmlx.dylib
			$(CC) $< -c -o $@

all:		libft mlx $(NAME)

$(NAME):	$(SRCS:.c=.o) $(HEADERS)
			$(CC) $(SRCS:.c=.o) -o $(NAME) $(FLAGS)

clean:
			rm -rf $(SRCS:.c=.o)
			make clean -C libft
			make clean -C mlx

fclean:		clean
			make fclean -C libft
			rm -rf libmlx.dylib
			rm -rf $(NAME)

re:			fclean all

libft:
			@make -C libft

mlx:
			@make -C mlx

.PHONY:		all clean fclean re libft mlx linux

