/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichrset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:34:04 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/28 14:53:31 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strichrset(const char *temp, const char *charset)
{
	int i;
	int j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (charset[j])
		{
			if (temp[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
