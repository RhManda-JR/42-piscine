#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

void	test(char *str, char *charset)
{
	char	**t;
	int		i;

	t = ft_split(str, charset);
	printf("split(\"%s\", \"%s\") -> [", str, charset);
	i = 0;
	while (t && t[i])
	{
		printf("\"%s\"%s", t[i], t[i + 1] ? ", " : "");
		free(t[i]);
		i++;
	}
	printf("]\n");
	free(t);
}

int	main(void)
{
	test("  Hello   World  42 ", " ");
	test("a,b;;c,", ",;");
	test("", " ");
	test(",,,,", ",");
	test("abc", "");
	test("abc", "xyz");
	return (0);
}
