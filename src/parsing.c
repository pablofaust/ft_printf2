/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:18:11 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 12:31:38 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_flag(char a)
{
	if (a == '#' || a == '0' || a == '-' || a == '+' || a == ' ')
		return (1);
	else
		return (0);
}

int				is_modif(char a)
{
	if (a == 'h' || a == 'l' || a == 'j' || a == 'z' || a == 'L')
		return (1);
	else
		return (0);
}

int				is_conv(char a)
{
	if (a == 's' || a == 'S' || a == 'p' || a == 'd' || a == 'D' \
			|| a == 'i' || a == 'o' || a == 'O' || a == 'u' \
			|| a == 'U' || a == 'x' || a == 'X' || a == 'c' \
			|| a == 'C' || a == 'f')
		return (1);
	else
		return (0);
}

static int		conv_parsing(const char *format, int *i, t_elem *elem)
{
	while (format[(*i)++])
	{
		if (is_flag(format[*i]) && !flags(format, &i, elem))
			return (0);
		if (ft_isdigit(format[*i]) && !width(format, &i, elem))
			return (0);
		if (format[*i] == '.' && !precision(format, &i, elem, 0))
			return (0);
		if (is_modif(format[*i]) & !length(format, &i, elem))
			return (0);
		if (is_conv(format[*i]))
		{
			if (!(conversion(format, &i, elem)))
				return (0);
			return (1);
		}
		else
		{
			(*i)--;
			return (1);
		}
		(*i)++;
	}
	return (1);
}

int				parsing(const char *format, t_elem **elems)
{
	t_elem			*elem;
	int				i;
	int				len;

	i = -1;
	len = ft_strlen(format);
	while (++i < len)
	{
		if (!(elem = new_elem()))
			return (0);
		if (format[i] == '%')
			percent_parsing(format, &i, elem);
		if (format[i] == '%' && format[i + 1] && format[i + 1] != '%')
		{
			if (!(conv_parsing(format, &i, elem)))
				return (0);
		}
		else
		{
			if (!(plain_parsing(format, &i, elem)))
				return (0);
		}
		add_elem(elems, elem);
	}
	return (1);
}
