/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:10:50 by cristian          #+#    #+#             */
/*   Updated: 2023/10/15 16:22:15 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	words(char const *s, char c)
{
	size_t	num_words;

	num_words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			num_words++;
		while (*s && *s != c)
			s++;
	}
	return (num_words);
}

static char	**free_array(char **array, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < pos)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	start;
	size_t	pos;
	size_t	i;

	result = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	pos = 0;
	start = 0;
	while (s[i])
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			result[pos++] = ft_substr(s, start, i - start + 1);
			if (!result[pos - 1])
				return (free_array(result, pos - 1));
		}
		i++;
	}
	result[pos] = NULL;
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
	const char *str = "H \0 H";
	char c = '\0';
	int i;

	i = 0;
	while (i < 2)
	{
		printf("%s\n", ft_split(str, c)[i]);
		i++;
	}
}
*/
