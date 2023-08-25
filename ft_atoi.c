/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:57:49 by cristian          #+#    #+#             */
/*   Updated: 2023/08/25 00:34:06 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	num;

	neg = 0;
	num = 0;
	while (!(str[i] >= 48  && str[i] <= 57))
	{
		if (str[i] == '-')
		{
			neg++;
		}
		i++;
	}
	while (str[i] >= 48  && str[i] <= 57)
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	neg = neg % 2;
	if (neg == 1)
	{
		num = -num;
	}
	return (num);
}

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str;

	str = "   -+---+-1234ab5678";
	printf("%d \n", ft_atoi(str));
// por algun motivo la funcion atoi original no parece funcionar con " " o "+"
	printf("%d", atoi(str));
}
