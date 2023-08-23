/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:27:48 by cristian          #+#    #+#             */
/*   Updated: 2023/08/23 01:33:46 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while((s1[i] != '\0' || s2[i] != '\0') && i < n)
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
	ft_strncmp(ptr1,ptr2,4);
	printf("%d",ft_strncmp(ptr1,ptr2,4));	
}
