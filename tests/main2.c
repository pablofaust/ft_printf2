#include "../includes/ft_printf.h"
int			main()
{
	int real;
	int fake;

	printf("Real printf : \n");
	real = printf("%lli", (long long)0x11ff11ff11ff11ff);
	printf("\nFalse printf : \n");
	fake = ft_printf("%lli", (long long)0x11ff11ff11ff11ff);
	printf("\n");
	printf("real : %d fake : %d\n", real, fake);
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
