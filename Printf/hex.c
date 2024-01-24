/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:32:06 by cristian          #+#    #+#             */
/*   Updated: 2024/01/24 17:09:07 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	puthexnbr(long long unsigned nbr, char *base, int fd)
{
	unsigned long long	i;
	unsigned long long	x;

	i = 1;
	x = nbr;
	x = x % 16;
	ft_putchar_fd(base[x], fd);
	while (nbr > 15)
	{
		ft_putchar_fd(base[nbr % 16], fd);
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int	sizelilhex(unsigned long long num, int fd)
{
	if (!num)
		return (-1);
	return (puthexnbr(num, "0123456789abcdef", fd));
}

int	sizebighex(unsigned long long num, int fd)
{
	if (!num)
		return (-1);
	return (puthexnbr(num, "0123456789ABCDEF", fd));
}

int	puthexptr(unsigned long long nbr, char *base, int fd)
{
	int	i;

	if (!nbr)
		return (-1);
	i = 0;
	while (nbr / e(16, i))
		i++;
	if (nbr >= 16)
	{
		puthexptr(nbr / 16, base, fd);
		nbr = nbr % 16;
	}
	if (nbr < 16)
		ft_putchar_fd(base[nbr], fd);
	return (i);
}

int	sizeptr(void *ptr, int fd)
{
	unsigned long long int	num;	

	if (!ptr)
		return (-1);
	num = (unsigned long long)ptr;
	ft_putstr_fd("0x", fd);
	return (puthexptr(num, "0123456789abcdef", fd) + 2);
}
/*
int	main(void)
{
	long int	num;

	num = 161;
	printf("\n El numero en hexadecimal ocupa :%d\n", sizelilhex(num, 1));
	printf("\n El numero en hexadecimal ocupa :%d\n", sizebighex(num, 1));
}
*/
