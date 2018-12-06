/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:10:04 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/06 10:31:36 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*uppercase(char *str)
{
	char	*new;
	char	c;
	int		i;

	new = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		c = str[i];
		new[i] = (c >= 97 && c <= 122) ? c - 32 : c;
		i++;
	}
	free(str);
	return (new);
}

static int		percent_width(t_elem *elem)
{
	int		len;
	int		i;

	free(elem->str);
	len = ft_atoi(elem->width);
	if (!(elem->str = ft_strnew(ABS(len))))
		return (0);
	i = 0;
	if (len < 0)
	{
		elem->str[i++] = '%';
		while (i < ABS(len))
			elem->str[i++] = (elem->width[0] == '0') ? '0' : ' ';
	}
	else
	{
		while (i < ABS(len) - 1)
			elem->str[i++] = (elem->width[0] == '0') ? '0' : ' ';
		elem->str[i] = '%';
	}
	return (1);
}

int				check_isnull(t_elem *ptr)
{
	int		nb;

	nb = (ft_atoi(ptr->width) > 0) ? ft_atoi(ptr->width) : 1;
	if (ptr->isnull && ptr->conv == 'c')
	{
		write(1, " ", nb - 1);
		write(1, "\0", 1);
		return (1);
	}
	return (1);
}

int				read_all(t_elem *elems)
{
	t_elem	*ptr;
	int		len;
	int		count;

	len = 0;
	count = 0;
	ptr = elems;
	while (ptr)
	{	
		if (check_isnull(ptr))
			;
		if (ptr->str != NULL)
		{
			if (ptr->plain == 1 && ptr->width != NULL)
				if (!(percent_width(ptr)))
					return (0);
			len = ft_strlen(ptr->str);
			if (ptr->conv == 'X')
				ptr->str = uppercase(ptr->str);
			write(1, ptr->str, len);
			count = count + len;
		}
		else if (!ptr->str && ptr->conv == 'c')
			count = (ptr->width) ? count + ft_atoi(ptr->width) : count + 1;
		ptr = ptr->next;
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	t_elem		*elems;
	va_list		ap;
	int			count;

	elems = NULL;
	if (!(parsing(format, &elems)))
		return (-1);
	va_start(ap, format);
	if (!(handling(ap, &elems)))
		return (-1);
	count = read_all(elems);
	return (count);
}
