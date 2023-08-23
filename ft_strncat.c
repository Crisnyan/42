/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 02:04:57 by cristian          #+#    #+#             */
/*   Updated: 2023/08/23 02:11:07 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	int		i;

	i = 0;
	j = 0;
	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return(dest);
}

#include <stdio.h>

int	main(void)
{
	char s1[] = "Hola ";
	char s2[] = "que ase";

	ft_strcat(s2,s1,1);
	printf("%s",ft_strcat(s2,s1,1));	
}	
