/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:24:44 by cristian          #+#    #+#             */
/*   Updated: 2023/10/15 16:20:40 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s || len == 0 || start >= ft_strlen(s))
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
	while (i < len && s[i] != 0 && start < ft_strlen(s))
		str[i++] = s[j++];
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int main (void)
{
	char *s1 = "hola";
	unsigned int start = 4294967295;
	size_t len = 0;

	printf("%s", ft_substr(s1, start, len));
}
*/
