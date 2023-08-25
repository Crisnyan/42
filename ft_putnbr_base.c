/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:36:01 by cristian          #+#    #+#             */
/*   Updated: 2023/08/25 02:08:13 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

void	ft_putnbr_base(int nbr, char *base)
{
	char	neg;
	char	result;

	neg = '-';
	if (blen(base) <= 1)
	{
		return ;
	}
	if (nbr < 0) 
	{
		write(1, &neg, 1);
		nbr = -nbr;
	}
	if (nbr >= blen(base))
	{
		ft_putnbr_base(nbr / blen(base), base);
		nbr = nbr % blen(base);
	}
	if (nbr < blen(base))
	{
		result = nbr + 48;
		write(1, &result, 1);
	}
}

int	main(void)
{
	int	num;
	char	*base;

	base = "01";
	num = -24789243;

	ft_putnbr_base(num, base);
}

