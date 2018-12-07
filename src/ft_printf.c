/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:10:04 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/07 10:54:44 by pfaust           ###   ########.fr       */
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

int				read_simple(t_elem *ptr, int *count)
{
	int		len;

	len = 0;
	if (ptr->plain == 1 && ptr->width != NULL)
		if (!(percent_width(ptr)))
			return (0);
	len = ft_strlen(ptr->str);
	if (ptr->conv == 'X')
		ptr->str = uppercase(ptr->str);
	write(1, ptr->str, len);
	*count = *count + len;
	return (1);
}

int				read_all(t_elem *elems)
{
	t_elem	*ptr;
	int		count;

	count = 0;
	ptr = elems;
	while (ptr)
	{
		if (check_isnull(ptr))
			;
		if (ptr->str != NULL)
		{
			if (!(read_simple(ptr, &count)))
				return (0);
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
	free_elems(elems);
	return (count);
}
