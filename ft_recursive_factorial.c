/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:08:02 by cristian          #+#    #+#             */
/*   Updated: 2023/08/26 01:15:45 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	num;

	if (nb < 0)
	{
		return (0);
	}
	num = 1;
	if (nb > 0)
	{
		num *= nb;
		nb--;
		ft_recursive_factorial(nb);
	}
	return (num);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%d \n", ft_recursive_factorial(7));
	printf("%d \n", ft_recursive_factorial(0));
	printf("%d \n", ft_recursive_factorial(-1));
}
*/
