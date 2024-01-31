#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
	free(str);
}

int main(void)
{
	char	*s1 = "Hola";
	char	*s2 = " que";
	char	*s3 = " tal";
	char 	*s4;
	int	i;

	i = 0;
	str = malloc(num * BUFFER_SIZE + 1)
	ptr = head;
	str = head->part.node;
	while (num > -1)
	{
		ptr = *(ptr->arrow);
		
		
		
	printf("%s", s3);
}
