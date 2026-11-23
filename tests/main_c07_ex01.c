#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

void	test(int min, int max)
{
	int	*t;
	int	i;

	t = ft_range(min, max);
	printf("range(%d, %d) -> ", min, max);
	if (!t)
		printf("NULL");
	i = 0;
	while (t && i < max - min)
		printf("%d ", t[i++]);
	printf("\n");
	free(t);
}

int	main(void)
{
	test(0, 5);
	test(-3, 2);
	test(5, 5);
	test(5, 2);
	return (0);
}
