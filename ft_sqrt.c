/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:06:09 by cristian          #+#    #+#             */
/*   Updated: 2023/08/27 03:50:44 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	sqrt;

	i = 1;
	sqrt = 0;
	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	while (i <= nb / 2)
	{
		sqrt = i * i;
		if (sqrt == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	int x;
	int y;
	int z;

	x = 25;
	y = 19;
	z = -1;

	printf("%d \n", ft_sqrt(x));
	printf("%d \n", ft_sqrt(y));
	printf("%d \n", ft_sqrt(z));


}
*/
