/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 01:47:35 by cristian          #+#    #+#             */
/*   Updated: 2023/08/25 14:50:42 by cmanica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	blen(char *base)
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
		while (base[k] != '\0' && base[k] != base[i])
		{
			if (base[k]  == base[i])
			{
				return (0);
			}
			k++;
		}
		i++;
	}
	return (i);
}

int	len(int num)
{
	int	i;

	i = 1;
	while (num > 10)
	{
		num = num/10;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	num;
	int	cum;

	neg = 0;
	num = 0;
	while (!(str[i] >= 48  && str[i] <= 57))
	{
		if (str[i] == '-')
		{
			neg++;
		}
		i++;
	}
	while (str[i] >= 48  && str[i] <= 57)
	{	
		num *= 10;
		num = (str[i] - 48);
		i++;
	}
	i = 0;
	cum = 0;
	while (i < len(num))
	{
	cum = ((num / 10**(len(num) - i)) % 10) * (len(num) - 1) * blen(base)**i;
	}
	// HAY QUE HACER UNA FUNCION QUE EXPONENCIE a^b T_T
	neg = neg % 2;
	if (neg == 1)
	{
		num = -num;
	}
	return (num);
}

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str;
	char *base;

	str = "   -+---+-1234ab5678";
	base = "01";
	printf("%d \n", ft_atoi_base(str, base));
}
