/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:03:40 by cristian          #+#    #+#             */
/*   Updated: 2024/01/31 14:45:17 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < n)
	{
		str[i] = '\0';
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
	char *string;
	char *string2;
	char str1[27] = "abcdefghijklmnopqrstuvwxyz";
	char str2[27] = "abcdefghijklmnopqrstuvwxyz";		
	
	while (i < 30)
	{

	
		printf("i es: %d\n", i);
		bzero((void *)str1, i);
		ft_bzero((void *)str2, i);
		string = (char*)str1; 
		string2 = (char*)str2; 
		printf("tuya %s\n", string + i - 1);
		printf("mia %s\n", string2 + i - 1);
		i++;
	}
}
*/
