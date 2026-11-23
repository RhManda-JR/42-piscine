/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:31:46 by login             #+#    #+#             */
/*   Updated: 2026/11/23 22:31:46 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr(unsigned long long addr)
{
	char	buf[16];
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buf[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, buf, 16);
	write(1, ": ", 2);
}

void	ft_print_hex_part(unsigned char *p, unsigned int len)
{
	char			*hex;
	unsigned int	i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			write(1, &hex[p[i] / 16], 1);
			write(1, &hex[p[i] % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_chars(unsigned char *p, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (p[i] >= 32 && p[i] <= 126)
			write(1, &p[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*p;
	unsigned int	i;
	unsigned int	len;

	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		len = size - i;
		if (len > 16)
			len = 16;
		ft_print_addr((unsigned long long)(p + i));
		ft_print_hex_part(p + i, len);
		ft_print_chars(p + i, len);
		i += 16;
	}
	return (addr);
}
