/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:18:24 by cristian          #+#    #+#             */
/*   Updated: 2024/01/28 17:57:34 by cmanica-         ###   ########.fr       */
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
#include <errno.h>

int	sizechar(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	sizestr(char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return ((int)ft_strlen(str));
}

char	*ntos(unsigned long long num, char *base)
{
	char				*str;
	int					nlen;
	int					blen;
	unsigned long long	num2;

	blen = (int)ft_strlen(base);
	nlen = 1;
	num2 = num;
	while (num2 >= (unsigned long long)blen)
	{
		num2 /= (unsigned long long)blen;
		nlen++;
	}
	str = ft_calloc((nlen + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (nlen)
	{
		nlen--;
		str[nlen] = base[num % blen];
		num /= blen;
	}
	return (str);
}

int	sizeuint(unsigned int num, int fd) {
	char	*str;
	int		size;

	if (num == 0)
		return (ft_putstr_fd("0", fd), 1);
	if (!num)
		return (-1);
	str = ntos(num, "0123456789");
	size = (int)ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (size);
}

int	sizeint(int num, int fd)
{
	char	*str;

	if (num == 0)
		return (ft_putstr_fd("0", fd), 1);
	if (!num)
		return (-1);
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
		str = ntos(num, "0123456789");
		free(str);
		return (sizeuint(num, fd) + 1);
	}
	else
	{
		str = ntos(num, "0123456789");
		free(str);
		return (sizeuint(num, fd));
	}
}

int	puthexnbr(unsigned int num, char *base, int fd)
{
	char	*str;
	int		size;

	if (!num)
		return (-1);
	str = ntos(num, base);
	size = (int)ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (size);
}

int	sizelilhex(unsigned int num, int fd)
{
	if (num == 0)
		return (ft_putstr_fd("0", fd), 1);
	if (!num)
		return (-1);
	return (puthexnbr(num, "0123456789abcdef", fd));
}

int	sizebighex(unsigned int num, int fd)
{
	if (num == 0)
		return (ft_putstr_fd("0", fd), 1);
	if (!num)
		return (-1);
	return (puthexnbr(num, "0123456789ABCDEF", fd));
}

int	puthexptr(unsigned long long num, char *base, int fd)
{
	char	*str;
	int		size;

	if (!num)
		return (-1);
	str = ntos(num, base);
	size = (int)ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (size);
}

int	sizeptr(void *ptr, int fd)
{
	unsigned long long int	num;	

	if (!ptr)
	{
		ft_putstr_fd("0x0", fd);
		return (3);
	}
	num = (unsigned long long)ptr;
	ft_putstr_fd("0x", fd);
	return (puthexptr(num, "0123456789abcdef", fd) + 2);
}

int	casos(const char *format, va_list args)
{
	format++;
	if (*format == 'c')
		return (sizechar(va_arg(args, int), 1));
	if (*format == 's')
		return (sizestr(va_arg(args, char *), 1));
	if (*format == 'd')
		return (sizeint(va_arg(args, int), 1));
	if (*format == 'i')
		return (sizeint(va_arg(args, int), 1));
	if (*format == 'x')
		return (sizelilhex(va_arg(args, unsigned long long int), 1));
	if (*format == 'X')
		return (sizebighex(va_arg(args, unsigned long long int), 1));
	if (*format == 'u')
		return (sizeuint(va_arg(args, unsigned int), 1));
	if (*format == 'p')
		return (sizeptr(va_arg(args, void *), 1));
	return (-1);
}
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
int	main(void)
{
	printf("%d", printf("%s", "some string with %s hehe\n"));
	printf("\n");
	printf("%d", ft_printf("%s", "some string with %s hehe\n"));
	printf("\n");
	printf("%d", errno);
	return (0);
}
