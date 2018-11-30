#include "ft_printf.h"

char	*ft_complete_exp(char *str)
{
	int		len;
	char	*exp;
	int		i;

	len = ft_strlen(str);
	if (len == 8)
		return (str);
	if (!(exp = ft_strnew(8)))
		return (NULL);
	i = 0;
	while (i < 8 - len)
		exp[i++] = '0';
	if (!(ft_strcat(exp, str)))
		return (NULL);
	return (exp);
}

char	*ft_fill_bits(double n, char *exp, char *reals, char* decimals)
{
	char	*bits;

	if (!(bits = ft_strnew(32)))
		return (NULL);
	bits[0] = (n > 0) ? '0' : '1';
	if (!(ft_strcat(bits, exp)))
		return (NULL);
	if (!(ft_strcat(bits, reals)))
		return (NULL);
	if (!(ft_strcat(bits, decimals)))
		return (NULL);
	return (bits);
}

char	*ft_doutoa(double n)
{
	char	*reals;
	int		exp_int;
	char	*exp_char;
	char	*decimals;
	char	*bits;
	
	exp_int = 1;
	if (!(reals = ft_double_reals(n, &exp_int)))
		return (NULL);
	if (!(exp_char = ft_complete_exp(ft_itoa_base(exp_int + 127, 2))))
		return (NULL);
	if (!(decimals = ft_double_decimals(ABS(n) - (double)ABS((int)n), 23 - exp_int)))
		return (NULL);
	if (exp_int < 0)
	{
		if (!(decimals = ft_truncate(decimals, ABS(exp_int), '<')))
			return (NULL);
	}
	if (!(bits = ft_fill_bits(n, exp_char, reals, decimals)))
		return (NULL);
	return (bits);
}

int		conversion_float(va_list ap, t_maillon **maillon)
{
	char	*chaine;
	char	modif;
	double	arg;
	char	*doutoa;

	chaine = NULL;
	modif = ((*maillon)->modificateur) ? trans_modif((*maillon)->modificateur) : '0';
	arg = va_arg(ap, double);
	if (!(doutoa = ft_doutoa(arg)))
		return (0);
	(*maillon)->chaine = doutoa;
	return (1);
}
