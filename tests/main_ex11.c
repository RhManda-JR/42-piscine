#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	ft_putstr_non_printable("Hello\nHow are you?");
	write(1, "\n", 1);
	ft_putstr_non_printable("tab\there \x7f \x01 \xff");
	write(1, "\n", 1);
	ft_putstr_non_printable("");
	write(1, "[vide OK]\n", 10);
	return (0);
}
