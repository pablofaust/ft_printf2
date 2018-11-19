#include "ft_printf.h"
int			traitement(va_list ap, t_maillon **maillons)
{
	t_maillon	*pointeur;

	pointeur = *maillons;
	while (pointeur->suivant)
	{
		if (!(pointeur->fonction(ap, pointeur)))
			return (0);
		pointeur = pointeur->suivant;
	}
	return (1);
}

