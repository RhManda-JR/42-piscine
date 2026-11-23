#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

void	test(char *s)
{
	printf("%s  \"%s\" -> %d\n",
		ft_strlen(s) == (int)strlen(s) ? "OK" : "KO", s, ft_strlen(s));
}

int	main(void)
{
	test("Hello World");
	test("");
	test("a");
	test("42\tecole\n");
	return (0);
}
