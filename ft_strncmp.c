/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:55:01 by cristian          #+#    #+#             */
/*   Updated: 2023/10/01 23:09:14 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && (s1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
			{
				return (str1[i] - str2[i]);
			}
			if (str1[i] < str2 [i])
			{
				return (str1[i] - str2[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *ptr1;
	char *ptr2;
	char *ptr3;
	char *ptr4;

	ptr1 = "Hola";
	ptr2 = "Hola que";
	ptr3 = "Hola";
	ptr4 = "Hola que";
	printf("%d\n",ft_strncmp(ptr1,ptr2));	
	printf("%d\n",strncmp(ptr3,ptr4));	
}
*/
