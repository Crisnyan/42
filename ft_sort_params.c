/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 04:35:12 by cristian          #+#    #+#             */
/*   Updated: 2023/08/27 15:59:32 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
			{
				return (s1[i] - s2[i]);
			}
			if (s1[i] < s2 [i])
			{
				return (s2[i] - s1[i]);
			}
		}
		i++;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	n;

	n = 10;
	i = 0;
	while( 




	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write (1, &n, 1);
		i++;

	}
	return (0);
}
