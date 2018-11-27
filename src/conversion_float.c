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

int	ft_double_exp(char *reals)
{
	int	i;

	i = 0;
	if (reals == NULL)
		return (0);
	while (reals[i] && reals[i] != '1')
		i++;
	return (ft_strlen(reals) - i - 1);
}

char	*ft_del_dot(char *str)
{
	char	*cpy;
	int	i;
	int	j;
	
	if (!(cpy = ft_strnew(27)))
		return (NULL);
	i = 0;
	j = 0;
	while (j < 27)
	{
		if (str[i] == '.')
			i++;
		cpy[j++] = str[i++];
	}
	return (cpy);
}

char	*ft_double_mantissa(double n, int *exp)
{
	char	*reals;
	char	*decimals;
	char	*mantissa;

	if (!(reals = ft_itoa_base(ABS((int)n), 2)))
		return (NULL);
	*exp = ft_double_exp(reals);
	if (!(mantissa = ft_strcat(reals, ".")))
		return (NULL);
	if (!(decimals = ft_double_decimals(ABS(n) - (double)ABS((int)n), 30 - ft_strlen(reals))))
		return (NULL);
	if (!(mantissa = ft_strcat(mantissa, decimals)))
		return (NULL);
	if (!(mantissa = ft_del_dot(ft_truncate(mantissa, 2, '<'))))
		return (NULL);
	return (mantissa);
}


char	*ft_doutoa(double n)
{
	char	*bits;	
	char	*mantissa;
	int	exp;
	char	*c_exp;
	
	if (!(bits = ft_strnew(32)))
		return (NULL);
	if (!(mantissa = ft_double_mantissa(n, &exp)))
		return (NULL);
	if (!(c_exp = ft_itoa_base(exp + 127, 2)))
		return (NULL);
	bits[0] = (n < 0) ? '1' : '0';
	if (!(bits = ft_strcat(bits, c_exp)))
		return (NULL);
	if (!(bits = ft_strcat(bits, mantissa)))
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
