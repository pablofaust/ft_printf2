#include "../includes/ft_printf.h"
int			main()
{
	int real;
	int fake;

//	dprintf(1, "Real printf : \n");
	real = printf("%-7d", 7799);
//	dprintf(1, "\n");
	fake = ft_printf("%-7d", 7789);
//	dprintf(1, "\n");
//	dprintf(1, "real : %d fake : %d\n", real, fake);
	if (real == fake) 
	{
		printf("Both are the same");
	}
	else 
	{
		printf("Not the same");
	}
	return (0);
}
