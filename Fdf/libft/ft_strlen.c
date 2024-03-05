/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:52:02 by cristian          #+#    #+#             */
/*   Updated: 2024/02/29 15:47:09 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	char str[] = "12345";

	str[0] = i;	
	printf("%d\n", ft_strlen(str));
	printf("%d\n", ft_strlen("\n"));
	printf("%d\n", ft_strlen("1"));
	printf("%ld\n", strlen(str));
	printf("%ld\n", strlen("\n"));
	printf("%ld\n", strlen("1"));
	
	while (i < 128)
	{
		str[i] = i;
		printf("i es: %d\n", i);
		printf("mia %d\n", ft_strlen(str));
		printf("tuya %ld\n", strlen(str));
		i++;
	}
}
*/
