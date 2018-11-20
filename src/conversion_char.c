#include "ft_printf.h"

char	*ecrit_null()
{
	char	*null;

	if (!(null = ft_strnew(6)))
		return (NULL);
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
	return (null);
}

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
	char	*arg;

	chaine = NULL;
	modif = ((*maillon)->modificateur ) ? trans_modif((*maillon)->modificateur) : '0';
	arg = va_arg(ap, char*);
	if ((*maillon)->conversion == 's' && modif != 'l')
	{
		if (arg == NULL)
		{
			if (!(chaine = ecrit_null()))
				return (0);
		}
		else
			chaine = arg;
	}
	else if ((*maillon)->conversion == 'c' || (*maillon)->conversion == 'C')
	{
		c = va_arg(ap, int);
		chaine = ft_strnew(1);
		chaine[0] = c;
	}
	(*maillon)->chaine = chaine;
	return (ecrit_char(maillon));
}

