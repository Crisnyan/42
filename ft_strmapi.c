/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:54:51 by cristian          #+#    #+#             */
/*   Updated: 2023/10/11 01:53:36 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
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

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (0);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

char f1(unsigned int pos, char c)
{
	c = pos + 48;
	return (c);
}

int main(void)
{
	printf("%s", ft_strmapi("1234567890", f1));
}
*/
