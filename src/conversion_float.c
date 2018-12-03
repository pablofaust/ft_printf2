#include "ft_printf.h"

char	*doubles_decimales(double n)
{
	char	*chaine;
	int		pow;
	int		decimales;
	int		tmp;
	int		i;

	if (!(chaine = ft_strnew(6)))
		return (NULL);
	pow = ft_pow(7);
	decimales = (int)((ABS(n) - (double)ABS((int)n)) * pow);
	tmp = decimales;
	i = 0;
	while (i < 6)
	{
		pow = pow / 10;
		chaine[i] = (tmp) ? (decimales / pow) + 48 : '0';
		decimales = decimales % pow;
		i++;
	}
	return (chaine);
}

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ? trans_modif((*maillon)->modificateur) : '0';
	arg = va_arg(ap, double);
	if (!(chaine = ft_itoa((int)arg)))
		return (0);
	if (!(chaine = ft_strcat(chaine, ".")))
		return (0);
	if (!(chaine = ft_strcat(chaine, doubles_decimales(arg))))
		return (0);
	printf("chaine = %s\n", chaine);
	(*maillon)->chaine = chaine;
	return (1);
}
