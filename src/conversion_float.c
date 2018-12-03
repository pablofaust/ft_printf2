#include "ft_printf.h"

char	*doubles_decimales(double n, int precision)
{
	char				*chaine;
	unsigned long long	pow;
	long double			decimales;
	int					i;
	unsigned long long	tmp;
	unsigned long long	pow_max;

	pow_max = 1000000000000000000;
	if (!(chaine = ft_strnew(precision)))
		return (NULL);
	pow = ft_pow(precision + 1);
	decimales = ABS(n) - (double)ABS((int)n);
	tmp = (unsigned long long)(decimales * pow_max);
	printf("diff = %llu\n", pow_max / pow);
	i = 0;
	while (i < precision)
	{
		printf("pow = %llu, tmp = %.llu, tmp / pow = %llu\n", pow, tmp, tmp / pow);
		chaine[i] = (decimales) ? (tmp / pow) + 48 : '0';
		tmp = tmp % pow;
		pow = pow / 10;
		i++;
	}
	printf("tmp = %llu\n", tmp);
	if (tmp)
		printf("%llu\n", tmp / (pow_max / pow));
	return (chaine);
}

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;
	int		precision;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ? trans_modif((*maillon)->modificateur) : '0';
	arg = va_arg(ap, double);
	precision = ((*maillon)->precision) ? ft_atoi((*maillon)->precision) : 6;
	if (!(chaine = ft_itoa((int)arg)))
		return (0);
	if (!(chaine = ft_strcat(chaine, ".")))
		return (0);
	if (!(chaine = ft_strcat(chaine, doubles_decimales(arg, precision))))
		return (0);
	printf("chaine = %s\n", chaine);
	(*maillon)->chaine = chaine;
	return (1);
}
