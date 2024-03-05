/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:39:45 by cmanica-          #+#    #+#             */
/*   Updated: 2023/09/17 23:27:34 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha( int c)
{
	if ((c > 64 && c < 91) || (c < 123 && c > 96))
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
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('a'));
	printf("%d\n", isalpha('A'));
	printf("%d\n", isalpha('1'));
}
*/
