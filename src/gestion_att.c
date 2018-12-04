#include "ft_printf.h"

char		*ajout_zero_o(t_maillon **maillon, char *chaine, int initial)
{
	int		lon;
	char	*nouvelle;
	int		precision;
	
	precision = ft_atoi((*maillon)->precision);
	lon = (chaine) ? ft_strlen(chaine) : 0;
	if ((*maillon)->est_nul)
	{
		if (ft_atoi((*maillon)->largeur) > 1)
			(*maillon)->largeur = ft_itoa(ft_atoi((*maillon)->largeur) + 1);
		if ((*maillon)->precision == NULL || ft_atoi((*maillon)->precision) == 1)
			return (chaine);
	}
	if (precision > initial)
		return (chaine);
	if (!(nouvelle = ft_strnew(lon + 1)))
		return (chaine);
	nouvelle[0] = '0';
	if (!chaine)
		return (nouvelle);
	nouvelle = ft_strncat(nouvelle, chaine, lon);
	free(chaine);
	return (nouvelle);
}

char		*ajout_0x_x(t_maillon **maillon)
{
	char	*chaine;
	char	c;
	int		lon;
	char	*nouvelle;

	c = (*maillon)->conversion;
	chaine = (*maillon)->chaine;
	if ((*maillon)->est_nul)
		return (chaine);
	lon = ft_strlen(chaine);
	if (lon == 1 && chaine[0] == '0')
		return (chaine);
	if (!(nouvelle = ft_strnew(lon + 2)))
		return (chaine);
	nouvelle[0] = '0';
	nouvelle[1] = (c == 'x') ? 'x' : 'X';
	nouvelle = ft_strncat(nouvelle, chaine, lon);
	free(chaine);
	return (nouvelle);
}

char		*modif_hash(t_maillon **maillon, char c, int initial)
{
	if (c == 'o' || c == 'O')
		return (ajout_zero_o(maillon, (*maillon)->chaine, initial));
	else if (c == 'x' || c == 'X')
		return (ajout_0x_x(maillon));
	return ((*maillon)->chaine);
}

char		*modif_plus(t_maillon **maillon, char c)
{
	char	*chaine;
	char	*nouvelle;
	int		lon;
	char	conversion;

	chaine = (*maillon)->chaine;
	lon = ft_strlen(chaine);
	conversion = (*maillon)->conversion;
	if (conversion == 'd' || conversion == 'i' || conversion == 'f')
	{
		if (chaine[0] != '-')
		{
			if (!(nouvelle = ft_strnew(lon + 1)))
				return (chaine);
			nouvelle[0] = c;
			nouvelle = ft_strncat(nouvelle, chaine, lon);
			free(chaine);
			return (nouvelle);
		}
	}
	return (chaine);
}
