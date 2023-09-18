/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:57:52 by cmanica-          #+#    #+#             */
/*   Updated: 2023/09/18 02:50:13 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit( int c)
{
	if (48 <= c && c <= 57)
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
