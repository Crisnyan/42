/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:18:24 by cristian          #+#    #+#             */
/*   Updated: 2024/01/24 18:03:37 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <string.h>
#include <limits.h>

static int	loop(const char *format, int size, va_list args)
{
	int		x;

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			x = casos(format, args);
			if (x == -1)
				return (-1);
			size += x - 1;
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar_fd('%', 1);
			format += 2;
		}
		else
			write(1, format++, 1);
		size++;
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, format);
	size = loop(format, size, args);
	if (size == -1)
		return (-1);
	va_end(args);
	return (size);
}

void	ft_setcolor(int expected, int ft)
{
	if (expected == ft)
		printf("\033[0;32m");
	else
		printf("\033[0;31m");
}

void	ft_resetcolor () 
{
	printf("\033[0m\n");
}

void	ft_title (char *s) 
{
	printf("\033[0;33m\n");
	printf("%s", s);
	ft_resetcolor();
}

void	ft_output(int expected, int ft, char *s)
{
	static int	count = 0;

	ft_setcolor(expected, ft);
	printf("(%d) printf:%d ft_printf:%d | %s\n", ++count, expected, ft, s);
	ft_resetcolor();
}

void	ft_print(char *s)
{
	int		expected;
	int		ft;

	expected = ft_printf(s);
	printf("|\n");
	ft = ft_printf(s);
	ft_printf("|\n");
	ft_output(expected, ft, s);
}

void	ft_prints(char *s, char *v)
{
	int	expected;
	int	ft;

	expected = printf(s, v);
	printf("|\n");
	ft = ft_printf(s, v);
	ft_printf("|\n");
	ft_output(expected, ft, s);
}

void	ft_printc(char *s, char c)
{
	int	expected;
	int	ft;

	expected = printf(s, c);
	printf("|\n");
	ft = ft_printf(s, c);
	ft_printf("|\n");
	ft_output(expected, ft, s);
}

void	ft_printi(char *s, long long n)
{
	int	expected;
	int	ft;

	expected = printf(s, n);
	printf("|\n");
	ft = ft_printf(s, n);
	ft_printf("|\n");
	ft_output(expected, ft, s);
}

void	ft_printp(char *s, void *p)
{
	int	expected;
	int	ft;

	expected = printf(s, p);
	printf("|\n");
	ft = ft_printf(s, p);
	ft_printf("|\n");
	ft_output(expected, ft, s);
}
/*
int	main(void)
{

	int	num;

	num = 42;
	ft_title("   >>>   MANDATORY   <<<\n\n");
	ft_print("Hello world!");
	ft_print("%%");
	ft_print("%%c");

	ft_printc("%c", '$');
	ft_printc("%c", 0);
	ft_printc("a%ca", 'c');

	ft_prints("%s", "Hello world");
	ft_prints("%s", "Hello\0 world");
	ft_prints("STR:%s", "hi");
	ft_prints("%s", "");
	ft_prints("%s", NULL);


	ft_printi("%i", 42);
	ft_printi("%d", -6);
	ft_printi("%d", 2147483647);
	ft_printi("%d", -2147483648);
	ft_printi("%i", 0);
	ft_printi("%u", 42);
	ft_printi("%u", -42);

	ft_printi("%x", 42);
	ft_printi("%X", -42);
	ft_printi("%x", 0);

	ft_printp("%p", &num);
	ft_printp("%p", "");
	ft_printp("%p", NULL);
	return (0);
}
*/
