/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_largeur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:18:53 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/06 10:43:59 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*width_zeros_x(t_elem *elem, char *new, int width)
{
	char	*str;
	int		i;
	int		j;
	int		x;

	str = elem->str;
	if (str[0] == '+' || str[0] == '-' || str[0] == ' ')
		new[0] = str[0];
	i = (str[0] == '+' || str[0] == '-' || str[0] == ' ') ? 1 : 0;
	j = (str[0] == '+' || str[0] == '-' || str[0] == ' ') ? 1 : 0;
	x = (str[0] == '+' || str[0] == '-' || str[0] == ' ') ? 3 : 2;
	new[i++] = '0';
	new[i++] = 'x';
	while (i < width - ft_strlen(str) + 2)
		new[i++] = '0';
	while (i < width - j)
		new[i++] = str[x++];
	return (new);
}

char		*width_zeros(t_elem *elem, char *new, int width)
{
	char	*str;
	int		i;
	int		j;

	str = elem->str;
	if (str[0] == '+' || str[0] == '-' || str[0] == ' ')
		new[0] = str[0];
	i = (str[0] == '+' || str[0] == '-' || str[0] == ' ') ? 1 : 0;
	j = (str[0] == '+' || str[0] == '-' || str[0] == ' ') ? 1 : 0;
	if (elem->hash && elem->conv == 'x')
		return (width_zeros_x(elem, new, width));
	while (i < width - ft_strlen(str) + j)
		new[i++] = '0';
	while (str[j])
		new[i++] = str[j++];
	return (new);
}

char		*width_bef(t_elem *elem, char *new, int prec, int initial)
{
	int		i;
	int		j;
	int		add;
	char	c;

	c = elem->conv;
	add = 0;
	if ((c == 'o' || c == 'O') && elem->hash)
		add = 1;
	else if ((c == 'd' || c == 'i') && (elem->plus || \
				elem->space) && elem->str[0] != '-')
		add = 1;
	else if ((c == 'x' || c == 'X') && elem->hash)
		add = 2;
	i = 0;
	if (elem->conv == 's' && !ft_strlen(elem->str) && ft_atoi(elem->width))
		prec = 0;
	if (prec > initial + elem->neg)
		prec = prec - initial + elem->neg;
	else if (prec != 0 && prec <= initial && prec < ft_atoi(elem->width) && !elem->neg)
		prec = 0;
	else if (prec != 0 && prec <= initial && prec < ft_atoi(elem->width) && elem->neg)
		prec = elem->neg;
	while (i < ft_atoi(elem->width) - initial - add - prec)
		new[i++] = ' ';
	j = 0;
	while (elem->str[j])
		new[i++] = elem->str[j++];
	return (new);
}

char		*width_aft(t_elem *elem, char *new, int width)
{
	char	*str;
	int		i;

	str = elem->str;
	i = -1;
	while (str[++i])
		new[i] = str[i];
	while (i < width)
		new[i++] = ' ';
	new[i] = '\0';
	return (new);
}

char		*handle_width(t_elem *elem, int width, int initial)
{
	char	*new;
	int		prec;

	if (elem->str == NULL)
	{
		if (!(new = width_null(width)))
			return (NULL);
		return (new);
	}
	if (elem->conv == 'f')
		elem->prec = NULL;
	prec = (elem->prec != NULL) ? ft_atoi(elem->prec) : 0;
	if (!(new = ft_strnew(width)))
		return (NULL);
	if (elem->minus)
		new = width_aft(elem, new, width);
	else
	{
		if (elem->zero && elem->prec == NULL)
			new = width_zeros(elem, new, width);
		else
			new = width_bef(elem, new, prec, initial);
	}
	return (new);
}
