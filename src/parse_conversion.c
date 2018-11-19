#include "ft_printf.h"

int					attributs(char const *format, int **i, t_maillon **maillon)
{
	if (format[**i - 1] != '%')
		return (0);
	while (est_attribut(format[**i]))
	{
		if (format[**i] == '#')
			(*maillon)->att_hash = 1;
		if (format[**i] == '0')
			(*maillon)->att_zero = 1;
		if (format[**i] == '-')
			(*maillon)->att_moins = 1;
		if (format[**i] == '+')
			(*maillon)->att_plus = 1;
		if (format[**i] == ' ')
			(*maillon)->att_espace = 1;
		(**i)++;
	}
	return (1);
}

int					largeur(const char *format, int **i, t_maillon **maillon)
{
	int		j;
	int		nb;
	int		k;

	j = **i;
	nb = 0;
	if ((*maillon)->largeur != NULL ||(*maillon)->precision != NULL \
			|| (*maillon)->modificateur != NULL || (*maillon)->conversion != '0')
		return (0);
	while (ft_isdigit(format[j]))
	{
		nb++;
		j++;
	}
	if (!((*maillon)->largeur = malloc(sizeof(char) * nb + 1)))
		return (0);
	k = 0;
	while (ft_isdigit(format[**i]))
	{
		(*maillon)->largeur[k] = format[**i];
		(**i)++;
		k++;
	}
	(*maillon)->largeur[k] = '\0';
	return (1);
}

int				precision(const char *format, int **i, t_maillon **maillon)
{
	int		nb;
	int		j;
	int		k;

	if ((*maillon)->precision != NULL || (*maillon)->modificateur != NULL || (*maillon)->conversion != '0')
		return (0);
	(**i)++;
	nb = 0;
	j = **i;
	while (ft_isdigit(format[j]))
	{
		nb++;
		j++;
	}
	if (!((*maillon)->precision = malloc(sizeof(char) * nb + 1)))
		return (0);
	k = 0;
	while (ft_isdigit(format[**i]))
	{
		(*maillon)->precision[k] = format[**i];
		(**i)++;
		k++;
	}
	(*maillon)->precision[k] = '\0';
	return (1);
}

int				modificateur(const char *format, int **i, t_maillon **maillon)
{
	int		j;
	int		nb;
	int		k;

	if ((*maillon)->modificateur != NULL || (*maillon)->conversion != '0')
		return (0);
	j = **i;
	nb = 0;
	while (est_modificateur(format[j]))
	{
		nb++;
		j++;
	}
	if (nb > 2)
		return (0);
	if (!((*maillon)->modificateur = malloc(sizeof(char) * nb + 1)))
		return (0);
	k = 0;
	while (est_modificateur(format[**i]))
	{
		(*maillon)->modificateur[k] = format[**i];
		(**i)++;
		k++;
	}
	(*maillon)->modificateur[k] = '\0';
	return (1);
}

int				conversion(const char *format, int **i, t_maillon **maillon)
{
	char	c;

	if ((*maillon)->conversion != '0')
		return (0);
	c = format[**i];
	(*maillon)->conversion = c;
	if (c == 's' || c == 'c' || c == 'C')
		(*maillon)->fonction = conversion_char;
	else if (c == 'd' || c == 'D' || c == 'i' || c == 'p')
		(*maillon)->fonction = conversion_int;
	else if (c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'u' || c == 'U')
		(*maillon)->fonction = conversion_uint;
	else if (c == 'S')
		(*maillon)->fonction = conversion_char;
	return (1);
}
