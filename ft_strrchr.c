/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:16:06 by cristian          #+#    #+#             */
/*   Updated: 2023/10/01 23:15:48 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		k;

	str = (char *)s;
	i = 0;
	k = -1;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			k = i;
		i++;
	}
	if (k > -1)
		return (&str[k]);
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
	int	s2;
	int	s4;

	int i;

	i = 0;
	while (i < 256 + 127)
	{
		s2 = i;
		s4 = i;
		printf("i es %d\n", i);
		printf("mia  %s\n",ft_strrchr(s1, s2));
		printf("tuya %s\n",strrchr(s3, s4));
		i++;
	}
	return(0);
}
*/
