/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:47:21 by login             #+#    #+#             */
/*   Updated: 2026/11/23 22:47:21 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_space(char c);
int		ft_base_len(char *base);
char	*ft_itoa_base(long long n, char *base, int len);

int	ft_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_atoi_base(char *str, char *base, int len)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	result = 0;
	while (ft_index_in_base(str[i], base) != -1)
	{
		result = result * len + ft_index_in_base(str[i], base);
		i++;
	}
	return ((int)(result * sign));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	len_from;
	int	len_to;

	len_from = ft_base_len(base_from);
	len_to = ft_base_len(base_to);
	if (len_from == 0 || len_to == 0)
		return (0);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from, len_from),
			base_to, len_to));
}
