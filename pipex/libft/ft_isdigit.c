/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:57:52 by cmanica-          #+#    #+#             */
/*   Updated: 2024/07/06 01:35:32 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit( int c)
{
	if ('0' <= c && c <= '9')
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
	int i = 0;
	while (i < 128)
	{
		printf("i es: %d\n", i);
		printf("mia %d\n", ft_isdigit(i));
		printf("tuya %d\n", isdigit(i));
		i++;
	}
}
*/
