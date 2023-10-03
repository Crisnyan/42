/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:05:26 by cristian          #+#    #+#             */
/*   Updated: 2023/10/03 01:52:25 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0) 
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
/*
int	main(void)
{
	int	num;
	num = 42789423;

	ft_putnbr_fd(num);
}
*/
