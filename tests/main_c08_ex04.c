#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_stock_str.h"

t_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(void)
{
	char		*av[] = {"Hello", "", "42 Paris"};
	t_stock_str	*t;
	int			i;
	int			ok;

	t = ft_strs_to_tab(3, av);
	ok = (t != NULL);
	i = 0;
	while (ok && i < 3)
	{
		ok = t[i].str == av[i] && t[i].size == (int)strlen(av[i])
			&& t[i].copy != av[i] && strcmp(t[i].copy, av[i]) == 0;
		i++;
	}
	ok = ok && t[3].str == NULL;
	printf("%s  3 chaines + element final str = 0\n", ok ? "OK" : "KO");
	i = 0;
	while (t && i < 3)
		free(t[i++].copy);
	free(t);
	return (0);
}
