#include "ft_printf.h"

static int		est_nul(char *str)
{
	if (!str)
		return (1);
	return (0);
}

int				ecrit_char(t_maillon **maillon)
{
	int		largeur;
	int		initial;
	int		precision;

	if (est_nul((*maillon)->chaine))
	{
		(*maillon)->chaine = NULL;
		return (1);
	}
	if ((*maillon)->chaine == NULL)
		return (1);
	largeur = ((*maillon)->largeur) ? ft_atoi((*maillon)->largeur) : 0;
	initial = ft_strlen((*maillon)->chaine);
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 0;
	if ((*maillon)->precision)
		(*maillon)->chaine = modif_precision(maillon, precision, initial);
	initial = ((*maillon)->chaine != NULL) ? ft_strlen((*maillon)->chaine) : 0;
	if (largeur && largeur > initial)
		(*maillon)->chaine = gestion_largeur(maillon, largeur, initial);
	return (1);
}
