/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:28:45 by cristian          #+#    #+#             */
/*   Updated: 2023/10/01 23:13:41 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return ('\0');
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char	*s1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int	s2;
	char	*s3 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int	s4;

	int i;

	i = 0;
	while (i < 256 + 127)
	{
		s2 = i;
		s4 = i;
		printf("i es %d\n", i);
		printf("mia  %s\n",ft_strchr(s1, s2));
		printf("tuya %s\n",strchr(s3, s4));
		i++;
	}
	return(0);
}
*/
