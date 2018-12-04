#include "ft_printf.h"

char	*en_majuscules(char *chaine)
{
	char	*nouvelle;
	char	c;
	int		i;

	nouvelle = ft_strnew(ft_strlen(chaine));
	i = 0;
	while (chaine[i])
	{
		c = chaine[i];
		nouvelle[i] = (c >= 97 && c <= 122) ? c - 32 : c;
		i++;
	}
	free(chaine);
	return (nouvelle);
}

static int		largeur_pourcent(t_maillon *maillon)
{
	int		lon;
	int		i;

	free(maillon->chaine);
	lon = ft_atoi(maillon->largeur);
	if (!(maillon->chaine = ft_strnew(ABS(lon))))
		return (0);
	i = 0;
	if (lon < 0)
	{
		maillon->chaine[i++] = '%';
		while (i < ABS(lon))
			maillon->chaine[i++] = (maillon->largeur[0] == '0') ? '0' : ' ';
	}
	else
	{
		while (i < ABS(lon) - 1)
			maillon->chaine[i++] = (maillon->largeur[0] == '0') ? '0' : ' ';
		maillon->chaine[i] = '%';
	}
	return (1);
}

int		lecture(t_maillon **maillons)
{
	t_maillon	*pointeur;
	int		len;
	int		retour;

	len = 0;
	retour = 0;
	pointeur = *maillons;
	while (pointeur)
	{
		if (pointeur->chaine != NULL)
		{
			if (pointeur->ordinaires == 1 && pointeur->largeur != NULL)
			{
				if (!(largeur_pourcent(pointeur)))
					return (0);
			}
			len = ft_strlen(pointeur->chaine);
			if (pointeur->conversion == 'X')
				pointeur->chaine = en_majuscules(pointeur->chaine);
			write(1, pointeur->chaine, len);
			retour = retour + len;
		}
		else if (!pointeur->chaine && pointeur->conversion == 'c')
			retour = (pointeur->largeur) ? retour + ft_atoi(pointeur->largeur) : retour + 1;
		pointeur = pointeur->suivant;
	}
	return (retour);
}

int		ft_printf(const char *format, ...)
{
	t_maillon		*maillons;
	va_list			ap;
	int			retour;

	maillons = NULL;
	if (!(parsing(format, &maillons)))
		return (-1);
	va_start(ap, format);
	if (!(traitement(ap, &maillons)))
		return (-1);
	retour = lecture(&maillons);
	return (retour);
}
