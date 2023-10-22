/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:51:06 by cristian          #+#    #+#             */
/*   Updated: 2023/10/15 15:31:58 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	e(int n, int exp)
{
	int	num;

	num = 1;
	if (exp > 0)
	{
		while (exp > 0)
		{
			num *= n;
			exp--;
		}
	}
	if (exp < 0)
		return (0);
	if (n == 0 && exp == 0)
		return (1);
	return (num);
}

static int	lin(int n)
{
	int	l;
	int	len;

	l = n;
	len = 1;
	while (l / 10)
	{
		l = l / 10;
		len++;
	}
	return (len);
}

char	*loop(int n, int num, int neg)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * num + (1 * neg));
	if (str == NULL)
		return (NULL);
	while (i - 1 + (1 * neg) < num - 1 + (1 * neg))
	{
		if (n < 0)
		{
			n = -n;
			str[0] = '-';
		}
		str[i - 1 + (1 * neg)] = (n / e(10, num - i - 1) % 10) + 48;
		i++;
	}
	str[i - 1 + (1 * neg)] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		num;
	char	*str;

	neg = 1;
	num = lin(n);
	if (n < 0)
		neg++;
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	return (loop(n, num, neg));
}
/*
#include <stdio.h>

int main(void)
{
	int n = -2147483647;
	printf("%s", ft_itoa(n -1));
}
*/
