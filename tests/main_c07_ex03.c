#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(int size, char **strs, char *sep);

void	test(int size, char **strs, char *sep, char *expected)
{
	char	*r;

	r = ft_strjoin(size, strs, sep);
	printf("%s  size=%d sep=\"%s\" -> \"%s\"\n",
		(r && strcmp(r, expected) == 0) ? "OK" : "KO", size, sep, r);
	free(r);
}

int	main(void)
{
	char	*s[] = {"Hello", "World", "42"};

	test(3, s, ", ", "Hello, World, 42");
	test(3, s, "", "HelloWorld42");
	test(1, s, ", ", "Hello");
	test(0, s, ", ", "");
	return (0);
}
