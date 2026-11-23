/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:47:21 by login             #+#    #+#             */
/*   Updated: 2026/11/23 22:47:21 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_nb_len(long long n, int len)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		n /= len;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(long long n, char *base, int len)
{
	char	*res;
	int		size;

	size = ft_nb_len(n, len);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	res[size] = '\0';
	res[0] = base[0];
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		size--;
		res[size] = base[n % len];
		n /= len;
	}
	return (res);
}
