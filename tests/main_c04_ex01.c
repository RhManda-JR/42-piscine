#include <unistd.h>

void	ft_putstr(char *str);

int	main(void)
{
	ft_putstr("Hello World");
	write(1, "|\n", 2);
	ft_putstr("");
	write(1, "| (vide attendu)\n", 17);
	ft_putstr("ligne1\nligne2");
	write(1, "|\n", 2);
	return (0);
}
