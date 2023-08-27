/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:27:06 by cristian          #+#    #+#             */
/*   Updated: 2023/08/26 17:48:16 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int c;
	int d;

	a = 3;
	b = 3;
	c = 0;
	d = 0;
	printf("%d \n", ft_recursive_power(a,b));
	printf("%d \n", ft_recursive_power(c,d));
}
*/
