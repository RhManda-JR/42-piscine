#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb);

void	test(int n)
{
	printf("attendu %-12d obtenu ", n);
	fflush(stdout);
	ft_putnbr(n);
	write(1, "\n", 1);
}

int	main(void)
{
	test(0);
	test(42);
	test(-42);
	test(7);
	test(-7);
	test(1000000);
	test(2147483647);
	test(-2147483648);
	return (0);
}
