#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	findnl(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*buff == '\n')
			return (i);
		buff++;
		i++;
	}
	return (-1);
}

part	create(char *buff, part *ptr)
{
	part	part;
	int	check;
	char	*str;

	ptr = &part;
	check = findnl(buff);
	if (check != -1)
		str = ft_substr(buff, 0, check);
	else
		str = ft_strdup(buff);
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
	printf("%d\n", num);
	printf("%d\n", (num - 1)* BUFFER_SIZE + findnl(buff) + 1);
	ptr = head;
	str = malloc((num - 1)* BUFFER_SIZE + findnl(buff) + 1);
	while (--num > -1)
	{
		str = ft_strjoin(str, ptr->node);
		ptr = ptr->arrow;
	}
		str = ft_strjoin(str, "\0");
	return (str);
}
		
char	*get_next_line(int fd)
{
	part		*head;
	part		*prev;
	part		*next;
	static char	*buff;
	char		*str;

	head = 0;
	prev = 0;
	if (buff)
	{
		prev = (part *)malloc(sizeof(part));
		*prev = create(buff, prev);
		head = prev;
	}
	buff = malloc(BUFFER_SIZE);
	while (findnl(buff) == -1)
	{
		read(fd, buff, BUFFER_SIZE);
		next = (part *)malloc(sizeof(part));
		printf("BUFF IN 1: %s\n", buff);
		if (head == 0)
			head = next;
		*next = create(buff, next);
		if (!next)
			break ;
		if (prev)
		{
			prev->arrow = next;
			printf("ARROW POINTING TO: %p", prev->arrow);
		}
		prev = next;
		printf("BUFF IN 1: %s\n", buff);
	}
	prev->arrow = next;
	next->arrow = 0;
	printf("ARROW POINTING TO: %p", prev->arrow);
	printf("BUFF IN 1: %s\n", buff);
	str = getstr(head, buff);
	printf("BUFF IN 2: %s\n", buff);
	buff = ft_substr(buff, findnl(buff), BUFFER_SIZE - findnl(buff));
	printf("BUFF IN 3: %s\n", buff);
	head = 0;
	return (str);
}

int main(void)
{
	int	libro;
	int	times;
	int	i;

	i = 0;
	times = 5;
	while (i < times)
	{
		libro = open("bee.txt", O_RDONLY);
		printf("%s", get_next_line(libro));
		i++;
	}
}

