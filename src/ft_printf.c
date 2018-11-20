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
