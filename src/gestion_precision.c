#include "ft_printf.h"

char		*ajout_zeros(char *nouvelle, char *chaine, int lon, int precision)
{
	int		diff;
	int		i;
	int		signe;
	int		j;

	signe = (chaine[0] == '-' || chaine[0] == '+' || chaine[0] == ' ') ? 1 : 0;
	diff = precision - lon + signe;
	i = (chaine[0] == '-' || chaine[0] == '+' || chaine[0] == ' ') ? 1 : 0;
	j = (chaine[0] == '-' || chaine[0] == '+' || chaine[0] == ' ') ? 1 : 0;
	while (i < diff + signe)
		nouvelle[i++] = '0';
	while (i <= precision)
		nouvelle[i++] = chaine[j++];
	return (nouvelle);
}

char		*precision_int(t_maillon **maillon)
{
	char	*chaine;
	char	*nouvelle;
	int		lon;
	int		precision;
	int		signe;

	chaine = (*maillon)->chaine;
	lon = ft_strlen(chaine);
	signe = (chaine[0] == '-' || chaine[0] == '+' || chaine[0] == ' ') ? 1 : 0;
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 0;
	if (precision > lon - signe)
	{
		if (!(nouvelle = ft_strnew(precision + signe)))
			return (chaine);
		if (signe)
			nouvelle[0] = chaine[0];
		nouvelle = ajout_zeros(nouvelle, chaine, lon, precision);
		free(chaine);
		return (nouvelle);
	}
	else
		return (chaine);
}

char		*precision_char(t_maillon **maillon, int precision, int initial)
{
	char	*chaine;
	char	*nouvelle;
	int		i;

	chaine = (*maillon)->chaine;
	if (precision < initial) 
	{
		if (!(nouvelle = ft_strnew(precision)))
			return (chaine);
		i = -1;
		while (chaine[++i] && i < precision)
			nouvelle[i] = chaine[i];
		return (nouvelle);
	}
	else
		return (chaine);
}

char		*modif_precision(t_maillon **maillon, int precision, int initial)
{
	char	c;

	c = (*maillon)->conversion;
	if (c == 'd' || c == 'i')
		return (precision_int(maillon));
	else if (c == 's')
		return (precision_char(maillon, precision, initial));
	return ((*maillon)->chaine);
}
