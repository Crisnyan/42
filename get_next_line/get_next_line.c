/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:00 by cristian          #+#    #+#             */
/*   Updated: 2024/02/09 02:19:51 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	fnl(char *buff)
{
	int	i;
	int	x;

	if (buff == 0)
		return (0);
	i = 1;
	x = (int)slen(buff);
	while (i < x + 1)
	{
		if (*buff == '\n')
			return (i);
		buff++;
		i++;
	}
	return (0);
}

void	create(char *buff, t_part **parts, char **res)
{
	int		check;

	if (*res)
		buff = *res;
	parts[NEXT] = clc(sizeof(t_part), 1);
	check = fnl(buff);
	if (check != 0 && check != BUFFER_SIZE)
		parts[NEXT]->node = ft_substr(buff, 0, check);
	else
		parts[NEXT]->node = ft_strdup(buff);
	parts[NEXT]->arrow = 0;
	if (parts[HEAD] == 0)
		parts[HEAD] = parts[NEXT];
	if (!parts[NEXT])
		return (clearall(buff, parts, res, 1));
	if (parts[PREV] && parts[NEXT])
		parts[PREV]->arrow = parts[NEXT];
	parts[PREV] = parts[NEXT];
	if (check != 0 && check != BUFFER_SIZE)
		*res = ft_substr(buff, check, BUFFER_SIZE - check);
	else
		*res = 0;
}

char	*getstr(t_part **p, char *b)
{
	t_part	*ptr;
	int		num;
	char	*str;

	ptr = p[HEAD];
	num = 0;
	while (ptr != 0) 
	{
		ptr = ptr->arrow;
		num++;
	}
	ptr = p[HEAD];
	if (fnl(p[HEAD]->node) != 0 && fnl(p[HEAD]->node) != BUFFER_SIZE)
		str = clc((num - 2) * BUFFER_SIZE + slen(p[HEAD]->node) + slen(b), 1);
	else
		str = clc((num - 1) * BUFFER_SIZE + slen(p[HEAD]->node), 1);
	if (num == 1)
		return (ft_strdup((p[HEAD]->node)));
	while (--num > -1)
	{
		str = ft_strjoin(str, ptr->node);
		ptr = ptr->arrow;
	}
	return (str);
}

void	clearall(char *buff, t_part **parts, char **res, int mode)
{
	int		check;
	t_part	*ptr;

	ptr = parts[HEAD];
	check = fnl(buff);
	if (check != BUFFER_SIZE && check != 0 && mode == 1)
		*res = ft_substr(buff, check, BUFFER_SIZE - check + 1);
	else if (fnl(*res) != 0 && mode == 1)
		*res = ft_substr(*res, check, BUFFER_SIZE - check + 1);
	else if (mode == 1)
		*res = 0;
	while (ptr != 0)
	{
		parts[HEAD] = parts[HEAD]->arrow;
		parts[HEAD] = 0;
		free(ptr->node);
		ptr = ptr->arrow;
		parts[HEAD] = ptr;
	}
	buff = 0;
	return (free(ptr), free(buff));
}

char	*get_next_line(int fd)
{
	t_part		*parts[3];
	char		*str[2];
	static char	*res = 0;

	parts[HEAD] = 0;
	parts[NEXT] = 0;
	str[S] = 0;
	str[B] = clc((BUFFER_SIZE + 1), 1);
	while (res && !str[S])
	{
		if (create(res, parts, &res), 1 && fnl(parts[PREV]->node) != 0)
		{
			str[S] = getstr(parts, res);
			return (clearall(str[B], parts, &res, 2), str[S]);
		}
	}
	while (fnl(str[B]) == 0 && read(fd, str[B], BUFFER_SIZE) > 0 && fd != -1)
		create(str[B], parts, &res);
	if (fnl(str[B]) == 0 && !res && parts[NEXT] == 0)
		return (clearall(str[B], parts, &res, 1), free(res), NULL);
	parts[PREV]->arrow = parts[NEXT];
	if (parts[NEXT] != 0)
		parts[NEXT]->arrow = 0;
	str[S] = getstr(parts, str[B]);
	return (clearall(str[B], parts, &res, 1), str[S]);
}
/*
int main(void)
{
	int	libro;
	char	*str;

	libro = open("giant_line_nl.txt", O_RDONLY);
	str = get_next_line(libro);
	while(str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(libro);
	}
}
*/
