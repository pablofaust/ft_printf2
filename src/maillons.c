#include "ft_printf.h"

int					nb_maillons(t_maillon **maillons)
{
	t_maillon		**pointeur;
	int				nb;

	if (maillons == NULL)
		return (0);
	pointeur = maillons;
	nb = 0;
	while (*pointeur)
	{
		*pointeur = (*pointeur)->suivant;
		nb++;
	}
	return (nb);
}

/*static void			free_maillons(t_maillon **maillons)
{
	t_maillon		*pointeur;

	pointeur = *maillons;
	while (*maillons)
	{
		*maillons = pointeur->suivant;
		free(pointeur);
		pointeur = *maillons;
	}
	*maillons = NULL;
}*/

t_maillon			*creer_maillon(void)
{
	t_maillon		*maillon;

	if (!(maillon = malloc(sizeof(t_maillon))))
		return (NULL);
	maillon->ordinaires = 0;
	maillon->att_hash = 0;
	maillon->att_zero = 0;
	maillon->att_moins = 0;
	maillon->att_plus = 0;
	maillon->att_espace = 0;
	maillon->largeur = NULL;
	maillon->precision = NULL;
	maillon->modificateur = NULL;
	maillon->conversion = '0';
	maillon->fonction = NULL;
	maillon->chaine = NULL;
	maillon->neg = 0;
	maillon->lon = 0;
	maillon->suivant = NULL;
	return (maillon);
}

void			ajouter_maillon(t_maillon **maillons, t_maillon *maillon)
{
	t_maillon		*pointeur;

	pointeur = *maillons;
	if (pointeur == NULL)
		*maillons = maillon;
	else
	{
		while (pointeur->suivant)
			pointeur = pointeur->suivant;
		pointeur->suivant = maillon;
	}
}
