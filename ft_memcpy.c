/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:47:24 by cristian          #+#    #+#             */
/*   Updated: 2023/09/18 02:49:49 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	i = 0;
	str = (char *)dest;
	str2 = (char *)src;
	while (i < n)
	{
		*(str++) = *(str2++);
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 10;
	char str1[23] = "hellome llamo cristian";
	char str2[6] = "hola ";
	char str3[23] = "hellome llamo cristian";
	char *string;
	char *string2;
	memcpy((void *)str1, (void *)str2, i);
	ft_memcpy((void *)str3, (void *)str2, i);
	string = (char*)str1; 
	string2 = (char*)str3;
	printf("tuya %s\n", string);
	printf("mia %s\n", string2);
}
*/
