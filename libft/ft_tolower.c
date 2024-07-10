/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:55:11 by cristian          #+#    #+#             */
/*   Updated: 2023/09/18 02:49:02 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower( int arg)
{
	if (arg > 64 && arg < 91)
	{
		return (arg + 32);
	}
	else
	{
		return (arg);
	}
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{

	int i = -250;
	while (i < 256)
	{
		printf("i es: %d\n", i);
		printf("mia %c\n", ft_tolower(i));
		printf("tuya %c\n", tolower(i));
		i++;
	}
}
*/
