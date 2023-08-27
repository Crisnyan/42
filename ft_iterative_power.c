/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:17:26 by cristian          #+#    #+#             */
/*   Updated: 2023/08/26 01:26:33 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

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
/*
#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int c;
	int d;

	a = 7;
	b = 2;
	c = 0;
	d = 0;
	printf("%d \n", ft_iterative_power(a,b));
	printf("%d \n", ft_iterative_power(c,d));
}
*/
