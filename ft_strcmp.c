/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:45:13 by cristian          #+#    #+#             */
/*   Updated: 2023/08/23 00:24:59 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
			{	
				return (s1[i] - s2[i]);
			}
			if (s1[i] < s2 [i])
			{
				return (s2[i] - s1[i]);
			}
		}
		i++;
	}
	return(0);
}

#include <stdio.h>

int	main(void)
{
	char *ptr1;
	char *ptr2;

	ptr1 = "Hola";
	ptr2 = "Hola que";
	ft_strcmp(ptr1,ptr2);
	printf("%d",ft_strcmp(ptr1,ptr2));	
}
