/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:38:28 by cristian          #+#    #+#             */
/*   Updated: 2023/10/02 19:02:54 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	
	while (i < 200)
	{
		printf("i es: %d\n", i);
		printf("tuya %s\n", (char *)calloc(i, i));
		printf("mia %s\n", (char *)ft_calloc(i, i));
		i++;
	}
}
*/
