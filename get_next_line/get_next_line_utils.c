/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:52 by cristian          #+#    #+#             */
/*   Updated: 2024/02/09 12:56:25 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	slen(const char *s)
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

void	*clc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	char	*str;

	i = 0;
	ptr = malloc(count * size);
	str = (char *)ptr;
	if (ptr != NULL && size > 0 && count > 0)
	{
		while (i++ < size * count)
			*(str++) = 0;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = clc(slen(s) + 1, 1);
	if (!dst)
		return (NULL);
	while (i < slen(s))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	str = clc(slen(s1) + slen(s2) + 1, 1);
	if (!str)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
		return (NULL);
	}
	i = 0;
	while (*s1 != '\0')
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s || len == 0 || start >= slen(s))
		return (ft_strdup(""));
	i = (size_t)start;
	while (s[i] != 0)
		i++;
	i = i - start;
	if (i < len)
		len = i;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	j = (size_t)start;
	while (i < len && s[i] != 0 && start < slen(s))
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}
