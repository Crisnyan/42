/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:31:02 by cristian          #+#    #+#             */
/*   Updated: 2023/09/18 02:47:40 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < n)
	{
		*str = c;
		str++;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	char str1[500] = "";
	char str3[500] = "";
	int str2;
	char *string;
	char *string2;
	
	
	while (i < 128)
	{
		str2 = i;
		printf("i es: %d\n", i);
		memset((void *)str1, str2, i);
		ft_memset((void *)str3, str2, i);
		string = (char*)str1; 
		string2 = (char*)str3; 
		printf("tuya %s\n", string);
		printf("mia %s\n", string2);
		i++;
	}
}
*/
