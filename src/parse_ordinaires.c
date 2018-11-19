#include "ft_printf.h"

static int			ajout_chaine(t_maillon **maillon, int j, char a)
{
	char		*nouvelle;
	int			i;

	i = 0;
	if ((*maillon)->chaine == NULL)
	{
		if (!((*maillon)->chaine = malloc(sizeof(char) * 2)))
			return (0);
		(*maillon)->chaine[i] = a;
		(*maillon)->chaine[i + 1] = '\0';
		return (1);
	}
	else
	{
		if (!(nouvelle = malloc(sizeof(char) * j + 1)))
			return (0);
		while (i <= j)
		{
			nouvelle[i] = (*maillon)->chaine[i];
			i++;
		}
		nouvelle[j] = a;
		nouvelle[j + 1] = '\0';
		(*maillon)->chaine = nouvelle;
		return (1);
	}
}

int				parse_ordinaires(const char *format, int *i, t_maillon **maillon)
{
	int			j;

	j = 0;
	while (format[*i])
	{
		if (format[*i] == '%')
		{
			if (format[*i - 1] && format[*i - 1] != '%' && format[*i + 1] && format[*i + 1] != '%')
			{
				(*i)--;
				return (1);
			}
		}
		if (!(ajout_chaine(maillon, j, format[*i])))
			return (0);
		j++;
		(*i)++;
	}
	return (1);
}
