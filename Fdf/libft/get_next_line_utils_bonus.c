/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:43:28 by laufarin          #+#    #+#             */
/*   Updated: 2024/02/29 16:08:36 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnl_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

void	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	ptr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (ptr == NULL)
		return (ft_free(s1));
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char) c;
	if (c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
