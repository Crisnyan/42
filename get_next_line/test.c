/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 23:19:44 by cristian          #+#    #+#             */
/*   Updated: 2024/01/01 17:23:54 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 25

int	get_line_size(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\n' || '\0')
			return (i);
		i++;
	} 
	return (i);
}
	
char	*get_next_line(int fd)
{
	int		done;
	int		size;
	char		*buf;
	static char	*reserva;
	char		*line;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	done = get_line_size(buf, read(fd, buf, BUFFER_SIZE));
	printf("%d", done);
	reserva = (char *)malloc(done + 1);
	size = 0;
	
	while (size < done)
	{
		reserva[size] = *(buf + size);	
		*(buf + size++) = 0;
	}
	if (reserva[size] != ('\n' || '\0'))
		get_next_line(fd);

	printf("%d", BUFFER_SIZE);
	return (line);
}
		
int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("bee.txt", O_RDONLY);
	while (i < 4)
	{
		printf("\nline %i: %s", i,  get_next_line(fd));
		i++;
	}
}
