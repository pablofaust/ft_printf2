/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecrire_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:47:00 by pfaust            #+#    #+#             */
/*   Updated: 2018/12/04 15:47:55 by pfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		trans_modif(char *modif)
{
	int		lon;

	lon = ft_strlen(modif);
	if (lon == 1)
		return (modif[0]);
	else if (lon == 2)
	{
		if (modif[0] == 'h')
			return ('H');
		else
			return ('L');
	}
	else
		return ('0');
}

static int	est_nul(char *str)
{
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (1);
	return (0);
}

int			ecrit_int(t_maillon **maillon)
{
	int		largeur;
	int		initial;
	int		precision;

	if (est_nul((*maillon)->chaine))
		(*maillon)->est_nul = 1;
	largeur = ((*maillon)->largeur) ? ft_atoi((*maillon)->largeur) : 0;
	initial = ft_strlen((*maillon)->chaine);
	if ((*maillon)->chaine[0] == '-')
		(*maillon)->neg = 1;
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 0;
	if ((*maillon)->att_plus)
		(*maillon)->chaine = modif_plus(maillon, '+');	
	if (!(*maillon)->att_plus && (*maillon)->att_espace)
		(*maillon)->chaine = modif_plus(maillon, ' ');	
	if ((*maillon)->precision != NULL)
		(*maillon)->chaine = modif_precision(maillon, precision, initial);
	if ((*maillon)->att_hash)
		(*maillon)->chaine = modif_hash(maillon, (*maillon)->conversion, initial);
	if (largeur && largeur > initial)
		(*maillon)->chaine = gestion_largeur(maillon, largeur, initial);
	return (1);
}


