/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maillons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:24:59 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 12:16:38 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				nb_elems(t_elem **elems)
{
	t_elem			*ptr;
	int				nb;

	if (elems == NULL)
		return (0);
	ptr = *elems;
	nb = 0;
	while (ptr)
	{
		ptr = ptr->next;
		nb++;
	}
	return (nb);
}

t_elem			*new_elem(void)
{
	t_elem		*elem;

	if (!(elem = malloc(sizeof(t_elem))))
		return (NULL);
	elem->plain = 0;
	elem->hash = 0;
	elem->zero = 0;
	elem->minus = 0;
	elem->plus = 0;
	elem->space = 0;
	elem->isnull = 0;
	elem->width = NULL;
	elem->prec = NULL;
	elem->modif = NULL;
	elem->conv = '0';
	elem->function = NULL;
	elem->str = NULL;
	elem->neg = 0;
	elem->len = 0;
	elem->next = NULL;
	return (elem);
}

void			add_elem(t_elem **elems, t_elem *elem)
{
	t_elem		*ptr;

	ptr = *elems;
	if (ptr == NULL)
		*elems = elem;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = elem;
	}
}
