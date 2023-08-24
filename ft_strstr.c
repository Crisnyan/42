/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:13:53 by cristian          #+#    #+#             */
/*   Updated: 2023/08/24 01:14:21 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		k = i;
		while (str[k] != '\0')
		{
			if (str[k] != to_find[j])
			{
				break ;
			}
			k++;
			j++;
			if (to_find[j] == '\0')
			{
				return (str + i);
			}
		}
		i++;
	}
	return ('\0');
}
/*
#include <stdio.h>

int main(void)
{
	char *s1;
	char *s2;

	s1 = "cafe";
	s2 = "odio el cafe";
	ft_strstr(s2,s1);
	printf("%s",ft_strstr(s2, s1));
	return(0);
}
*/	
