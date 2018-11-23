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
	printf("chaine = %s\n", chaine);
/*	entiers = (int)arg;
	decimales = arg - (double)entiers;
	neg = (arg < 0) ? 1 : 0;
	i = 0;
	tmp = ABS(entiers);
	lon = 0;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		lon++;
	}
	if (!(chaine = ft_strnew(lon + 1 + precision + neg)))
		return (0);
	if (neg)
		chaine[i++] = '-';
	if (entiers == 0)
		chaine[i++] = '0';
	pow = ft_pow(lon);
	tmp = ABS(entiers);
	while (tmp > 0)
	{
		chaine[i++] = (tmp/ pow) + 48;
		tmp = tmp % pow;
		pow = pow / 10;
	}
	pow = ft_pow(precision + 1);
	tmp = ABS((int)(decimales * pow));
	tmp2 = (int)(decimales * pow);
	chaine[i++] = '.';
	while (precision > 0)
	{
		printf("tmp = %d\n", tmp);
		pow = pow / 10;
		chaine[i++] = (tmp2) ? (tmp / pow) + 48 : '0';
		tmp = tmp % pow;
		precision--;
	}
	printf("chaine = %s\n", chaine);*/
	return (1);
}
