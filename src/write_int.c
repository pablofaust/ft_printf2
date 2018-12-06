/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecrire_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:47:00 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/06 10:32:05 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		trans_modif(char *modif)
{
	int		len;

	len = ft_strlen(modif);
	if (len == 1)
		return (modif[0]);
	else if (len == 2)
	{
		if (modif[0] == 'h')
			return ('H');
		else
			return ('L');
	}
	else
		return ('0');
}

static int	is_null(char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (1);
	return (0);
}

int			write_int(t_elem *elem)
{
	int		width;
	int		initial;
	int		prec;

	if (is_null(elem->str))
		elem->isnull = 1;
	width = (elem->width) ? ft_atoi(elem->width) : 0;
	initial = ft_strlen(elem->str);
	if (elem->str[0] == '-')
		elem->neg = 1;
	prec = (elem->prec) ? ft_atoi(elem->prec) : 0;
	if (elem->plus)
		elem->str = modif_plus(elem, '+');
	if (!elem->plus && elem->space)
		elem->str = modif_plus(elem, ' ');
	if (elem->prec != NULL)
		elem->str = modif_prec(elem, prec, initial);
	if (elem->hash)
		elem->str = modif_hash(elem, elem->conv, initial);
	if (width && width > initial)
		elem->str = handle_width(elem, width, initial);
	return (1);
}
