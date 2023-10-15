/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:42:19 by cristian          #+#    #+#             */
/*   Updated: 2023/10/11 01:53:19 by cristian         ###   ########.fr       */
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

static int	inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	start(char *s1, char const *set)
{
	int	i;
	int	start;

	i = 0;
	start = -1;
	while (s1)
	{
		if (inset(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (start);
}

static int	end(char *s1, char const *set)
{
	int	end;
	int	len;

	len = ft_strlen(s1) - 1;
	end = -1;
	while (len > -1)
	{
		if (inset(s1[len], set) == 0)
			return (len);
		len--;
	}
	return (end);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		i;
	int		srt;
	int		fin;
	char	*str;

	i = 0;
	while (!s1)
		return (0);
	fin = end(s1, set) + 1;
	srt = start(s1, set);
	str = (char *)malloc(sizeof(char) * (fin - srt + 1));
	if (!str)
		return (0);
	while (srt < fin)
		str[i++] = s1[srt++];
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	char *s1 = "lorem ipsum amet";
	char *set = "te";

	printf("%s", ft_strtrim(s1, set));
}
*/
