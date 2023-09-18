/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:37:21 by cristian          #+#    #+#             */
/*   Updated: 2023/09/18 02:48:18 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper( int arg)
{
	if (arg > 96 && arg < 123)
	{
		return (arg - 32);
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

	int i = -300;
	while (i < 0)
	{
		printf("i es: %d\n", i);
		printf("mia %c\n", ft_toupper(i));
		printf("tuya %c\n", toupper(i));
		i++;
	}
}
*/
