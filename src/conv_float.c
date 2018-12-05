/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:45:55 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 11:08:47 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*round_decimals(char *str, unsigned long long tmp)
{
	int		len;
	int		i;
	int		nine;

	if (tmp < 5)
		return (str);
	len = ft_strlen(str);
	i = len - 1;
	if (str[i] && tmp >= 5)
	{
		nine = 1;
		while (str[i] && nine == 1)
		{
			if (str[i] == '9')
				str[i] = '0';
			else
			{
				str[i]++;
				nine--;
			}
			i--;
		}
	}
	return (str);
}

char	*double_decimals(double n, int prec)
{
	char				*str;
	unsigned long long	pow;
	long double			decimals;
	int					i;
	unsigned long long	tmp;

	if (!(str = ft_strnew(prec)))
		return (NULL);
	pow = 1000000000000000000;
	decimals = ABS(n) - (double)ABS((int)n);
	tmp = (unsigned long long)(decimals * pow);
	i = 0;
	while (i < prec)
	{
		pow = pow / 10;
		str[i] = (decimals) ? (tmp / pow) + 48 : '0';
		tmp = tmp % pow;
		i++;
	}
	return (round_decimals(str, tmp / ft_int_pow(tmp)));
}

int		conv_float(va_list ap, t_elem *elem)
{
	char	*str;
	char	modif;
	double	arg;
	int		prec;

	str = NULL;
	modif = (elem->modif) ? trans_modif(elem->modif) : '0';
	arg = (modif == 'L') ? va_arg(ap, long double) : va_arg(ap, double);
	prec = ft_atoi(elem->prec);
	if (prec > 17 || !elem->prec)
		prec = 6;
	if (!(str = ft_strnew(ft_strlen(ft_itoa((int)arg)) + prec)))
		return (0);
	if (arg < 0)
		str[0] = '-';
	if (!(str = ft_strcat(str, ft_itoa(ABS((int)arg)))))
		return (0);
	if (!(str = ft_strcat(str, ".")))
		return (0);
	if (!(str = ft_strcat(str, double_decimals(arg, prec))))
		return (0);
	elem->str = str;
	return (write_int(elem));
}
