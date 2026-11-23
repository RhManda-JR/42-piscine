#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

void	test(int min, int max)
{
	int	*t;
	int	n;
	int	i;

	t = (int *)1;
	n = ft_ultimate_range(&t, min, max);
	printf("ultimate_range(%d, %d) -> retour %d, tab ", min, max, n);
	if (!t)
		printf("NULL");
	i = 0;
	while (t && i < n)
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
