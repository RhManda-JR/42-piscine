#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

void	test(char *s, char *base, int expected)
{
	int	r;

	r = ft_atoi_base(s, base);
	printf("%s  \"%s\" base \"%s\" -> %d (attendu %d)\n",
		r == expected ? "OK" : "KO", s, base, r, expected);
}

int	main(void)
{
	test("42", "0123456789", 42);
	test("101010", "01", 42);
	test("ff", "0123456789abcdef", 255);
	test("FF", "0123456789abcdef", 0);
	test(" \t -+-FF", "0123456789ABCDEF", 255);
	test(" --+-7FFFFFFFz", "0123456789ABCDEF", -2147483647);
	test("-80000000", "0123456789ABCDEF", -2147483648);
	test("vn", "poneyvif", 42);
	test("12a34", "0123456789", 12);
	test("42", "", 0);
	test("42", "0", 0);
	test("42", "0123456789+", 0);
	test("42", "01-", 0);
	test("42", "0120", 0);
	test("42", "01 ", 0);
	test("42", "01\t", 0);
	return (0);
}
