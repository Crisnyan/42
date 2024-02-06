/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:00 by cristian          #+#    #+#             */
/*   Updated: 2024/02/03 22:20:43 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	findnl(char *buff)
{
	int	i;
	int	x;

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

part	create(char *buff, part *ptr)
{
	part	part;
	int	check;
	char	*str;

	ptr = &part;
	check = findnl(buff);
	if (check != 0 && check != BUFFER_SIZE)
		str = ft_substr(buff, 0, check);
	else
		str = ft_strdup(buff);
	str[slen(str)] = 0;
	ptr->node = str;
	ptr->arrow = 0;
	return (part);
}

char	*getstr(part *head, char *buff)
{
	part	*ptr;
	int	num;
	char	*str;

	ptr = head;
	num = 0;
	while (ptr != 0) 
	{
		ptr = ptr->arrow;
		num++;
	}
	ptr = head;
	if (findnl(head->node) != 0 && findnl(head->node) != BUFFER_SIZE)
		str = clc((num - 2) * BUFFER_SIZE + slen(head->node) + slen(buff), 1);
	else
		str = clc((num - 1) * BUFFER_SIZE + slen(head->node), 1);
	if (num == 1)
		return(str = ft_strjoin(head->node, "\0"));
	while (--num > -1)
	{
		str = ft_strjoin(str, ptr->node);
		ptr = ptr->arrow;
	}
	str = ft_strjoin(str, "\0");
	return (str);
}

char	*clearall(char *buff, part *head)
{
	int	check;
	part	*ptr;

	ptr = head;
	check = findnl(buff);
	if (check != BUFFER_SIZE)
		buff = ft_substr(buff, check, BUFFER_SIZE - check + 1);
	else
		buff[0] = 0;
	while (ptr != 0)
	{
		head = head->arrow;
		head = 0;
		free(ptr->node);
		ptr = ptr->arrow;
		head = ptr;
	}
	return (free(ptr), buff);
}

char	*get_next_line(int fd)
{
	part		*head;
	part		*prev;
	part		*next;
	char		*buff;
	static char	*res;
	char		*str;

	head = 0;
	prev = 0;
	next = 0;
	buff = clc((BUFFER_SIZE + 1), 1);
	if (res)
	{
		prev = (part *)malloc(sizeof(part));
		*prev = create(res, prev);
		head = prev;
		if (findnl(res) != 0)
			buff = res;
	}
	while (findnl(buff) == 0 && read(fd, buff, BUFFER_SIZE) > 0)
	{
		next = (part *)malloc(sizeof(part));
		*next = create(buff, next);
		if (head == 0)
			head = next;
		if (!next)
			return (0);
		if (prev)
			prev->arrow = next;
		prev = next;
	}
	if (findnl(buff) == 0)
		return (0);
	prev->arrow = next;
	if (next != 0)
		next->arrow = 0;
	str = getstr(head, buff);
	res = clearall(buff, head);
	if (*res == 0)
		res = 0;
	return (free(buff), str);
}
/*
int main(void)
{
	int	libro;
	int	i;
	int	lines;

	i = 0;
	lines = 4070;
	libro = open("bee.txt", O_RDONLY);
	while(i++ < lines) 
		printf("%s", get_next_line(libro));
		
}
*/
