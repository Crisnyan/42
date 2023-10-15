/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:57:49 by cristian          #+#    #+#             */
/*   Updated: 2023/10/05 23:32:43 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14)) 
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}
/*
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str;

	str = "   -+1234ab5678";
	printf("%d \n", ft_atoi(str));
// por algun motivo la funcion atoi original no parece funcionar con " " o "+"
	printf("%d\n", atoi(str));
}
*/
