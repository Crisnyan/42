/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:00 by cristian          #+#    #+#             */
/*   Updated: 2024/02/11 14:57:57 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "new.h"

int	fnl(char *buff)
{
	int		i;
	int		x;

	if (buff == 0)
		return (0);
	i = 1;
	x = (int)slen(buff) + 1;
	while (i++ < x + 1)
	{
		if (*buff == '\n')
			return (i);
		buff++;
	}
	return (0);
}

void	clearall(char *buff, char **res)
{
	int		check;

	check = fnl(buff);
	if (check != BUFFER_SIZE && check != 0)
		*res = ft_substr(buff, check, BUFFER_SIZE - check + 1);
	else if (fnl(*res) != 0)
		*res = ft_substr(*res, check, BUFFER_SIZE - check + 1);
	else
		*res = 0;
	buff = 0;
	return (free(buff));
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*buff;
	static char	*res = 0;

	str = 0;
	buff = clc((BUFFER_SIZE + 1), 1);
	while (res && !str)
	{
			if (fnl(res) != 0)
			{
				res = ft_substr(res, 0, fnl(res));
				return (clearall(buff, &res), ft_strjoin(str, res));
			}
		str = ft_strjoin(str, res);
		clearall(buff, &res);
	}
	while (fnl(buff) == 0 && read(fd, buff,  BUFFER_SIZE) > -1 && fd != -1)
		str = ft_strjoin(str, buff);
	str = ft_strjoin(str, ft_substr(buff, 0, fnl(buff)));
	if (fnl(buff) == 0 && !res && !buff)
		return (clearall(buff, &res), free(res), str);
	return (clearall(buff, &res), str);
}

int main(void)
{
	int	libro;
	char	*s;

	libro = open("bee.txt", O_RDONLY);
	s = get_next_line(libro);
	while(s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(libro);
	}
	close(libro);
	return (0);
}

