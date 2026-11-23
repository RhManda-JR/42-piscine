#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src);

void	test(char *s)
{
	char	*d;

	d = ft_strdup(s);
	printf("%s  \"%s\"\n", (d && d != s && strcmp(d, s) == 0) ? "OK" : "KO", s);
	free(d);
}

int	main(void)
{
	test("Hello World");
	test("");
	test("42");
	return (0);
}
