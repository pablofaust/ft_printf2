#include "ft_printf.h"

char		*ajout_zero_o(char *chaine)
{
	int		lon;
	char	*nouvelle;

	lon = ft_strlen(chaine);
	if (lon == 1 && chaine[0] == '0')
		return (chaine);
	if (!(nouvelle = ft_strnew(lon + 1)))
		return (chaine);
	nouvelle[0] = '0';
	nouvelle = ft_strncat(nouvelle, chaine, lon);
	free(chaine);
	return (nouvelle);
}

char		*ajout_0x_x(char c, char *chaine)
{
	int		lon;
	char	*nouvelle;

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

char		*modif_hash(t_maillon **maillon, char c)
{
	if (c == 'o' || c == 'O')
		return (ajout_zero_o((*maillon)->chaine));
	else if (c == 'x' || c == 'X')
		return (ajout_0x_x((*maillon)->conversion, (*maillon)->chaine));
	return ((*maillon)->chaine);
}

char		*modif_plus(t_maillon **maillon, char c)
{
	char	*chaine;
	char	*nouvelle;
	int		lon;

	chaine = (*maillon)->chaine;
	lon = ft_strlen(chaine);
	if ((*maillon)->conversion == 'd' || (*maillon)->conversion == 'i')
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
