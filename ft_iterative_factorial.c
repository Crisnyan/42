/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:47:30 by cristian          #+#    #+#             */
/*   Updated: 2023/08/25 23:11:46 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;

	if (nb < 0)
	{
		return (0);
	}
	num = 1;
	while (nb > 0)
	{
		num *= nb;
		nb--;
	}
	return (num);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%d \n", ft_iterative_factorial(7));
	printf("%d \n", ft_iterative_factorial(0));
	printf("%d \n", ft_iterative_factorial(-1));
}
*/
