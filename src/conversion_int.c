#include "ft_printf.h"


int			connaitre_base(char	c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'b')
		return (2);
	return (10);
}

char		*hexa (long long arg, t_maillon **maillon)
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

int			ecrit_int(t_maillon **maillon)
{
	int		largeur;
	int		initial;
	int		precision;

	largeur = ((*maillon)->largeur) ? ft_atoi((*maillon)->largeur) : 0;
	initial = ft_strlen((*maillon)->chaine);
	if ((*maillon)->chaine[0] == '-')
		(*maillon)->neg = 1;
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 0;
	if ((*maillon)->att_hash)
		((*maillon)->chaine = modif_hash(maillon, (*maillon)->conversion));
	if ((*maillon)->att_plus)
		(*maillon)->chaine = modif_plus(maillon, '+');	
	if (!(*maillon)->att_plus && (*maillon)->att_espace)
		(*maillon)->chaine = modif_plus(maillon, ' ');	
	if ((*maillon)->precision != NULL)
		(*maillon)->chaine = modif_precision(maillon, precision, initial);
	if (largeur && largeur > initial)
		(*maillon)->chaine = gestion_largeur(maillon, largeur, initial);
	return (1);
}

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

int			conversion_uint(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	int		base;

	chaine = NULL;
	base = connaitre_base((*maillon)->conversion);
	if ((*maillon)->conversion == 'X')
		chaine = ft_itoa_base_uint(va_arg(ap, unsigned int), base, 'A');
	else
		chaine = ft_itoa_base_uint(va_arg(ap, unsigned int), base, 'a');
	(*maillon)->chaine = chaine;
	return (ecrit_int(maillon));
}

int			conversion_int(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;

	chaine = NULL;
	modif = ((*maillon)->modificateur ) ? trans_modif((*maillon)->modificateur) : '0';
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
