#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	m[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on "
		"peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	if (ft_print_memory(m, sizeof(m)) != m)
		write(1, "KO: mauvaise valeur de retour\n", 30);
	write(1, "--- size 0 ---\n", 15);
	ft_print_memory(m, 0);
	write(1, "--- size 5 ---\n", 15);
	ft_print_memory(m, 5);
	return (0);
}
