/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_db.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:09:36 by pfaust            #+#    #+#             */
/*   Updated: 2018/11/26 10:33:24 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lon_entiers(double n)
{
	int		entiers;
	int		lon;

	entiers = ABS((int)n);
	lon = 0;
	while (entiers > 0)
	{
		entiers = entiers / 10;
		lon++;
	}
	return (lon);
}

static char		*ft_ajout_entiers(double n, int lon)
{
	int		entiers;
	int		pow;
	char	*chaine;
	int		i;

	if (!(chaine = ft_strnew(lon)))
		return (NULL);
	entiers = ABS((int)n);
	if (entiers == 0)
	{
		chaine[0] = '0';
		return (chaine);
	}
	pow = ft_pow(lon);
	i = 0;
	while (entiers > 0)
	{
		chaine[i++] = (entiers / pow) + 48;
		entiers = entiers % pow;
		pow = pow / 10;
	}
	return (chaine);
}

static char		*ft_ajout_decimales(double n, int precision, int pow)
{
	char	*chaine;
	int		entiers;
	double	decimales;
	int		tmp1;
	int		tmp2;
	int		i;

	if (!(chaine = ft_strnew(precision + 1)))
		return (NULL);
	i = -12;
	entiers = ABS((int)n);
	decimales = ABS(n) - (double)entiers;
	tmp1 = (int)(decimales * pow);
	tmp2 = (int)(decimales * pow);
	i = 0;
	chaine[i++] = '.';
	while (precision > 0)
	{
		pow = pow / 10;
		chaine[i++] = (tmp2) ? (tmp1 / pow) + 48 : '0';
		tmp1 = tmp1 % pow;
		precision--;
	}
	return (chaine);
}

char			*ft_itoa_db(double n, int precision)
{
	char	*chaine;
	int		neg;
	int		lon;
	int		i;
	int		pow;

	neg = (n < 0) ? 1 : 0;
	lon = ft_lon_entiers(n);
	if (!(chaine = ft_strnew(lon + 1 + precision)))
		return (NULL);
	i = 0;
	if (neg)
		chaine[i++] = '-';
	if (!(chaine = ft_strcat(chaine, ft_ajout_entiers(n, lon))))
		return (NULL);
	pow = ft_pow(precision + 1);
	if (!(chaine = ft_strcat(chaine, ft_ajout_decimales(n, precision, pow))))
		return (NULL);
	return (chaine);
}
