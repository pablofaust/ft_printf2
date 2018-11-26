#include "ft_printf.h"

int		float_lon(int precision)
{
	if (precision == 0)
		return (6);
	else
		return (precision);
}

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;
	int		nb_d;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ? trans_modif((*maillon)->modificateur) : '0';
	arg = va_arg(ap, double);
	nb_d = float_lon(ft_atoi((*maillon)->precision));
	if (!(chaine = ft_itoa_db(arg, nb_d)))
		return (0);
	(*maillon)->chaine = chaine;
	return (ecrit_int(maillon));
}
