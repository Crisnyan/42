/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:48:09 by cmanica-          #+#    #+#             */
/*   Updated: 2024/01/28 17:44:02 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	pf_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	else
		return (1);
}

int	pf_putstr_fd(char *str, int fd)
{
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		pf_putchar_fd(*str, fd);
		str++;
	}
	return (ft_strlen(str));
}

void	*pfalloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}
