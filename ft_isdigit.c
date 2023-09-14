/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:57:52 by cmanica-          #+#    #+#             */
/*   Updated: 2023/09/14 16:17:45 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit( int arg)
{
	if (48 <= arg && arg <= 57)
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
