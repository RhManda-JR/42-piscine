#include <stdio.h>

int	ft_atoi(char *str);

void	test(char *s, int expected)
{
	int	r;

	r = ft_atoi(s);
	printf("%s  \"%s\" -> %d (attendu %d)\n",
		r == expected ? "OK" : "KO", s, r, expected);
}

int	main(void)
{
	test(" ---+--+1234ab567", -1234);
	test("42", 42);
	test("-42", -42);
	test("+42", 42);
	test("--42", 42);
	test(" \t\n\v\f\r 42", 42);
	test("- 42", 0);
	test("abc", 0);
	test("", 0);
	test("0", 0);
	test("00042", 42);
	test("2147483647", 2147483647);
	test("-2147483648", -2147483648);
	return (0);
}
