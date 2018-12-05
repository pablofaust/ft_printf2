/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:50:11 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 11:09:57 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_str(char *arg, t_elem *elem)
{
	int		total;
	int		part;
	int		i;
	int		j;

	total = ft_strlen(arg);
	part = total;
	if (elem->width != NULL)
		total = ft_atoi(elem->width);
	if (elem->prec != NULL)
		part = ft_atoi(elem->prec);
	if (!(elem->str = ft_strnew(total)))
		return (0);
	i = 0;
	while (elem->width != NULL && i < total - part)
		elem->str[i++] = ' ';
	j = 0;
	while (i <= total && part--)
		elem->str[i++] = arg[j++];
	if (elem->prec == NULL)
		elem->str[i] = '\0';
	return (1);
}

int		fill_nb_minus(t_elem *elem, char *itoa, int prec, int neg)
{
	int		len;
	int		zeros;
	int		i;
	int		width;
	int		j;

	width = 0;
	zeros = ft_never_negative(prec - elem->len + neg);
	if (elem->width != NULL)
	{
		if (!(width = ft_atoi(elem->width) - (elem->len + zeros)))
			return (0);
	}
	len = (prec != 0) ? prec + neg + width : elem->len + width;
	if (!(elem->str = ft_strnew(len)))
		return (0);
	i= 0;
	j = 0;
	if (neg)
	{
		elem->str[i++] = '-';
		j++;
	}
	while (zeros && i <= zeros)
		elem->str[i++] = '0';
	while (itoa[j])
		elem->str[i++] = itoa[j++];
	while (width && i < width + zeros + j)
		elem->str[i++] = ' ';
	return (1);
}

int		fill_nb(t_elem *elem, char *itoa, int prec, int neg)
{
	int		len;
	int		zeros;
	int		i;
	int		width;
	int		j;

	width = 0;
	zeros = ft_never_negative(prec - elem->len + neg);
	if (elem->width != NULL)
	{
		if (!(width = ft_atoi(elem->width) - (elem)->len + zeros))
			return (0);
	}
	len = (prec != 0) ? prec + neg + width : elem->len + width;
	if (!(elem->str = ft_strnew(len)))
		return (0);
	i= 0;
	while (width && i < width)
		elem->str[i++] = ' ';
	j = 0;
	if (neg)
	{
		elem->str[i++] = '-';
		j++;
	}
	while (zeros && i <= width + zeros)
		elem->str[i++] = '0';
	while (itoa[j])
		elem->str[i++] = itoa[j++];
	return (1);
}
