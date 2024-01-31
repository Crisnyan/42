/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 03:18:29 by cristian          #+#    #+#             */
/*   Updated: 2024/01/31 15:37:09 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		casos(const char *format, va_list args);
int		sizeuint(unsigned int num, int fd);
int		sizechar(char c, int fd);
int		sizeint(int num, int fd);
int		sizestr(char *str, int fd);
int		sizelilhex(unsigned int num, int fd);
int		sizebighex(unsigned int num, int fd);
int		sizeptr(void *ptr, int fd);
char	*ntos(unsigned long long num, char *base);
void	*pfalloc(size_t num, size_t size);
#endif
