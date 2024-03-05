/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:50:04 by cristian          #+#    #+#             */
/*   Updated: 2023/10/02 00:11:40 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	size_t i = 10;
	char str1[23] = "";
	char str2[6] = "";
	char str3[23] = "";
	char *string;
	char *string2;
	g_strlcpy((char *)str1, (char *)str2, i);
	ft_strlcpy((char *)str3, (char *)str2, i);
	string = (char*)str1; 
	string2 = (char*)str3;
	printf("tuya %s\n", string);
	printf("mia %s\n", string2);
}
*/
