/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:00 by cristian          #+#    #+#             */
/*   Updated: 2024/02/10 02:41:45 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

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

void	getstr(t_part **p, char **b)
{
	t_part	*ptr;
	int		n;

	ptr = p[HEAD];
	n = 0;
	while (ptr != 0 && n++ > -1) 
		ptr = ptr->arrow;
	ptr = p[HEAD];
	if (fnl(p[HEAD]->node) != 0 && fnl(p[HEAD]->node) != BUFFER_SIZE)
		b[S] = clc((n - 2) * BUFFER_SIZE + slen(p[HEAD]->node) + slen(b[B]), 1);
	else
		b[S] = clc((n - 1) * BUFFER_SIZE + slen(p[HEAD]->node), 1);
	if (n == 1)
		b[S] = ft_strdup(p[HEAD]->node);
	while (--n > -1)
	{
		b[S] = ft_strjoin(b[S], ptr->node);
		ptr = ptr->arrow;
	}
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
	return (free(parts[HEAD]), free(parts[PREV]), free(ptr), free(buff));
}

char	*get_next_line(int fd)
{
	t_part		*parts[3];
	char		*s[2];
	static char	*res = 0;

	parts[HEAD] = 0;
	parts[NEXT] = 0;
	s[S] = 0;
	s[B] = clc((BUFFER_SIZE + 1), 1);
	while (res && !s[S])
		if (create(res, parts, &res), 1 && fnl(parts[PREV]->node) != 0)
			return (getstr(parts, s), clearall(s[B], parts, &res, 2), s[S]);
	while (fnl(s[B]) == 0 && read(fd, s[B], BUFFER_SIZE) > 0 && fd != -1)
		create(s[B], parts, &res);
	if (fnl(s[B]) == 0 && !res && !parts[HEAD])
		return (clearall(s[B], parts, &res, 1), free(res), NULL);
	parts[PREV]->arrow = parts[NEXT];
	if (parts[NEXT] != 0)
		parts[NEXT]->arrow = 0;
	return (getstr(parts, s), clearall(s[B], parts, &res, 1), s[S]);
}

int main(void)
{
	int	libro;
	char	*s;

	libro = open("test.txt", O_RDONLY);
	s = get_next_line(libro);
	while(s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(libro);
	}
}

