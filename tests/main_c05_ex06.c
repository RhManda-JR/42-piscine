#include <stdio.h>

void	check(char *what, long long got, long long expected)
{
	printf("%s  %-32s -> %lld (attendu %lld)\n",
		got == expected ? "OK" : "KO", what, got, expected);
}

int	ft_is_prime(int nb);

int	main(void)
{
	check("is_prime(-7)", ft_is_prime(-7), 0);
	check("is_prime(0)", ft_is_prime(0), 0);
	check("is_prime(1)", ft_is_prime(1), 0);
	check("is_prime(2)", ft_is_prime(2), 1);
	check("is_prime(4)", ft_is_prime(4), 0);
	check("is_prime(17)", ft_is_prime(17), 1);
	check("is_prime(25)", ft_is_prime(25), 0);
	check("is_prime(2147483647)", ft_is_prime(2147483647), 1);
	return (0);
}
