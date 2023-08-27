/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:13:35 by cristian          #+#    #+#             */
/*   Updated: 2023/08/27 19:14:12 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;

	if (min >= max)
	{
		dest = (int *)malloc(0);
		return (dest);
	}
	else
	{
		dest = (int *)malloc(sizeof(int) * (max - min));
		i = 0;
		while (i < max - min)
		{
			dest[i] = min + i;
			i++;
		}
		return (dest);
	}
}
/*
#include <stdio.h>

int main(void)
{
	int w;
	int x;
	int y;
	int z;
	int i;
	
	w = -10;
	x = 10;
	y = 60;
	z = 60;
	i = 0;
	while (i < x - w)
	{
		printf("%d ", ft_range(w, x)[i]);
		i++;
	}
	printf("\n");

	i = 0;
	while (i < z - y)
	{
		printf("%d ", ft_range(y, z)[i]);
		i++;
	}
}
*/
