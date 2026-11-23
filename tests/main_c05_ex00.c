#include <stdio.h>

void	check(char *what, long long got, long long expected)
{
	printf("%s  %-32s -> %lld (attendu %lld)\n",
		got == expected ? "OK" : "KO", what, got, expected);
}

int	ft_iterative_factorial(int nb);

int	main(void)
{
	check("fact(-1)", ft_iterative_factorial(-1), 0);
	check("fact(0)", ft_iterative_factorial(0), 1);
	check("fact(1)", ft_iterative_factorial(1), 1);
	check("fact(5)", ft_iterative_factorial(5), 120);
	check("fact(12)", ft_iterative_factorial(12), 479001600);
	return (0);
}
