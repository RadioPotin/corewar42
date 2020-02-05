/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:05:07 by evogel            #+#    #+#             */
/*   Updated: 2019/11/06 15:02:34 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*count_lett(char const *s, char c)
{
	int		*lett;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(lett = (int*)ft_memalloc(sizeof(int) * ft_count_word(s, c))))
		return (NULL);
	while (s[i] && j < ft_count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			lett[j]++;
			i++;
		}
		j++;
	}
	return (lett);
}

static char	**fill_tab(char const *s, char c, char **tab)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] && tab[j])
	{
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		while (s[i] && s[i] != c)
			tab[j][k++] = s[i++];
		j++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		words;
	int		*lett;

	if (s == NULL || !(lett = count_lett(s, c)))
		return (NULL);
	words = ft_count_word(s, c);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		if (!(tab[i] = ft_strnew(lett[i])))
		{
			ft_tabdel(i - 1, &tab);
			ft_memdel((void**)&lett);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	ft_memdel((void**)&lett);
	return (fill_tab(s, c, tab));
}
