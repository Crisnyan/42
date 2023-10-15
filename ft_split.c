/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:10:50 by cristian          #+#    #+#             */
/*   Updated: 2023/10/15 05:08:05 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	wnum(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if (s[i++] == c)
		{
			while (s[i] == c)
			{
				if (s[i + 1] == 0)
					break ;
				i++;
			}
			count++;
		}
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	spos(const char *s, char c, int num)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			k++;
			if (k - 1 == num)
				return (i);
			while (s[i] != c && s[i] != 0)
				i++;
		}
		i++;
		if (s[i - 1] == 0)
			return (i - 1);
	}
	return (i);
}

static char	*row(const char *s, char c, int start)
{
	int		end;
	int		i;
	char	*str;

	end = start;
	if (s[end] == 0)
		return (0);
	i = 0;
	while (s[end] != c && s[end] != 0)
		end++;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		i;
	int		num;

	num = wnum(s, c);
	i = 0;
	if (!s)
		return (0);
	mat = (char **)malloc(sizeof(char *) * (num + 1));
	while (i < num)
	{
		mat[i] = (row(s, c, spos(s, c, i)));
		i++;
	}
	mat[i] = 0;
	return (mat);
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
