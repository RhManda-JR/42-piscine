#include <stdio.h>

void	check(char *what, long long got, long long expected)
{
	printf("%s  %-32s -> %lld (attendu %lld)\n",
		got == expected ? "OK" : "KO", what, got, expected);
}

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	check("pow(2, 10)", ft_iterative_power(2, 10), 1024);
	check("pow(0, 0)", ft_iterative_power(0, 0), 1);
	check("pow(3, 0)", ft_iterative_power(3, 0), 1);
	check("pow(0, 5)", ft_iterative_power(0, 5), 0);
	check("pow(5, -1)", ft_iterative_power(5, -1), 0);
	check("pow(-2, 3)", ft_iterative_power(-2, 3), -8);
	check("pow(-2, 4)", ft_iterative_power(-2, 4), 16);
	return (0);
}
