/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:53:45 by cmanica-          #+#    #+#             */
/*   Updated: 2023/09/14 17:59:21 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii( int arg)
{
	if (((arg > 64 && arg < 91) || (arg < 123 && arg > 96)) ||
		(48 <= arg && arg <= 57))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", ft_isascii('1'));
	printf("%d\n", isascii('a'));
	printf("%d\n", isascii('A'));
	printf("%d\n", isascii('1'));


	int i = 0;
	while (i < 128)
	{
		printf("i es: %d\n", i);
		printf("mia %d\n", ft_isascii(i));
		printf("tuya %d\n", isascii(i));
		i++;
	}
}
