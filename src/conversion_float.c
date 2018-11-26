#include "ft_printf.h"

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;
	int		precision;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ? trans_modif((*maillon)->modificateur) : '0';
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 6;
	arg = va_arg(ap, double);
	if (!(chaine = ft_itoa_db(arg, precision)))
		return (0);
	(*maillon)->chaine = chaine;
	return (ecrit_int(maillon));
}
