/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:57:22 by cristian          #+#    #+#             */
/*   Updated: 2023/10/01 23:10:14 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *s1;
	int s2;
	char *s3;
	int s4;

	int i;

	s1 = (char *)malloc(128*sizeof(char));
	s3 = (char *)malloc(128*sizeof(char));
	i = 32;
	while (i < 128)
	{
		s1[i] = i;
		s3[i] = i;
		i++;
	}
	i = 32;
	while (i < 128)
	{
		s2 = i;
		s4 = i;
		printf("i es %d\n", i);
		printf("mia %s\n",ft_memchr(s1, s2));
		printf("tuya %s\n",memchr(s3, s4));
		i++;
	}
	return (0);
}
*/
