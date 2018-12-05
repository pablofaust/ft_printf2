/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:12:10 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 12:12:25 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*double_decimals(double n, int len)
{
	char	*decimals;
	int		i;

	if (!(decimals = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		n = n * 2;
		decimals[i++] = (n >= 1) ? '1' : '0';
		n = n - (int)n;
	}
	return (decimals);
}

static void			neg_exp(double n, int *exp)
{
	char	*decimals;
	int		i;

	decimals = double_decimals(n, 28);
	i = 0;
	while (decimals[i] && decimals[i] != '1')
		i++;
	*exp = -i - 1;
}

char				*double_reals(double n, int *exp)
{
	char	*reals;
	int		i;
	int		j;

	if (!(reals = ft_itoa_base(ABS((int)n), 2)))
		return (NULL);
	i = 0;
	j = 0;
	if (ft_strrchr(reals, '1'))
	{
		while (reals[i])
		{
			if (reals[i] == '1' && j == 0)
				j = i + 1;
			i++;
		}
		*exp = (i > j) ? i - j : j - 1;
		return (ft_dir_strncpy(reals, ABS(*exp), '>'));
	}
	else
	{
		neg_exp(n, exp);
		return (ft_dir_strncpy(reals, ABS(*exp), '>'));
	}
}
