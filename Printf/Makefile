NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ft_printf.h
MAKE = libft.a
SRCS = ft_printf.c casos.c basics.c hex.c
OBJS = $(SRCS:.c=.o)

all:$(MAKE) $(NAME) 
	@echo "Creating library $(NAME): $@"

$(NAME): MAKE $(OBJS) $(INCLUDES)  Makefile	
	
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS) 
	@echo "=========== BUILD FOR $(NAME) COMPLETE =============="

MAKE:
	@echo "================== CREANDO LIBFT ===================="
	make -C libft


%.o: %.c $(INCLUDE) 
	@echo "=================== Compiling $< ===================="
	cc -c $(CFLAGS) $< -o $@

clean:
	@echo "Cleaning up $(NAME)"
	rm -f $(OBJS)
	make -C libft clean
fclean:
	@echo "================== CLEANING UP $(NAME) =================="
	rm -f $(OBJS)
	make -C libft clean
	@echo "================== FORCE CLEANING $(NAME) ==============="
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: fclean all clean re
