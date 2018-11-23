#include "ft_printf.h"

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;
	int		entiers;
	double	decimales;
	int		precision;
	int		lon;
	int		tmp;
	int		pow;
	int		i;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ? trans_modif((*maillon)->modificateur) : '0';
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 6;
	arg = va_arg(ap, double);
	entiers = (int)arg;
	decimales = arg - (double)entiers;
	tmp = entiers;
	lon = 0;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		lon++;
	}
	if (!(chaine = ft_strnew(lon + precision)))
		return (0);
	pow = ft_pow(lon);
	i = 0;
	while (entiers > 0)
	{
		chaine[i++] = (entiers / pow) + 48;
		entiers = entiers % pow;
		pow = pow / 10;
	}
	if (decimales)
	{
		chaine[i++] = '.';
		pow = ft_pow(precision + 1);
		tmp = (int)(decimales * pow);
		printf("%tmp = %d\n", tmp);
	}
	printf("chaine = %s\n", chaine);
	return (1);
}
