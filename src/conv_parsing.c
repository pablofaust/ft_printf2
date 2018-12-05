/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:29:36 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 12:05:19 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flags(char const *format, int **i, t_elem *elem)
{
	if (format[**i - 1] != '%')
		return (1);
	while (is_flag(format[**i]))
	{
		if (format[**i] == '#')
			elem->hash = 1;
		if (format[**i] == '0')
			elem->zero = 1;
		if (format[**i] == '-')
			elem->minus = 1;
		if (format[**i] == '+')
			elem->plus = 1;
		if (format[**i] == ' ')
			elem->space = 1;
		(**i)++;
	}
	return (1);
}

int			width(const char *format, int **i, t_elem *elem)
{
	int		j;
	int		nb;
	int		k;

	j = **i;
	nb = 0;
	if (elem->width != NULL || elem->prec != NULL \
			|| elem->modif != NULL || elem->conv != '0')
		return (0);
	while (ft_isdigit(format[j]))
	{
		nb++;
		j++;
	}
	if (!(elem->width = malloc(sizeof(char) * nb + 1)))
		return (0);
	k = 0;
	while (ft_isdigit(format[**i]))
	{
		elem->width[k] = format[**i];
		(**i)++;
		k++;
	}
	elem->width[k] = '\0';
	return (1);
}

int			precision(const char *format, int **i, t_elem *elem, int nb)
{
	int		j;
	int		k;

	if (elem->prec != NULL || elem->modif != NULL || elem->conv != '0')
		return (0);
	(**i)++;
	j = **i;
	while (ft_isdigit(format[j]))
	{
		nb++;
		j++;
	}
	if (!(elem->prec = malloc(sizeof(char) * nb + 1)))
		return (0);
	k = 0;
	if (nb == 0)
	{
		elem->prec[0] = '.';
		k++;
	}
	while (ft_isdigit(format[**i]))
		elem->prec[k++] = format[(**i)++];
	elem->prec[k] = '\0';
	return (1);
}

int			length(const char *format, int **i, t_elem *elem)
{
	int		j;
	int		nb;
	int		k;

	if (elem->modif != NULL || elem->conv != '0')
		return (0);
	j = **i;
	nb = 0;
	while (is_modif(format[j++]))
		nb++;
	if (nb > 2)
		return (0);
	if (!(elem->modif = malloc(sizeof(char) * nb + 1)))
		return (0);
	k = 0;
	while (is_modif(format[**i]))
	{
		elem->modif[k] = format[**i];
		(**i)++;
		k++;
	}
	elem->modif[k] = '\0';
	return (1);
}

int			conversion(const char *format, int **i, t_elem *elem)
{
	char	c;

	if (elem->conv != '0')
		return (0);
	c = format[**i];
	elem->conv = c;
	if (c == 's' || c == 'c' || c == 'C')
		elem->function = conv_char;
	else if (c == 'd' || c == 'D' || c == 'i' || c == 'p')
		elem->function = conv_int;
	else if (c == 'o' || c == 'O' || c == 'x' || \
			c == 'X' || c == 'u' || c == 'U')
		elem->function = conv_uint;
	else if (c == 'S')
		elem->function = conv_char;
	else if (c == 'f')
		elem->function = conv_float;
	return (1);
}
