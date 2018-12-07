/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:41:43 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/07 10:50:29 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*write_null(void)
{
	char		*null;

	if (!(null = ft_strnew(6)))
		return (NULL);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
	return (null);
}

char			*conv_c(va_list ap)
{
	char	c;
	char	*str;

	c = va_arg(ap, int);
	str = NULL;
	if (!(str = ft_strnew(1)))
		return (NULL);
	if (c)
		str[0] = c;
	else
		return (NULL);
	return (str);
}

char			*conv_s(va_list ap)
{
	char	*arg;
	char	*str;
	int		i;

	arg = va_arg(ap, char*);
	str = NULL;
	if (arg)
	{
		if (!(str = ft_strnew(ft_strlen(arg))))
			return (NULL);
		i = 0;
		while (arg[i])
		{
			str[i] = arg[i];
			i++;
		}
	}
	else
	{
		if (!(str = write_null()))
			return (NULL);
	}
	return (str);
}

int				conv_char(va_list ap, t_elem *elem)
{
	char	*str;
	char	modif;

	str = NULL;
	modif = (elem->modif) ? \
			trans_modif(elem->modif) : '0';
	if (elem->conv == 's' && modif != 'l')
		str = conv_s(ap);
	else if (elem->conv == 'c' || elem->conv == 'C')
	{
		if (!(str = conv_c(ap)))
		{
			elem->isnull = 1;
			str = NULL;
		}
	}
	elem->str = str;
	return (write_char(elem));
}
