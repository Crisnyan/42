/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:33:25 by cristian          #+#    #+#             */
/*   Updated: 2023/08/27 03:51:15 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int main(void)
{
	int x;
	int y;
	int z;

	x = -42;
	y = 42;
	z = 19;
	printf("%d \n", ft_is_prime(x));
	printf("%d \n", ft_is_prime(y));
	printf("%d \n", ft_is_prime(z));
}
*/
