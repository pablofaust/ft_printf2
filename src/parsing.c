#include "ft_printf.h"

int				is_flag(char a)
{
	if (a == '#' || a == '0' || a == '-' || a == '+' || a ==' ')
		return (1);
	else
		return (0);
}

int				is_modif(char a)
{
	if (a == 'h' || a == 'l' || a == 'j' || a =='z' || a == 'L')
		return (1);
	else
		return (0);
}

int				is_conv(char a)
{
	if (a == 's' || a == 'S' || a == 'p' || a == 'd' || a == 'D' \
			|| a == 'i' || a == 'o' || a == 'O' || a == 'u' \
			|| a == 'U' || a == 'x' || a == 'X' || a == 'c' \
			|| a == 'C' || a == 'f')
		return (1);
	else
		return (0);
}

static int		conv_parsing(const char *format, int *i, t_elem *elem)
{
	(*i)++;
	while (format[*i])
	{
		if (is_flag(format[*i]))
		{
			if (!(flags(format, &i, elem)))
				return (0);
		}
		if (ft_isdigit(format[*i]))
		{
			if (!(width(format, &i, elem)))
				return (0);
		}
		if (format[*i] == '.')
		{
			if (!(precision(format, &i, elem)))
				return (0);
		}
		if (is_modif(format[*i]))
		{
			if (!(length(format, &i, elem)))
				return (0);
		}
		if (is_conv(format[*i]))
		{
			if (!(conversion(format, &i, elem)))
				return (0);
			return (1);
		}
		else
		{
			(*i)--;
			return (1);
		}
		(*i)++;
	}
	return (1);
}

static int		get_percent(const char *format, int *i)
{
	int		j;
	j = *i + 1;

	if (format[j] == '-')
		j++;
	while (format[j] && ft_isdigit(format[j]))
		j++;
	if (format[j] == '%')
		return (j - *i - 1);
	return (0);
}

static int		percent_parsing(const char *format, int *i, t_elem *elem)
{
	int		j;
	int		len;

	if ((format[*i + 1] && format[*i + 1] == '%') ||
	   		(format[*i + 1] && format[*i + 1] == ' ' && format[*i + 2] && format[*i + 2] == '%'))
	{
		elem->plain = 1;
		if (!(elem->str = ft_strnew(1)))
			return (0);
		elem->str[0] = '%';
		*i = (format[*i + 1] == '%') ? *i + 1 : *i + 2;
		return (1);
	}
	j = 0;
	if (format[*i + 1] && (len = get_percent(format, i)))
	{
		(*i)++;
		elem->plain = 1;
		if (!(elem->width = ft_strnew(len)))
			return (0);
		while (j < len)
			elem->width[j++] = format[(*i)++];
	}
	return (1);
}

int					parsing(const char *format, t_elem **elems)
{
	t_elem			*elem;
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(format);
	while (i < len)
	{
		if (!(elem = new_elem()))
			return (0);
		if (format[i] == '%')
			percent_parsing(format, &i, elem);
		if (format[i] == '%' && format[i + 1] && format[i + 1] != '%')
		{
			if (!(conv_parsing(format, &i, elem)))
				return (0);
		}
		else
		{
			if (!(plain_parsing(format, &i, elem)))
				return (0);
		}
		add_elem(elems, elem);
		i++;
	}
	return (1);
}
