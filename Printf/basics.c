/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:49:08 by cristian          #+#    #+#             */
/*   Updated: 2024/01/24 18:06:16 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	sizechar(char c, int fd)
{
	if (!c)
		return (-1);
	ft_putchar_fd(c, fd);
	return (1);
}

int	sizestr(char *str, int fd)
{
	if (!str)
		return (-1);
	ft_putstr_fd(str, fd);
	return ((int)ft_strlen(str));
}

long long unsigned int e(int nb, int power)
{
	long long unsigned int	num;

	num = 1;
	if (power > 0)
	{
		while (power > 0)
		{
			num *= nb;
			power--;
		}
	}
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	return (num);
}

int	sizeint(int num, int fd)
{
	int	i;

	if (!num)
		return (-1);
	if (num == 2147483647)
		return (ft_putstr_fd("2147483647", fd), 10);
	if (num == -2147483648)
		return (ft_putstr_fd("-2147483648", fd), 11);
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
		i = 1;
	}
	i = 0;
	while (num / e(10, i))
		i++;
	ft_putnbr_fd(num, fd);
	return (i);
}

int	sizeuint(unsigned int num, int fd)
{
	int	i;
	int	x;

	if (!num)
		return (-1);
	i = 0;
	while (num / e(10, i))
		i++;
	x = 1;
	while (x <= i)
	{
		ft_putchar_fd((num / e(10, i - x) % 10) + '0', fd);
		x++;
	}
	return (i);
}
/*
int	main(void)
{
	printf("\nel numero tiene %d digitos", sizeint(-6, 1));
}
*/
