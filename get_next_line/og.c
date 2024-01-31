/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 22:09:53 by cristian          #+#    #+#             */
/*   Updated: 2024/01/29 21:22:33 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 5

typedef struct	line
{
	char		*node;
	part		*arrow;
}part;

void	getinres(int fd, char *res)
{
	char	*buf;
	int	i;
	
	buf = malloc(BUFFER_SIZE + 1);
	buf[BUFFER_SIZE] = '\0';
	if (buf == 0)
		return ;
	i = 0;
	read(fd, buf, BUFFER_SIZE);
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\0')
		{	
			res[i] = '\0';
			return ;
		}
		res[i] = buf[i];
		i++;
	}
	res[i] = '\0';
}

char	*get_next_line(int fd)
{
	int		leido;
	int		i;
	static char	*res;
	char		*line;

	if (fd < 0 || read(fd, &line, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	res = malloc(20000);
	leido = 0;
	i = 0;
	line = 0;
	getinres(fd, res);
	while (res[i++] != '\0' || '\n')
		leido++;
	while (i < leido + 1)
	{
		line[i++] = *res;
		*res = 0;
		res++;
	}
	if (*res != '\0' || '\n')
		get_next_line(fd);
	else if (*res == '\n')
		line[i] = '\n';
	else if (*res == '\0')
		line[i] = '\0';
	return(line);
		
		
		
}
		
int	main(void)
{
	int fd;

	fd = open("bee.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
