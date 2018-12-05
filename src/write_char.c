/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:51:36 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 12:51:37 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_null(char *str)
{
	if (!str)
		return (1);
	return (0);
}

int				write_char(t_elem *elem)
{
	int		width;
	int		initial;
	int		prec;

	if (is_null(elem->str))
	{
		elem->str = NULL;
		return (1);
	}
	if (elem->str == NULL)
		return (1);
	width = (elem->width) ? ft_atoi(elem->width) : 0;
	initial = ft_strlen(elem->str);
	prec = (elem->prec) ? ft_atoi(elem->prec) : 0;
	if (elem->prec)
		elem->str = modif_prec(elem, prec, initial);
	initial = (elem->str != NULL) ? ft_strlen(elem->str) : 0;
	if (width && width > initial)
		elem->str = handle_width(elem, width, initial);
	return (1);
}
