/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:49:08 by cristian          #+#    #+#             */
/*   Updated: 2024/01/31 17:09:19 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <errno.h>
#include <fcntl.h>

int	sizechar(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
	{
		perror("ERROR\n");
		return (-1);
	}	
	return (1);
}
int	sizestr(char *str, int fd)
{
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str != '\0')
	{
		i += sizechar(*str, fd);
		str++;
	}
	return (i);
}

char	*ntos(unsigned long long num, char *base)
{
	char				*str;
	int					nlen;
	int					blen;
	unsigned long long	num2;

	blen = (int)ft_strlen(base);
	blen = ft_strlen(base);
	nlen = 1;
	num2 = num;
	while (num2 >= (unsigned long long)blen)
	{
		num2 /= (unsigned long long)blen;
		nlen++;
	}
	str = pfalloc((nlen + 1), sizeof(char));
	if (!str)
		return (0x0);
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
		return (sizechar('0', fd));
	if (!num)
		return (-1);
	str = ntos(num, "0123456789");
	size = (int)ft_strlen(str);
	sizestr(str, fd);
	free(str);
	return (size);
}

int	sizeint(int num, int fd)
{
	char	*str;

	if (num == 0)
		return (sizechar('0', fd));
	if (!num)
		return (-1);
	if (num < 0)
	{
		sizechar('-', fd);
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
