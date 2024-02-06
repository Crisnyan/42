/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:28 by cristian          #+#    #+#             */
/*   Updated: 2024/02/03 22:16:05 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

typedef struct	partget
{
	char	*node;
	struct partget	*arrow;
}part;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*clearbuff(char *buff);
char	*getstr(part *head, char *buff);
char	*ft_strjoin(const char *s1, const char *s2);
int		findnl(char *buff);
void	*clc(size_t count, size_t size);
size_t	slen(const char *s);
part	create(char *buff, part *ptr);
#endif
