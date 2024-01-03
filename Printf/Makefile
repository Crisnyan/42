NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -Ilibft
INCLUDES = ft_printf.h
SRCS = ft_printf.c casos.c basics.c hex.c
OBJS = $(SRCS:.c=.o)

$(NAME):$(OBJS) Makefile
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	@echo "build for $(NAME) complete"

all:$(NAME) 
	@echo "Creating library $(NAME): $@"

%.o: %.c $(INCLUDE) 
	@echo "Compiling $<"
	cc -c $(CFLAGS) $(IFLAGS) $< -o $@

clean:
	@echo "Cleaning up $(NAME)"
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	@echo "Force cleaning $(NAME)"
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: fclean all clean re
