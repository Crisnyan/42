/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanica- <cmanica-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:48:09 by cmanica-          #+#    #+#             */
/*   Updated: 2024/01/28 15:56:47 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	pf_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) != -1)
		return(write(fd, &c, 1));
	return (-1);
	
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

int main(void)
{
	char c = '\v';
	printf("%ld", write(1, &c, 1));
}
