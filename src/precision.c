/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:22:10 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 11:20:58 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_zeros(char *new, char *str, int len, int prec)
{
	int		dif;
	int		i;
	int		sign;
	int		j;

	sign = (str[0] == '-' || str[0] == '+' || str[0] == ' ') ? 1 : 0;
	dif = prec - len + sign;
	i = (str[0] == '-' || str[0] == '+' || str[0] == ' ') ? 1 : 0;
	j = (str[0] == '-' || str[0] == '+' || str[0] == ' ') ? 1 : 0;
	while (i < dif + sign)
		new[i++] = '0';
	while (i <= prec)
		new[i++] = str[j++];
	return (new);
}

char		*prec_int(t_elem *elem, int prec)
{
	char	*str;
	char	*new;
	int		len;
	int		sign;

	str = elem->str;
	len = ft_strlen(str);
	sign = (str[0] == '-' || str[0] == '+' || str[0] == ' ') ? 1 : 0;
	if (prec == 0 && elem->prec[0] == '.' && elem->str == NULL)
		return (NULL);
	if (prec > len - sign)
	{
		if (!(new = ft_strnew(prec + sign)))
			return (str);
		if (sign)
			new[0] = str[0];
		new = add_zeros(new, str, len, prec);
		free(str);
		return (new);
	}
	else
		return (str);
}

char		*prec_char(t_elem *elem, int prec, int initial)
{
	char	*str;
	char	*new;
	int		i;

	if (prec == 0 && elem->prec[0] == '.')
		return (NULL);
	str = elem->str;
	if (prec < initial) 
	{
		if (!(new = ft_strnew(prec)))
			return (str);
		i = -1;
		while (str[++i] && i < prec)
			new[i] = str[i];
		return (new);
	}
	else
		return (str);
}

char	*check_zero(t_elem *elem)
{
	char	*str;

	if (elem->plus)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = '+';
		return (str);
	}
	return (NULL);
}

char		*modif_prec(t_elem *elem, int prec, int initial)
{
	char	c;

	if (elem->isnull && prec == 0)
		return (check_zero(elem));
	c = elem->conv;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (prec_int(elem, prec));
	else if (c == 's')
		return (prec_char(elem, prec, initial));
	return (elem->str);
}
