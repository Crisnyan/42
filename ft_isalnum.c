/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:35:44 by cmanica-          #+#    #+#             */
/*   Updated: 2023/09/17 23:27:18 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum( int c)
{
	if (((c > 64 && c < 91) || (c < 123 && c > 96))
		|| (48 <= c && c <= 57))
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
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", isalnum('a'));
	printf("%d\n", isalnum('A'));
	printf("%d\n", isalnum('1'));


	int i = 0;
	while (i < 128)
	{
		printf("i es: %d\n", i);
		printf("mia %d\n", ft_isalnum(i));
		printf("tuya %d\n", isalnum(i));
		i++;
	}
}
*/
