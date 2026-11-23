/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:47:21 by login             #+#    #+#             */
/*   Updated: 2026/11/23 22:47:21 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_safe(int *pos, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (pos[i] == row || pos[i] - row == col - i
			|| row - pos[i] == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_solution(int *pos)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = pos[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_solve(int *pos, int col)
{
	int	row;
	int	count;

	if (col == 10)
	{
		ft_print_solution(pos);
		return (1);
	}
	count = 0;
	row = 0;
	while (row < 10)
	{
		if (ft_is_safe(pos, col, row))
		{
			pos[col] = row;
			count += ft_solve(pos, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];

	return (ft_solve(pos, 0));
}
