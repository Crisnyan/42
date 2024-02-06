/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:16:52 by cristian          #+#    #+#             */
/*   Updated: 2024/02/02 00:50:46 by cristian         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (slen(s)) + 1);
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * slen(s1) + slen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s1 != '\0')
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
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

void	*clc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	char	*str;

	i = 0;
	ptr = malloc(count * size);
	str = (char *)ptr;
	if (count == 0 || size == 0)
		count = 1;
	if (ptr != NULL)
	{
		while (i++ < size * count)
			*(str++) = 0;
	}
	return (ptr);
}
