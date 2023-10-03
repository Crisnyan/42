/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:57:49 by cristian          #+#    #+#             */
/*   Updated: 2023/10/02 01:18:27 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c > 8 && c < 14))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	nbr;

	i = 0;
	signal = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			signal = -1;
		}
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * signal);
}
/*
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
*/
