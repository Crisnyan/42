/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:13:50 by cristian          #+#    #+#             */
/*   Updated: 2023/08/28 01:47:34 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = (int *)malloc(0);
		return (-1);
	}
	else
	{
//problemas con pointers (segmentation fault) SIGSEGV
		*range = (int *)malloc(sizeof(int) * (max - min));
		i = 0;
		while (i < max - min)
		{
			*range[i] = min + i;
			i++;
		}
		return (i + 1);
	}
}

#include <stdio.h>

int main(void)
{
	int w;
	int x;
	int y;
	int z;
	int **range;
	int **range2;	

	range = NULL;
	range2 = NULL;
	
	w = -10;
	x = 10;
	y = 60;
	z = 60;
	printf("%d \n", ft_ultimate_range(range, w, x));
	printf("%d \n", ft_ultimate_range(range2, y, z));
}
