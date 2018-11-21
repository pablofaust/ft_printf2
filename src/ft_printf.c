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
	if (!(maillon->chaine = ft_strnew(lon)))
		return (0);
	i = 0;
	while (i < lon - 1)
		maillon->chaine[i++] = ' ';
	maillon->chaine[i] = '%';
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
		pointeur = pointeur->suivant;
	}
	return (retour);
}

void	lire_maillons(t_maillon **maillons)
{
	t_maillon	**pointeur;
	int			i;

	i = 1;
	pointeur = maillons;
	while (*pointeur)
	{
		printf("--- MAILLON %d ---\n\n", i);
		printf("ordinaires = %d\n", (*pointeur)->ordinaires);
		printf("# = %d\n", (*pointeur)->att_hash);
		printf("0 = %d\n", (*pointeur)->att_zero);
		printf("- = %d\n", (*pointeur)->att_moins);
		printf("+ = %d\n", (*pointeur)->att_plus);
		printf("  = %d\n", (*pointeur)->att_espace);
		printf("largeur = %s\n", (*pointeur)->largeur);
		printf("precision = %s\n", (*pointeur)->precision);
		printf("modificateur = %s\n", (*pointeur)->modificateur);
		printf("conversion = %c\n", (*pointeur)->conversion); 
		printf("chaine = %s\n\n", (*pointeur)->chaine);
		*pointeur = (*pointeur)->suivant;
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_maillon		*maillons;
	va_list			ap;
	int			retour;

	maillons = NULL;
	if (!(parsing(format, &maillons)))
		return (-1);
	//lire_maillons(&maillons);
	va_start(ap, format);
	if (!(traitement(ap, &maillons)))
		return (-1);
	retour = lecture(&maillons);
	return (retour);
}
