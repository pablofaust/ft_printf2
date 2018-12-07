/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:46:40 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/07 16:00:13 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_base(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'b')
		return (2);
	return (10);
}

char		*hexa(long long arg)
{
	char	*str;
	char	*itoa;

	if (!(itoa = ft_itoa_base_ll(arg, 16)))
		return (NULL);
	/*if (!(str = ft_strnew(ft_strlen(itoa) + 2)))
	{
		printf("fail maloc etape : %s, itoa len : %d, address : %p \n", itoa, ft_strlen(itoa), &itoa);
		if (itoa)
			free(itoa);
		return (NULL);
	}*/
	if (!(str = ft_strjoin("0x", itoa)))
	{
		if (str)
			free(str);
		if (itoa)
			free(itoa);
		return (NULL);
	}
	if (itoa)
	{
		free(itoa);
		itoa = NULL;
	}
	return (str);
}

int			exceptions(char c)
{
	if (c == 'U' || c == '0' || c == 'p')
		return (1);
	return (0);
}

int			conv_uint(va_list ap, t_elem *elem)
{
	char	*str;
	int		base;
	char	modif;

	str = NULL;
	base = get_base(elem->conv);
	modif = (elem->modif) ?\
			trans_modif(elem->modif) : '0';
	if (modif == 'h' && !exceptions(elem->conv))
		str = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), base);
	else if (modif == 'H' && !exceptions(elem->conv))
		str = ft_itoa_base((unsigned char)va_arg(ap, unsigned int), base);
	else if (modif == 'l' || exceptions(elem->conv))
		str = ft_itoa_base_ll(va_arg(ap, unsigned long), base);
	else if (modif == 'L')
		str = ft_itoa_base_ll(va_arg(ap, unsigned long long), base);
	else if (modif == 'j')
		str = ft_itoa_base_ll(va_arg(ap, uintmax_t), base);
	else if (modif == 'z')
		str = ft_itoa_base_ll(va_arg(ap, size_t), base);
	else
		str = ft_itoa_base(va_arg(ap, unsigned int), base);
	elem->str = str;
	return (write_int(elem));
}

int			conv_int(va_list ap, t_elem *elem)
{
	char	*str;
	char	modif;

	str = NULL;
	modif = (elem->modif) ? trans_modif(elem->modif) : '0';
	if (elem->conv == 'p')
		str = hexa((long long)va_arg(ap, void*));
	else if (modif == '0' && elem->conv != 'D')
		str = ft_itoa(va_arg(ap, int));
	else if (modif == 'H' && elem->conv != 'D')
		str = ft_itoa((char)va_arg(ap, int));
	else if (modif == 'h' && elem->conv != 'D')
		str = ft_itoa_ll((short)va_arg(ap, int));
	else if (modif == 'l' || elem->conv == 'D')
		str = ft_itoa_ll(va_arg(ap, long));
	else if (modif == 'L')
		str = ft_itoa_ll(va_arg(ap, long long));
	else if (modif == 'j')
		str = ft_itoa_ll(va_arg(ap, intmax_t));
	else if (modif == 'z')
		str = ft_itoa_ll(va_arg(ap, ssize_t));
	elem->str = str;
	return (write_int(elem));
}
