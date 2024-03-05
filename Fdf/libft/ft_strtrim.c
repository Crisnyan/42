/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:42:19 by cristian          #+#    #+#             */
/*   Updated: 2023/10/15 16:12:20 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (0);
	j = 0;
	i = 0;
	k = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (k > i && ft_strchr(set, s1[k - 1]))
		k--;
	str = malloc(sizeof(char) * (k - i + 1));
	if (str == 0)
		return (0);
	while (i < k)
		str[j++] = s1[i++];
	str[j] = '\0';
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
