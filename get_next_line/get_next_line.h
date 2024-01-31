#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
# endif

typedef struct	partget
{
	const char	*node;
	struct partget	*arrow;
}part;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*clearbuff(char *buff);
char	*getstr(part *head, char *buff);
char	*ft_strjoin(const char *s1, const char *s2);
int		findnl(char *buff);
size_t	ft_strlen(const char *s);
part	create(char *buff, part *ptr);
#endif
