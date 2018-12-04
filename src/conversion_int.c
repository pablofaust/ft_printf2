/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:46:40 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:49:52 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			connaitre_base(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'b')
		return (2);
	return (10);
}

char		*hexa(long long arg, t_maillon **maillon)
{
	char	*chaine;
	char	*itoa;

	chaine = (*maillon)->chaine;
	if (!(itoa = ft_itoa_base_ll(arg, 16)))
		return (chaine);
	if (!(chaine = ft_strnew(ft_strlen(itoa) + 2)))
		return (chaine);
	if (!(chaine = ft_strjoin("0x", itoa)))
		return (chaine);
	return (chaine);
}

int			exceptions(char c)
{
	if (c == 'U' || c == '0' || c == 'p')
		return (1);
	return (0);
}

int			conversion_uint(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	int		base;
	char	modif;

	chaine = NULL;
	base = connaitre_base((*maillon)->conversion);
	modif = ((*maillon)->modificateur) ?\
			trans_modif((*maillon)->modificateur) : '0';
	if (modif == 'h' && !exceptions((*maillon)->conversion))
		chaine = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), base);
	else if (modif == 'H' && !exceptions((*maillon)->conversion))
		chaine = ft_itoa_base((unsigned char)va_arg(ap, unsigned int), base);
	else if (modif == 'l' || exceptions((*maillon)->conversion))
		chaine = ft_itoa_base_ll(va_arg(ap, unsigned long), base);
	else if (modif == 'L')
		chaine = ft_itoa_base_ll(va_arg(ap, unsigned long long), base);
	else if (modif == 'j')
		chaine = ft_itoa_base_ll(va_arg(ap, uintmax_t), base);
	else if (modif == 'z')
		chaine = ft_itoa_base_ll(va_arg(ap, size_t), base);
	else
		chaine = ft_itoa_base(va_arg(ap, unsigned int), base);
	(*maillon)->chaine = chaine;
	return (ecrit_int(maillon));
}

int			conversion_int(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ?\
			trans_modif((*maillon)->modificateur) : '0';
	if ((*maillon)->conversion == 'p')
		chaine = hexa((long long)va_arg(ap, void*), maillon);
	else if (modif == '0' && (*maillon)->conversion != 'D')
		chaine = ft_itoa(va_arg(ap, int));
	else if (modif == 'H' && (*maillon)->conversion != 'D')
		chaine = ft_itoa((char)va_arg(ap, int));
	else if (modif == 'h' && (*maillon)->conversion != 'D')
		chaine = ft_itoa_ll((short)va_arg(ap, int));
	else if (modif == 'l' || (*maillon)->conversion == 'D')
		chaine = ft_itoa_ll(va_arg(ap, long));
	else if (modif == 'L')
		chaine = ft_itoa_ll(va_arg(ap, long long));
	else if (modif == 'j')
		chaine = ft_itoa_ll(va_arg(ap, intmax_t));
	else if (modif == 'z')
		chaine = ft_itoa_ll(va_arg(ap, ssize_t));
	(*maillon)->chaine = chaine;
	return (ecrit_int(maillon));
}
