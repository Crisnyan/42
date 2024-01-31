#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "aux.c"

#define BUFFER_SIZE 5

typedef struct	partget
{
	const char	*node;
	struct partget	*arrow;
}part;

part	create(char *buff, part *ptr)
{
	part	part;

	ptr = &part;
	ptr->node = strdup(buff);
	ptr->arrow = 0;
	return (part);
}


char	*getstr(part *head)
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
	printf("%d\n", num);
	ptr = head;
	str = malloc(num * BUFFER_SIZE);
	while (--num > -1)
	{
		str = strjoin(str, ptr->node);
		ptr = ptr->arrow;
	}
	return (str);
}

int	findnl(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == ('\n' || '\0'))
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	part	*head;
	part		*prev;
	part		*next;
	static char	*buff;

	if (!buff)
		buff = malloc(BUFFER_SIZE);
	head = 0;
	while (findnl(buff) == 0)
	{
		read(fd, buff, BUFFER_SIZE);
		next = (part *)malloc(sizeof(part));
		if (head == 0)
			head = next;
		*next = create(buff, next);
		if (!next)
			break ;
		if (prev)
			prev->arrow = next;
		prev = next;
	}
	return (getstr(head));
}

int main(void)
{
	int libro;

	libro = open("bee.txt", O_RDONLY);
	printf("%s", get_next_line(libro));
}
