/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:18:24 by cristian          #+#    #+#             */
/*   Updated: 2024/01/31 14:01:17 by cmanica-         ###   ########.fr       */
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
				return (size);
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
	va_end(args);
	return (size);
}
/*
int	main(void)
{
	printf("%d", printf("%s", "some string with %s hehe\n"));
	printf("\n");
	printf("%d", ft_printf("%s", "some string with %s hehe\n"));
	printf("\n");
	return (0);
}
*/
