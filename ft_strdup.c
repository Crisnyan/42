/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:56:46 by cristian          #+#    #+#             */
/*   Updated: 2023/10/02 19:56:51 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[20] = "";
	char s2[20] = "muy buenas";

//	printf("%s \n",ft_strdup(s1));	
//	printf("%s \n",ft_strdup(s2));
	printf("%s \n",strdup(s1));
	printf("%s \n",strdup(s2));

}
*/	
