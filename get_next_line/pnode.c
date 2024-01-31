#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "aux.c"

#define BUFFER_SIZE 4

typedef struct	partget
{
	const char	*node;
	struct partget	*arrow;
}part;

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
		while (check++ < BUFFER_SIZE)
			 *buff = 0;
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

char	*clearbuff(char *buff)
{
	int	i;

	i = 0;
	while (i < findnl(buff))
	{
		*buff = 0;
		buff++;
		i++;
	}
	return (buff);
}
		
		
char	*get_next_line(int fd)
{
	part		*head;
	part		*prev;
	part		*next;
	static char	*buff;
	char		*str;
	int			i;

	head = 0;
	buff = malloc(BUFFER_SIZE);
	i = 0;
	prev = 0;
	while (i < 5)
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
		i++;
		printf("BUFF IN: %s\n", buff);
	}
	str = getstr(head, buff);
	return (str);
}

int main(void)
{
	int	libro;

		libro = open("bee.txt", O_RDONLY);
		printf("%s", get_next_line(libro));
}
