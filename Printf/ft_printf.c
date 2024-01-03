/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:18:24 by cristian          #+#    #+#             */
/*   Updated: 2024/01/01 18:38:38 by cristian         ###   ########.fr       */
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
int main(void)
{
	const char *str = "hola%d%% tengo anos, y tu %s tienes? Oh %c%c%c tienes %x o %X anos? tienes %p y %u a la vez? %s";
	
	printf("\n%d\n", ft_printf(str, 0xF, "cuantos", 'w', 'o', 'w', 0x7FFFFFFF, 1243249, (void *)0xFFFFFFFFFFFFFFF, 124321, "puto"));
}
