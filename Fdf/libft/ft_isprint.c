/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:49:23 by cristian          #+#    #+#             */
/*   Updated: 2023/09/17 23:27:04 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint( int c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
	}
	else
	{
		return (0);
	}
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d\n", ft_isprint('a'));
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", isprint('a'));
	printf("%d\n", isprint('\n'));
	printf("%d\n", isprint('1'));


	int i = -200;
	while (i < 200)
	{
		printf("i es: %d\n", i);
		printf("mia %d\n", ft_isprint(i));
		printf("tuya %d\n", isprint(i));
		i++;
	}
}
*/
