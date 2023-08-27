/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 01:47:35 by cristian          #+#    #+#             */
/*   Updated: 2023/08/26 00:59:09 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	e(int base, int exp)
{
	int	num;

	num = 1;
	if (exp > 0)
	{
		while (exp > 0)
		{
			num *= base;
			exp--;
		}
	}
	if (exp < 0)
	{
		exp = -exp;
		while (exp > 0)
		{
			num *= (1 / base);
			exp--;
		}
	}
	return (num);
}

int	bl(char *base)
{
	int	i;
	int	k;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		k = 0;
		while (base[k] != '\0')
		{
			if (base[k] == base[i] && k != i)
			{
				return (0);
			}
			k++;
		}
		i++;
	}
	return (i);
}

int	l(int num)
{
	int	i;

	i = 1;
	while (num > 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	cum_neg(int n, int neg, char *base)
{
	int	i;
	int	cum;
	int	p1;
	int	p2;

	i = 0;
	cum = 0;
	while (i < l(n))
	{
		p1 = (n / e(10, (l(n) - i - 1))) % 10;
		p2 = e(bl(base), l(n) - i - 1);
		cum += p1 * p2; 
		i++;
	}
	neg = neg % 2;
	if (neg == 1)
		cum = -cum;
	return (cum);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	neg;

	neg = 0;
	n = 0;
	while (!(str[i] >= 48 && str[i] <= 57))
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n *= 10;
		n += (str[i] - 48);
		i++;
	}
	return (cum_neg(n, neg, base));
}
/*
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str1;
	char *base1;
	char *str2;
	char *base2;
	char *base3;

	str1 = "   -+---+-1234ab5678";
	base1 = "poniguay";
	str2 = "+--++-+-10100110as234";
	base2 = "01";
	base3 = "11";
//	printf("%d \n", ft_atoi_base(str1, base1));
//	printf("%d \n", ft_atoi_base(str2, base2));
	printf("%d \n", ft_atoi_base(str2, base3));
}
*/
