#include <stdlib.h>
#include "ft_stock_str.h"

t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(struct s_stock_str *par);

int	main(void)
{
	char		*av[] = {"Hello", "", "42 Paris"};
	t_stock_str	*t;
	int			i;

	t = ft_strs_to_tab(3, av);
	ft_show_tab(t);
	i = 0;
	while (i < 3)
		free(t[i++].copy);
	free(t);
	return (0);
}
