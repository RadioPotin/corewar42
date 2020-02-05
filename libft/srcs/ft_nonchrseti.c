/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonchrseti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:33:12 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/19 14:14:37 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nonchrseti(const char *str, const char *chrset)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (chrset[j])
		{
			if (str[i] == chrset[j])
				break ;
			j++;
		}
		if (j == ft_strlen(chrset))
			return (i + 1);
		i++;
	}
	return (0);
}
