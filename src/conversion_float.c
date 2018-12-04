/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:45:55 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:46:18 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*arrondi(char *str, unsigned long long tmp)
{
	int		len;
	int		i;
	int		neuf;

	if (tmp < 5)
		return (str);
	len = ft_strlen(str);
	i = len - 1;
	if (str[i] && tmp >= 5)
	{
		neuf = 1;
		while (str[i] && neuf == 1)
		{
			if (str[i] == '9')
				str[i] = '0';
			else
			{
				str[i]++;
				neuf--;
			}
			i--;
		}
	}
	return (str);
}

char	*doubles_decimales(double n, int precision)
{
	char				*chaine;
	unsigned long long	pow;
	long double			decimales;
	int					i;
	unsigned long long	tmp;

	if (!(chaine = ft_strnew(precision)))
		return (NULL);
	pow = 1000000000000000000;
	decimales = ABS(n) - (double)ABS((int)n);
	tmp = (unsigned long long)(decimales * pow);
	i = 0;
	while (i < precision)
	{
		pow = pow / 10;
		chaine[i] = (decimales) ? (tmp / pow) + 48 : '0';
		tmp = tmp % pow;
		i++;
	}
	return (arrondi(chaine, tmp / ft_int_pow(tmp)));
}

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;
	int		precision;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ?\
			trans_modif((*maillon)->modificateur) : '0';
	arg = (modif == 'L') ? va_arg(ap, long double) : va_arg(ap, double);
	precision = ft_atoi((*maillon)->precision);
	if (precision > 17 || !(*maillon)->precision)
		precision = 6;
	if (!(chaine = ft_strnew(ft_strlen(ft_itoa((int)arg)) + precision)))
		return (0);
	if (arg < 0)
		chaine[0] = '-';
	if (!(chaine = ft_strcat(chaine, ft_itoa(ABS((int)arg)))))
		return (0);
	if (!(chaine = ft_strcat(chaine, ".")))
		return (0);
	if (!(chaine = ft_strcat(chaine, doubles_decimales(arg, precision))))
		return (0);
	(*maillon)->chaine = chaine;
	return (ecrit_int(maillon));
}
