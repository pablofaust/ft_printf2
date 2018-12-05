/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:19:21 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 12:33:53 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_percent(const char *format, int *i)
{
	int		j;

	j = *i + 1;
	if (format[j] == '-')
		j++;
	while (format[j] && ft_isdigit(format[j]))
		j++;
	if (format[j] == '%')
		return (j - *i - 1);
	return (0);
}

int				percent_parsing(const char *format, int *i, t_elem *elem)
{
	int		j;
	int		len;

	if ((format[*i + 1] && format[*i + 1] == '%') || \
			(format[*i + 1] && format[*i + 1] == ' ' \
			&& format[*i + 2] && format[*i + 2] == '%'))
	{
		elem->plain = 1;
		if (!(elem->str = ft_strnew(1)))
			return (0);
		elem->str[0] = '%';
		*i = (format[*i + 1] == '%') ? *i + 1 : *i + 2;
		return (1);
	}
	j = 0;
	if (format[*i + 1] && (len = get_percent(format, i)))
	{
		(*i)++;
		elem->plain = 1;
		if (!(elem->width = ft_strnew(len)))
			return (0);
		while (j < len)
			elem->width[j++] = format[(*i)++];
	}
	return (1);
}
