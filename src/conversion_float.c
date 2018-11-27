#include "ft_printf.h"

int		float_lon(int precision)
{
	if (precision == 0)
		return (6);
	else
		return (precision);
}

char	*ft_double_decimals(double n, int len)
{
	char	*decimals;
	int		i;

	if (!(decimals = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		n = n * 2;
		decimals[i++] = (n >= 1) ? '1' : '0';
		n = n - (int)n;
	}
	return (decimals);
}

char	*ft_double_mantissa(double n)
{
	char	*reals;
	char	*decimals;
	char	*mantissa;

	if (!(reals = ft_itoa_base(ABS((int)n), 2)))
		return (NULL);
	if (!(mantissa = ft_strcat(reals, ".")))
		return (NULL);
	if (!(decimals = ft_double_decimals(ABS(n) - (double)ABS((int)n), 28 - ft_strlen(reals))))
		return (NULL);
	if (!(mantissa = ft_strcat(mantissa, decimals)))
		return (NULL);
	printf("mantissa = %s\n", mantissa);
	return (reals);
}

char	*ft_doutoa(double n)
{
	char	*bits;	
	char	*mantissa;
	
	if (!(bits = ft_strnew(32)))
		return (NULL);
	if (!(mantissa = ft_double_mantissa(n)))
		return (NULL);
	return (bits);
}

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ? trans_modif((*maillon)->modificateur) : '0';
	arg = va_arg(ap, double);
	ft_doutoa(arg);
	return (1);
}
