#include "ft_printf.h"

char		*largeur_zeros(t_maillon **maillon, char *nouvelle, int largeur)
{
	char	*chaine;
	int		i;
	int		j;

	chaine = (*maillon)->chaine;
	if (chaine[0] == '+' || chaine[0] == '-' || chaine[0] == ' ')
		nouvelle[0] = chaine[0];
	i = (chaine[0] == '+' || chaine[0] == '-' || chaine[0] == ' ') ? 1 : 0;
	j = (chaine[0] == '+' || chaine[0] == '-' || chaine[0] == ' ') ? 1 : 0;
	while (i < largeur - ft_strlen(chaine) + j)
		nouvelle[i++] = '0';
	while (chaine[j])
		nouvelle[i++] = chaine[j++];
	return (nouvelle);
}

char		*largeur_av(t_maillon **maillon, char *nouvelle, int precision, int initial)
{
	int		i;
	int		j;
	int		add;
	char		c;

	c = (*maillon)->conversion;
	add = 0;
	if ((c == 'o' || c == 'O') && (*maillon)->att_hash)
		add = 1;
	else if ((c == 'd' || c == 'i') && ((*maillon)->att_plus || (*maillon)->att_espace) && (*maillon)->chaine[0] != '-')
		add = 1;
	else if ((c == 'x' || c == 'X') && (*maillon)->att_hash)
		add = 2;
	i = 0;
	if (precision > initial + (*maillon)->neg)
		precision = precision - initial + (*maillon)->neg;
	while (i < ft_atoi((*maillon)->largeur) - initial - add - precision)
		nouvelle[i++] = ' ';
	j = 0;
	while ((*maillon)->chaine[j])
		nouvelle[i++] = (*maillon)->chaine[j++]; 
	return (nouvelle);
}

char		*largeur_apr(t_maillon **maillon, char *nouvelle, int largeur)
{
	char	*chaine;
	int		i;

	chaine = (*maillon)->chaine;
	i = -1;
	while (chaine[++i]) 
		nouvelle[i] = chaine[i];
	while (i <= largeur)
		nouvelle[i++] = ' ';
	return (nouvelle);
}

char		*gestion_largeur(t_maillon **maillon, int largeur, int initial)
{
	char	*nouvelle;
	int	precision;

	precision = ((*maillon)->precision != NULL) ? ft_atoi((*maillon)->precision) : 0;
	if (!(nouvelle = ft_strnew(largeur)))
		return ((*maillon)->chaine);
	if ((*maillon)->att_moins)
		nouvelle = largeur_apr(maillon, nouvelle, largeur);
	else
	{
		if ((*maillon)->att_zero && (*maillon)->precision == NULL)
			nouvelle = largeur_zeros(maillon, nouvelle, largeur);
		else
			nouvelle = largeur_av(maillon, nouvelle, precision, initial);
	}
//	free((*maillon)->chaine);
	return (nouvelle);
}
