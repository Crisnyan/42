/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:28 by cristian          #+#    #+#             */
/*   Updated: 2024/02/08 22:38:02 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

# ifndef HEAD 
#  define HEAD 0
# endif

# ifndef NEXT 
#  define NEXT 1
# endif

# ifndef PREV 
#  define PREV 2
# endif

# ifndef B 
#  define B 0
# endif

# ifndef S 
#  define S 1
# endif

typedef struct partget
{
	char			*node;
	struct partget	*arrow;
}t_part;

int		findnl(char *buff);
size_t	slen(const char *s);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*getstr(t_part **parts, char *buff);
char	*ft_strjoin(char *s1, char *s2);
void	create(char *buff, t_part **parts, char **res);
void	clearall(char *buff, t_part **parts, char **res, int mode);
void	*clc(size_t count, size_t size);
#endif
