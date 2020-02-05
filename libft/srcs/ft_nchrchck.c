/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nchrchck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:35:05 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/18 16:24:39 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nchrchck(const char *str, char *chrset, int len)
{
	int				i;
	unsigned int	j;

	i = 0;
	if (len < 0)
		return (-1);
	while (i < len)
	{
		j = 0;
		while (chrset[j])
		{
			if (str[i] == chrset[j])
				break ;
			else
				j++;
		}
		if (!chrset[j] && str[i] != chrset[j])
			return (-1);
		i++;
	}
	return (i);
}
