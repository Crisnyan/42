/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:14:37 by cmanica-          #+#    #+#             */
/*   Updated: 2023/08/24 16:39:25 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	neg;
	char	result;

	neg = '-';
	if (nb < 0) 
	{
		write(1, &neg, 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		result = nb + 48;
		write(1, &result, 1);
	}
}
/*
int	main(void)
{
	int	num;
	num = 42789423;

	ft_putnbr(num);
}
*/
