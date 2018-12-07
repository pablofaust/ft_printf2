/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maillons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:24:59 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/07 10:37:15 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_elem		*ft_lstfree(t_elem *elems)
{
	t_elem *ptr;
	t_elem	*next;

	ptr = elems;
	while (ptr)
	{
		next = ptr->next;
		if (ptr->width)
			free(ptr->width);
		if (ptr->prec)
			free(ptr->prec);
		if (ptr->modif)
			free(ptr->modif);
		if (ptr->str)
			free(ptr->str);
		ptr->next = NULL;
		free(ptr);
		ptr = next;
	}
	return (NULL);
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
