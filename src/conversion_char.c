#include "ft_printf.h"


int		ecrit_char(t_maillon **maillon)
{
	int		largeur;
	int		initial;
	int		precision;

	largeur = ((*maillon)->largeur) ? ft_atoi((*maillon)->largeur) : 0;
	initial = ft_strlen((*maillon)->chaine);
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 0;
	if ((*maillon)->precision)
		(*maillon)->chaine = modif_precision(maillon, precision, initial);
	initial = ft_strlen((*maillon)->chaine);
	if (largeur && largeur > initial)
		(*maillon)->chaine = gestion_largeur(maillon, largeur, initial);
	return (1);
}

int		conversion_char(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	char	c;

	chaine = NULL;
	modif = ((*maillon)->modificateur ) ? trans_modif((*maillon)->modificateur) : '0';
	if ((*maillon)->conversion == 's' && modif != 'l')
		chaine = va_arg(ap, char*);
	else if ((*maillon)->conversion == 'c' || (*maillon)->conversion == 'C')
	{
		c = va_arg(ap, int);
		chaine = ft_strnew(1);
		chaine[0] = c;
	}
	(*maillon)->chaine = chaine; 
	return (ecrit_char(maillon));
}

