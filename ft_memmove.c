/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:54:18 by cmanica-          #+#    #+#             */
/*   Updated: 2023/09/18 18:04:31 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	i = 0;
	str = (char *)dst;
	str2 = (char *)src;
	while (i < n && src && dst)
	{
		if (!src && !dst)
			return (0);
		else
		{
			*(str++) = *(str2++);
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;

	while (i < 29)
	{
		char str1[30] = "hey hey hey aqui el rich";
		char str2[28] = "hello my friend, here we go";
		char str3[30] = "hei hei hei aqui el rich";
		char *string;
		char *string2;
		printf("i es %d\n", i);
		memmove((void *)str1, (void *)str2, i);
		ft_memmove((void *)str3, (void *)str2, i);
		string = (char*)str1; 
		string2 = (char*)str3;
		printf("tuya %s\n", string);
		printf("mia %s\n", string2);
		i++;
	}
}
*/
