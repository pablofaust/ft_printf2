/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:50:11 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:52:56 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		remplir_chaine(char *arg, t_maillon **maillon)
{
	int		totale;
	int		portion;
	int		i;
	int		j;

	totale = ft_strlen(arg);
	portion = totale;
	if ((*maillon)->largeur != NULL)
		totale = ft_atoi((*maillon)->largeur);
	if ((*maillon)->precision != NULL)
		portion = ft_atoi((*maillon)->precision);
	if (!((*maillon)->chaine = ft_strnew(totale)))
		return (0);
	i = 0;
	while ((*maillon)->largeur != NULL && i < totale - portion)
		(*maillon)->chaine[i++] = ' ';
	j = 0;
	while (i <= totale && portion--)
		(*maillon)->chaine[i++] = arg[j++];
	if ((*maillon)->precision == NULL)
		(*maillon)->chaine[i] = '\0';
	return (1);
}

int		conversion_p_x(va_list ap, t_maillon **maillon)
{
	long long	arg;
	char		*itoa;

	arg = (long long)va_arg(ap, void*);
	if (!(itoa = ft_itoa_base_ll(arg, 16)))
		return (0);
	if (!((*maillon)->chaine = ft_strnew(ft_strlen(itoa) + 2)))
		return (0);
	if (!((*maillon)->chaine = ft_strjoin("0x", itoa)))
		return (0);
	return (1);
}

int		remplir_nb_moins(t_maillon **maillon, char *itoa, int precision, int neg)
{
	int		taille;
	int		zeros;
	int		i;
	int		largeur;
	int		j;

	largeur = 0;
	zeros = ft_never_negative(precision - (*maillon)->lon + neg);
	if ((*maillon)->largeur != NULL)
	{
		if (!(largeur = ft_atoi((*maillon)->largeur) - ((*maillon)->lon + zeros)))
			return (0);
	}
	taille = (precision != 0) ? precision + neg + largeur : (*maillon)->lon + largeur;
	if (!((*maillon)->chaine = ft_strnew(taille)))
		return (0);
	i= 0;
	j = 0;
	if (neg)
	{
		(*maillon)->chaine[i++] = '-';
		j++;
	}
	while (zeros && i <= zeros)
		(*maillon)->chaine[i++] = '0';
	while (itoa[j])
		(*maillon)->chaine[i++] = itoa[j++];
	while (largeur && i < largeur + zeros + j)
		(*maillon)->chaine[i++] = ' ';
	return (1);
}

int		remplir_nb(t_maillon **maillon, char *itoa, int precision, int neg)
{
	int		taille;
	int		zeros;
	int		i;
	int		largeur;
	int		j;

	largeur = 0;
	zeros = ft_never_negative(precision - (*maillon)->lon + neg);
	if ((*maillon)->largeur != NULL)
	{
		if (!(largeur = ft_atoi((*maillon)->largeur) - ((*maillon)->lon + zeros)))
			return (0);
	}
	taille = (precision != 0) ? precision + neg + largeur : (*maillon)->lon + largeur;
	if (!((*maillon)->chaine = ft_strnew(taille)))
		return (0);
	i= 0;
	while (largeur && i < largeur)
		(*maillon)->chaine[i++] = ' ';
	j = 0;
	if (neg)
	{
		(*maillon)->chaine[i++] = '-';
		j++;
	}
	while (zeros && i <= largeur + zeros)
		(*maillon)->chaine[i++] = '0';
	while (itoa[j])
		(*maillon)->chaine[i++] = itoa[j++];
	return (1);
}
