#include "ft_printf.h"

int			traitement(va_list ap, t_maillon **maillons)
{
	t_maillon	*pointeur;

	pointeur = *maillons;
	if (pointeur)
	{
		while (pointeur)
		{
			if (pointeur->fonction)
			{
				if (!(pointeur->fonction(ap, &pointeur)))
					return (0);
			}
			pointeur = pointeur->suivant;
		}
		return (1);
	}
	else
		return (1);
}

