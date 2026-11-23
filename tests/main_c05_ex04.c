#include <stdio.h>

void	check(char *what, long long got, long long expected)
{
	printf("%s  %-32s -> %lld (attendu %lld)\n",
		got == expected ? "OK" : "KO", what, got, expected);
}

int	ft_fibonacci(int index);

int	main(void)
{
	check("fib(-1)", ft_fibonacci(-1), -1);
	check("fib(0)", ft_fibonacci(0), 0);
	check("fib(1)", ft_fibonacci(1), 1);
	check("fib(2)", ft_fibonacci(2), 1);
	check("fib(10)", ft_fibonacci(10), 55);
	check("fib(20)", ft_fibonacci(20), 6765);
	return (0);
}
