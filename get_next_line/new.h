/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:18:28 by cristian          #+#    #+#             */
/*   Updated: 2024/02/11 14:55:15 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 15
# endif

int		findnl(char *buff);
size_t	slen(const char *s);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	clearall(char *buff,char **res);
void	*clc(size_t count, size_t size);
#endif
