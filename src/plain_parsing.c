/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ordinaires.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:31:06 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 10:31:07 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			add_str(t_elem **elem, int j, char a)
{
	char		*new;
	int			i;

	i = 0;
	if ((*elem)->str == NULL)
	{
		if (!((*elem)->str = malloc(sizeof(char) * 2)))
			return (0);
		(*elem)->str[i] = a;
		(*elem)->str[i + 1] = '\0';
		return (1);
	}
	else
	{
		if (!(new = malloc(sizeof(char) * j + 1)))
			return (0);
		while (i <= j)
		{
			new[i] = (*elem)->str[i];
			i++;
		}
		new[j] = a;
		new[j + 1] = '\0';
		(*elem)->str = new;
		return (1);
	}
}

int				plain_parsing(const char *format, int *i, t_elem **elem)
{
	int			j;

	j = 0;
	while (format[*i])
	{
		if (format[*i] == '%')
		{
			if (format[*i - 1] && format[*i - 1] != '%' && format[*i + 1] && format[*i + 1] != '%')
			{
				(*i)--;
				return (1);
			}
		}
		if (!(add_str(elem, j, format[*i])))
			return (0);
		j++;
		(*i)++;
	}
	return (1);
}
