/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:30:19 by cristian          #+#    #+#             */
/*   Updated: 2024/01/25 14:09:36 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	casos(const char *format, va_list args)
{
	format++;
	if (*format == 'c')
		return (sizechar(va_arg(args, int), 1));
	if (*format == 's')
		return (sizestr(va_arg(args, char *), 1));
	if (*format == 'd')
		return (sizeint(va_arg(args, int), 1));
	if (*format == 'i')
		return (sizeint(va_arg(args, int), 1));
	if (*format == 'x')
		return (sizelilhex(va_arg(args, unsigned long long int), 1));
	if (*format == 'X')
		return (sizebighex(va_arg(args, unsigned long long int), 1));
	if (*format == 'u')
		return (sizeuint(va_arg(args, unsigned int), 1));
	if (*format == 'p')
		return (sizeptr(va_arg(args, void *), 1));
	return (-1);
}
/*
int main(void)
{
void	argf(const char *format, ...)
	{
	va_list args;
	va_start(args, format);
	casos(format, args);
	va_end(args);
	}

	
	int x;
	x = 159;
	argf("x", x);
}
*/
