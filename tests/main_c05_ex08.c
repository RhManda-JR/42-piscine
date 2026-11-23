#include <stdio.h>

int	ft_ten_queens_puzzle(void);

int	main(void)
{
	int	n;

	n = ft_ten_queens_puzzle();
	fprintf(stderr, "%s  valeur de retour = %d (attendu 724)\n",
		n == 724 ? "OK" : "KO", n);
	return (0);
}
