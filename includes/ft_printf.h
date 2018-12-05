#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libs/libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>


typedef struct			s_elem t_elem;
typedef struct			s_elem
{
	int					plain;
	int					hash;
	int					zero;
	int					minus;
	int					plus;
	int					space;
	int					isnull;
	char				*width;
	char				*prec;
	char				*modif;
	char				conv;
	int					(*function)(va_list ap, t_elem **elem);
	char				*str;
	int					neg;
	int					len;
	t_elem				*next;
}						t_elem;


int				list_count(t_elem **elems);
int				ft_printf(const char *format, ...);
int				parsing(const char *format, t_elem **elem);
int				plain_parsing(const char *format, int *i, t_elem **elem);
int				flags(const char *format, int **i, t_elem **elem);
int				precision(const char *format, int **i, t_elem **elem);
int				width(const char *format, int **i, t_elem **elem);
int				length(const char *format, int **i, t_elem **elem);
int				conversion(const char *format, int **i, t_elem **elem);
int				is_flag(char a);
int				is_modif(char a);
int				is_conv(char a);
t_elem			*new_elem(void);
void			add_elem(t_elem **elem, t_elem *elems);
int				handling(va_list ap, t_elem **elem);
int				conv_char(va_list ap, t_elem **elem);
int				write_char(t_elem **elem);
int				conv_int(va_list ap, t_elem **elem);
int				write_int(t_elem **elem);
int				conv_uint(va_list ap, t_elem **elem);
int				conv_float(va_list ap, t_elem **elem);
int				write_int(t_elem **elem);
char			trans_modif(char *modif);
char			*modif_plus(t_elem **elem, char c);
char			*modif_hash(t_elem **elem, char c, int init);
char			*modif_prec(t_elem **elem, int prec, int init);
char			*handle_width(t_elem **elem, int width, int init);
char			*doutoa(double n);
char			*double_reals(double n, int *exp);
char			*double_decimals(double n, int len);
#endif
