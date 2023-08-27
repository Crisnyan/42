/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:54:08 by cristian          #+#    #+#             */
/*   Updated: 2023/08/26 18:51:46 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
	{
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
}
/*
#include <stdio.h>

int main(void)
{
	int a;
	int b;

	a = -6;
	b = 6;
	printf("%d \n", ft_fibonacci(a));
	printf("%d \n", ft_fibonacci(b));
}
*/
