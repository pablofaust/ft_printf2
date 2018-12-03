#include "ft_printf.h"

char	*doubles_decimales(double n, int precision)
{
	char				*chaine;
	unsigned long long	pow;
	double				decimales;
	int					i;
	int					entiers;
	unsigned long long	tmp;

	if (!(chaine = ft_strnew(precision)))
		return (NULL);
	pow = ft_pow(precision + 1);
	entiers = ABS((int)n);
	decimales = ABS(n) - (double)entiers;
	tmp = (unsigned long long)(decimales * pow);
	printf("decimales = %f, tmp = %lld\n", decimales, tmp);
	i = 0;
	while (i < precision)
	{
		pow = pow / 10;
		printf("pow = %lld, decimales = %f\n", pow, decimales);
		chaine[i] = (decimales) ? (tmp / pow) + 48 : '0';
		tmp = tmp % pow;
		i++;
	}
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
