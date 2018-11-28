

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

int	ft_double_exp(char *mantissa)
{
	int		i;
	int		j;
	int		k;
	
	i = 0;
	j = 0;
	while (mantissa[i] && mantissa[i] != '.')
	{
		if (mantissa[i] == '1' && j == 0)
			j = i + 1;
		i++;
	}
	if (j)
		return (i - j);
	i++;
	k = 0;
	while (mantissa[i] && mantissa[i] != '1')
	{
		i++;
		k++;
	}
	return (-k);
}

char	*ft_del_dot(char *str)
{
	char	*cpy;
	int	i;
	int	j;
	

	ft_putstr("str = ");
	ft_putbinstr(str);
	if (!(cpy = ft_strnew(27)))
		return (NULL);
	i = 0;
	j = 0;
	while (j <= 27)
	{
		if (str[i] == '.')
			i++;
		cpy[j++] = str[i++];
	}
	ft_putstr("apr del = ");
	ft_putbinstr(cpy);
	return (cpy);
}

char	*ft_double_mantissa(double n, int *exp)
{
	char	*reals;
	char	*decimals;
	char	*mantissa;

	if (!(reals = ft_itoa_base(ABS((int)n), 2)))
		return (NULL);
	ft_putstr("reals = ");
	ft_putbinstr(reals);
	if (!(mantissa = ft_strcat(reals, ".")))
		return (NULL);
	if (!(decimals = ft_double_decimals(ABS(n) - (double)ABS((int)n), 30 - ft_strlen(reals))))
		return (NULL);
	ft_putstr("decimals = ");
	ft_putbinstr(decimals);
	if (!(mantissa = ft_strcat(mantissa, decimals)))
		return (NULL);
	ft_putstr("mantissa = ");
	ft_putbinstr(mantissa);
	*exp = ft_double_exp(mantissa);
	if (!(mantissa = ft_del_dot(ft_truncate(mantissa, exp))))
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

