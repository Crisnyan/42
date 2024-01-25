/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:49:08 by cristian          #+#    #+#             */
/*   Updated: 2024/01/25 18:00:31 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

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

int	sizeuint(unsigned int num, int fd)
{
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
/*
   int	main(void)
   {
   printf("\nel numero tiene %d digitos", sizeint(-0, 1));
   printf("\nel numero tiene %d digitos", sizeint(0, 1));
   }
   */
