/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:22:28 by cristian          #+#    #+#             */
/*   Updated: 2023/10/01 23:12:57 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
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
	size_t	n;

	ptr1 = "Hola";
	ptr2 = "Hola que";
	ptr3 = "Hola";
	ptr4 = "Hola que";
	n = 10;
	printf("%d\n",ft_memcmp(ptr1,ptr2, n));
	printf("%d\n",memcmp(ptr3,ptr4, n));
}
*/
