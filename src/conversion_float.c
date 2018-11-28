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

void	ft_neg_exp(double n, int *exp)
{
	char	*decimals;
	int		i;

	decimals = ft_double_decimals(n, 28);
	//ft_putstr("decimals = ");
	//ft_putbinstr(decimals);
	i = 0;
	while (decimals[i] && decimals[i] != '1')
		i++;
	*exp = -i;
}

char	*ft_double_reals(double n, int *exp)
{
	char	*reals;
	int		i;
	int		j;

	if (!(reals = ft_itoa_base(ABS((int)n), 2)))
		return (NULL);
	i = 0;
	j = 0;
	if (ft_strrchr(reals, '1'))
	{
		while (reals[i])
		{
			if (reals[i] == '1' && j == 0)
				j = i + 1;
			i++;
		}
		*exp = (i > j ) ? i - j : j;
		return (ft_dir_strncpy(reals, ABS(*exp), '>'));
	}
	else
	{
		ft_neg_exp(n, exp);
		return (ft_dir_strncpy(reals, ABS(*exp), '>'));
	}
}

char	*ft_fill_bits(double n, char *exp, char *reals, char* decimals)
{
	char	*bits;

	if (!(bits = ft_strnew(32)))
		return (NULL);
	bits[0] = (n > 0) ? '0' : '1';
	ft_putstr("signe = ");
	ft_putbinstr(bits);
	ft_putstr("exp = ");
	ft_putbinstr(exp);
	if (!(ft_strcat(bits, exp)))
		return (NULL);
	ft_putstr("bits = ");
	ft_putbinstr(bits);
	ft_putstr("reals = ");
	ft_putbinstr(reals);
	if (!(ft_strcat(bits, reals)))
		return (NULL);
	ft_putstr("bits = ");
	ft_putbinstr(bits);
	ft_putstr("decimals = ");
	ft_putbinstr(decimals);
	if (!(ft_strcat(bits, decimals)))
		return (NULL);
	//ft_putstr("bits = ");
	//ft_putbinstr(bits);
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
	printf("exp = %d\n", exp_int);
	if (!(exp_char = ft_itoa_base(exp_int + 126, 2)))
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
	ft_putstr("bits = ");
	ft_putbinstr(bits);
	return (NULL);
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
	ft_putstr("result = ");
	ft_putbinstr(doutoa);
	return (1);
}
