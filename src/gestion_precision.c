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

char		*precision_int(t_maillon **maillon, int precision)
{
	char	*chaine;
	char	*nouvelle;
	int		lon;
	int		signe;

	chaine = (*maillon)->chaine;
	lon = ft_strlen(chaine);
	signe = (chaine[0] == '-' || chaine[0] == '+' || chaine[0] == ' ') ? 1 : 0;
	if (precision == 0 && (*maillon)->precision[0] == '.' && (*maillon)->chaine == NULL)
		return (NULL);
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

	if (precision == 0 && (*maillon)->precision[0] == '.')
		return (NULL);
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

char	*check_zero(t_maillon **maillon)
{
	char	*chaine;

	if ((*maillon)->att_plus)
	{
		if (!(chaine = ft_strnew(1)))
			return (NULL);
		chaine[0] = '+';
		return (chaine);
	}
	if (!(*maillon)->att_hash)
		return (NULL);
	return ((*maillon)->chaine);
}

char		*modif_precision(t_maillon **maillon, int precision, int initial)
{
	char	c;

	if ((*maillon)->est_nul && precision == 0)
		return (check_zero(maillon));
	c = (*maillon)->conversion;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (precision_int(maillon, precision));
	else if (c == 's')
		return (precision_char(maillon, precision, initial));
	return ((*maillon)->chaine);
}
