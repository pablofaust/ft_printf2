#include "ft_printf.h"

int			handling(va_list ap, t_elem **elems)
{
	t_elem	*ptr;

	ptr = *elems;
	if (ptr)
	{
		while (ptr)
		{
			if (ptr->function)
			{
				if (!(ptr->function(ap, &ptr)))
					return (0);
			}
			ptr = ptr->next;
		}
		return (1);
	}
	else
		return (1);
}

