/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:47:21 by login             #+#    #+#             */
/*   Updated: 2026/11/23 22:47:21 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_len(strs[i]);
		i++;
	}
	return (total + (size - 1) * ft_len(sep));
}

void	ft_append(char *dest, int *pos, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		pos;

	if (size <= 0)
	{
		res = malloc(sizeof(char));
		if (res)
			res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	if (!res)
		return (0);
	pos = 0;
	i = 0;
	while (i < size)
	{
		ft_append(res, &pos, strs[i]);
		if (i < size - 1)
			ft_append(res, &pos, sep);
		i++;
	}
	res[pos] = '\0';
	return (res);
}
