/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:53:45 by cmanica-          #+#    #+#             */
/*   Updated: 2023/09/17 23:27:58 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii( int c)
{
	if (c <= 127 && c >= 0)
	{
		return (1);
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
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('\n'));
	printf("%d\n", ft_isascii('1'));
	printf("%d\n", isascii('a'));
	printf("%d\n", isascii('\n'));
	printf("%d\n", isascii('1'));


	int i = -200;
	while (i < 200)
	{
		printf("i es: %d\n", i);
		printf("mia %d\n", ft_isascii(i));
		printf("tuya %d\n", isascii(i));
		i++;
	}
}
*/
