/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_att.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:08:27 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/05 10:40:27 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_zero_o(t_elem **elem, char *str, int initial)
{
	int		len;
	char	*new;
	int		prec;
	
	prec = ft_atoi((*elem)->prec);
	len = (str) ? ft_strlen(str) : 0;
	if ((*elem)->isnull)
	{
		if (ft_atoi((*elem)->width) > 1)
			(*elem)->width = ft_itoa(ft_atoi((*elem)->width) + 1);
		if ((*elem)->prec == NULL || ft_atoi((*elem)->prec) == 1)
			return (str);
	}
	if (prec > initial)
		return (str);
	if (!(new = ft_strnew(len + 1)))
		return (str);
	new[0] = '0';
	if (!str)
		return (new);
	new = ft_strncat(new, str, len);
	free(str);
	return (new);
}

char		*add_0x_x(t_elem **elem)
{
	char	*str;
	char	c;
	int		len;
	char	*new;

	c = (*elem)->conv;
	str = (*elem)->str;
	if ((*elem)->isnull)
		return (str);
	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
		return (str);
	if (!(new = ft_strnew(len + 2)))
		return (str);
	new[0] = '0';
	new[1] = (c == 'x') ? 'x' : 'X';
	new = ft_strncat(new, str, len);
	free(str);
	return (new);
}

char		*modif_hash(t_elem **elem, char c, int initial)
{
	if (c == 'o' || c == 'O')
		return (add_zero_o(elem, (*elem)->str, initial));
	else if (c == 'x' || c == 'X')
		return (add_0x_x(elem));
	return ((*elem)->str);
}

char		*modif_plus(t_elem **elem, char c)
{
	char	*str;
	char	*new;
	int		len;
	char	conv;

	str = (*elem)->str;
	len = ft_strlen(str);
	conv = (*elem)->conv;
	if (conv == 'd' || conv == 'i' || conv == 'f')
	{
		if (str[0] != '-')
		{
			if (!(new = ft_strnew(len + 1)))
				return (str);
			new[0] = c;
			new = ft_strncat(new, str, len);
			free(str);
			return (new);
		}
	}
	return (str);
}
