/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 03:18:29 by cristian          #+#    #+#             */
/*   Updated: 2024/01/01 18:24:51 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				casos(const char *format, va_list args);
int				sizeuint(unsigned int num, int fd);
int				sizechar(char c, int fd);
int				sizeint(int num, int fd);
int				sizestr(char *str, int fd);
int				sizelilhex(long int num, int fd);
int				sizebighex(long int num, int fd);
int				sizeptr(void *ptr, int fd);
long long unsigned int		e(int nb, int power);
#endif
