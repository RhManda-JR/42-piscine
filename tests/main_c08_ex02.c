#include <stdio.h>
#include "ft_abs.h"

int	main(void)
{
	int	x;

	x = -7;
	printf("%s  ABS(-5) = %d\n", ABS(-5) == 5 ? "OK" : "KO", ABS(-5));
	printf("%s  ABS(3) = %d\n", ABS(3) == 3 ? "OK" : "KO", ABS(3));
	printf("%s  ABS(0) = %d\n", ABS(0) == 0 ? "OK" : "KO", ABS(0));
	printf("%s  ABS(x + 2) avec x=-7 = %d\n", ABS(x + 2) == 5 ? "OK" : "KO", ABS(x + 2));
	printf("%s  10 - ABS(-3) = %d\n", 10 - ABS(-3) == 7 ? "OK" : "KO", 10 - ABS(-3));
	return (0);
}
