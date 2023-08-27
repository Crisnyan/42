/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:52:07 by cristian          #+#    #+#             */
/*   Updated: 2023/08/27 04:04:25 by cristian         ###   ########.fr       */
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
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 0)
		return (0);
	if (ft_is_prime(nb) == 0)
		return (ft_is_prime(nb + 1));
	return (nb);
}
/*
#include <stdio.h>

int main(void)
{
	int x;
	int y;
	int z;

	x = -1;
	y = 42;
	z = 53;
	printf("%d \n", ft_find_next_prime(x));
	printf("%d \n", ft_find_next_prime(y));
	printf("%d \n", ft_find_next_prime(z));
}
*/
