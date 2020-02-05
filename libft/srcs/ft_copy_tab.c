/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:45:44 by dapinto           #+#    #+#             */
/*   Updated: 2019/11/06 15:02:42 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	**ft_copy_tab(char **tab)
{
	char	**ret;
	int		size;
	int		i;

	i = 0;
	ret = NULL;
	if (tab)
	{
		size = ft_tab_size(tab);
		if (!(ret = malloc(sizeof(char *) * (size + 1))))
			return (NULL);
		ret[size] = NULL;
		while (i < size)
		{
			if (!(ret[i] = ft_strdup(tab[i])))
			{
				ft_tabdel(i, &ret);
				return (NULL);
			}
			i++;
		}
	}
	return (ret);
}
