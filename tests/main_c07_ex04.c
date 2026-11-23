#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

void	test(char *nbr, char *from, char *to, char *expected)
{
	char	*r;
	int		ok;

	r = ft_convert_base(nbr, from, to);
	if (expected == NULL)
		ok = (r == NULL);
	else
		ok = (r && strcmp(r, expected) == 0);
	printf("%s  \"%s\" [%s -> %s] -> %s\n", ok ? "OK" : "KO",
		nbr, from, to, r ? r : "NULL");
	free(r);
}

int	main(void)
{
	test("42", "0123456789", "01", "101010");
	test("-ff", "0123456789abcdef", "0123456789", "-255");
	test(" \t --+-2azz", "0123456789abcdef", "01", "-101010");
	test("0", "0123456789", "0123456789ABCDEF", "0");
	test("-0", "0123456789", "01", "0");
	test("-2147483648", "0123456789", "0123456789abcdef", "-80000000");
	test("2147483647", "0123456789", "0123456789ABCDEF", "7FFFFFFF");
	test("vn", "poneyvif", "0123456789", "42");
	test("42", "0123456789", "0", NULL);
	test("42", "0123456789", "01+", NULL);
	test("42", "01 2", "0123456789", NULL);
	test("42", "00", "0123456789", NULL);
	return (0);
}
