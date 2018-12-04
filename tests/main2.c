#include "../includes/ft_printf.h"
int			main()
{
	int real;
	int fake;
	long double ld;

	ld = -34059.94538;
	printf("Real printf : \n");
	real = printf("%#0012x", 0xe);
	printf("\n");
	printf("Fake printf : \n");
	fake = ft_printf("%#0012x", 0xe);
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
