/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:32:06 by cristian          #+#    #+#             */
/*   Updated: 2023/12/31 17:57:32 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	puthexnbr(long int nbr, char *base, int fd)
{
	int	i;

	i = 0;
	while (nbr / e(16, i))
		i++;
	if (nbr == -2147483648)
	{
		nbr = -nbr;
		puthexnbr((nbr / 16), base, fd);
		nbr = nbr % 16;
	}
	if (nbr < 0) 
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 16)
	{
		puthexnbr(nbr / 16, base, fd);
		nbr = nbr % 16;
	}
	if (nbr < 16)
		ft_putchar_fd(base[nbr], fd);
	return (i);
}

int	sizelilhex(long int num, int fd)
{
	if (!num)
		return (-1);
	ft_putstr_fd("0x", fd);
	return (puthexnbr(num, "0123456789abcdef", fd) + 2);
}

int	sizebighex(long int num, int fd)
{
	if (!num)
		return (-1);
	ft_putstr_fd("0x", fd);
	return (puthexnbr(num, "0123456789ABCDEF", fd) + 2); 
}

int	puthexptr(unsigned long long int nbr, char *base, int fd)
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
	num = (unsigned long long int)ptr;
	ft_putstr_fd("0x", fd);
	return (puthexptr(num, "0123456789abcdef", fd) + 2); 
}
/*
int	main(void)
{
	long int	num;

	num = 1542424924234;
	printf("\n El numero en hexadecimal ocupa :%d\n", sizelilhex(num, 1));
	printf("\n El numero en hexadecimal ocupa :%d\n", sizebighex(num, 1));
}
*/
