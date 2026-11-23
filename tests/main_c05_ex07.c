#include <stdio.h>

void	check(char *what, long long got, long long expected)
{
	printf("%s  %-32s -> %lld (attendu %lld)\n",
		got == expected ? "OK" : "KO", what, got, expected);
}

int	ft_find_next_prime(int nb);

int	main(void)
{
	check("next_prime(-5)", ft_find_next_prime(-5), 2);
	check("next_prime(0)", ft_find_next_prime(0), 2);
	check("next_prime(2)", ft_find_next_prime(2), 2);
	check("next_prime(4)", ft_find_next_prime(4), 5);
	check("next_prime(14)", ft_find_next_prime(14), 17);
	check("next_prime(2147483646)", ft_find_next_prime(2147483646), 2147483647);
	return (0);
}
