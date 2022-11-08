/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:30:42 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/09/28 17:34:40 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			word_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word_count);
}

static int	ft_word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free_all(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;
	int		len;
	int		j;

	i = 0;
	j = -1;
	tab = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (++j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		len = ft_word_len(s, c, i);
		tab[j] = ft_substr(s, i, len);
		if (!tab[j])
		{
			ft_free_all(tab, j);
			return (NULL);
		}
		i += len;
	}
	tab[j] = 0;
	return (tab);
}
