/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:31:46 by login             #+#    #+#             */
/*   Updated: 2026/11/23 22:31:46 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alnum(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!new_word && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		new_word = !ft_is_alnum(str[i]);
		i++;
	}
	return (str);
}
