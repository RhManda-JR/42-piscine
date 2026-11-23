#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	test(int n, char *base, char *expected)
{
	printf("%-11d base \"%s\" attendu \"%s\" obtenu \"", n, base, expected);
	fflush(stdout);
	ft_putnbr_base(n, base);
	write(1, "\"\n", 2);
}

int	main(void)
{
	test(42, "0123456789", "42");
	test(42, "01", "101010");
	test(255, "0123456789ABCDEF", "FF");
	test(-255, "0123456789abcdef", "-ff");
	test(42, "poneyvif", "vn");
	test(0, "01", "0");
	test(-2147483648, "0123456789", "-2147483648");
	test(-2147483648, "01", "-10000000000000000000000000000000");
	test(2147483647, "0123456789ABCDEF", "7FFFFFFF");
	test(42, "", "");
	test(42, "0", "");
	test(42, "0123456789+", "");
	test(42, "01-", "");
	test(42, "0120", "");
	return (0);
}
