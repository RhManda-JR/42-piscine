#include <unistd.h>
#include "ft.h"

void	ft_putchar(char c) { write(1, &c, 1); }
void	ft_swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
void	ft_putstr(char *str) { while (*str) ft_putchar(*str++); }
int		ft_strlen(char *str) { int i = 0; while (str[i]) i++; return (i); }
int		ft_strcmp(char *s1, char *s2) { while (*s1 && *s1 == *s2) { s1++; s2++; } return (*s1 - *s2); }

int	main(void)
{
	ft_putstr("ft.h compile et les 5 prototypes sont corrects\n");
	return (0);
}
