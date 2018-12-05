/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles_binaires.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:57:58 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 12:09:11 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*complete_exp(char *str)
{
	int		len;
	char	*exp;
	int		i;

	len = ft_strlen(str);
	if (len == 11)
		return (str);
	if (!(exp = ft_strnew(11)))
		return (NULL);
	i = 0;
	while (i < 11 - len)
		exp[i++] = '0';
	if (!(ft_strcat(exp, str)))
		return (NULL);
	return (exp);
}

char	*fill_bits(double n, char *exp, char *reals, char *decimals)
{
	char	*bits;

	if (!(bits = ft_strnew(64)))
		return (NULL);
	bits[0] = (n > 0) ? '0' : '1';
	if (!(ft_strcat(bits, exp)))
		return (NULL);
	if (!(ft_strcat(bits, reals)))
		return (NULL);
	if (!(ft_strcat(bits, decimals)))
		return (NULL);
	return (bits);
}

char	*doutoa(double n)
{
	char	*reals;
	int		exp_int;
	char	*exp_char;
	char	*decimals;
	char	*bits;

	exp_int = 1;
	if (!(reals = double_reals(n, &exp_int)))
		return (NULL);
	if (!(exp_char = complete_exp(ft_itoa_base(exp_int + 1023, 2))))
		return (NULL);
	if (!(decimals = double_decimals(ABS(n) \
					- (double)ABS((int)n), 52 - exp_int)))
		return (NULL);
	if (exp_int < 0)
	{
		if (!(decimals = ft_truncate(decimals, ABS(exp_int), '<')))
			return (NULL);
	}
	if (!(bits = fill_bits(n, exp_char, reals, decimals)))
		return (NULL);
	return (bits);
}
