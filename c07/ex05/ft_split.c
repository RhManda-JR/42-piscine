/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:47:21 by login             #+#    #+#             */
/*   Updated: 2026/11/23 22:47:21 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], charset)
			&& (i == 0 || ft_is_sep(str[i - 1], charset)))
			count++;
		i++;
	}
	return (count);
}

char	*ft_word_dup(char *str, char *charset)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && !ft_is_sep(str[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_free_all(char **tab, int n)
{
	while (n > 0)
	{
		n--;
		free(tab[n]);
	}
	free(tab);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		w;

	tab = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!tab)
		return (0);
	i = 0;
	w = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], charset))
			i++;
		else
		{
			tab[w] = ft_word_dup(&str[i], charset);
			if (!tab[w])
				return (ft_free_all(tab, w));
			w++;
			while (str[i] && !ft_is_sep(str[i], charset))
				i++;
		}
	}
	tab[w] = 0;
	return (tab);
}
