#include <stdio.h>

void	check(char *what, long long got, long long expected)
{
	printf("%s  %-32s -> %lld (attendu %lld)\n",
		got == expected ? "OK" : "KO", what, got, expected);
}

int	ft_sqrt(int nb);

int	main(void)
{
	check("sqrt(-4)", ft_sqrt(-4), 0);
	check("sqrt(0)", ft_sqrt(0), 0);
	check("sqrt(1)", ft_sqrt(1), 1);
	check("sqrt(16)", ft_sqrt(16), 4);
	check("sqrt(15)", ft_sqrt(15), 0);
	check("sqrt(2147395600)", ft_sqrt(2147395600), 46340);
	check("sqrt(2147483647)", ft_sqrt(2147483647), 0);
	return (0);
}
