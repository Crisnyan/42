/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:32:06 by cristian          #+#    #+#             */
/*   Updated: 2024/01/25 17:38:51 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	puthexnbr(long long unsigned num, char *base, int fd)
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

int	sizelilhex(unsigned long long num, int fd)
{
	if (num == 0)
		return (ft_putstr_fd("0", fd), 1);
	if (!num)
		return (-1);
	return (puthexnbr(num, "0123456789abcdef", fd));
}

int	sizebighex(unsigned long long num, int fd)
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
/*
int	main(void)
{
	long int	num;

	num = 9223372036854775807LL;
	printf("\n El numero en hexadecimal ocupa :%d\n", sizelilhex(num, 1));
	printf("\n El numero en hexadecimal ocupa :%d\n", sizebighex(num, 1));
}
*/
