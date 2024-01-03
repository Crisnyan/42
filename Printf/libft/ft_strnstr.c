/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:55:18 by cristian          #+#    #+#             */
/*   Updated: 2023/10/15 14:59:39 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*b;
	char	*l;

	i = 0;
	b = (char *)big;
	l = (char *)little;
	if (l[i] == 0)
		return (b);
	while (b[i] && i < len)
	{
		j = 0;
		k = i;
		while (b[k] != '\0' && k < len)
		{
			if (b[k++] != l[j++])
				break ;
			if (l[j] == '\0')
				return (b + i);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	char *s1;
	char *s2;

	s1 = "cafe";
	s2 = "odio el cafe";
	ft_strnstr(s2,s1);
	printf("%s",ft_strnstr(s2, s1));
	return(0);
}
*/	
