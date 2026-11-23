#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

void	test(char *str, char *to_find)
{
	char	*mine;
	char	*real;

	mine = ft_strstr(str, to_find);
	real = strstr(str, to_find);
	printf("%s  str=\"%s\" to_find=\"%s\" -> %s\n",
		mine == real ? "OK" : "KO", str, to_find, mine ? mine : "(null)");
}

int	main(void)
{
	test("Hello World", "World");
	test("Hello World", "o");
	test("Hello World", "");
	test("", "");
	test("", "a");
	test("Hello", "Hello World");
	test("aaab", "aab");
	test("abcabcd", "abcd");
	test("Hello World", "xyz");
	test("Hello World", "d");
	return (0);
}
