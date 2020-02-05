/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:28:25 by dapinto           #+#    #+#             */
/*   Updated: 2019/08/30 13:03:16 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdigit(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (!ft_isdigit(str[i]) && str[i] <= 32)
				break ;
			else if (!ft_isdigit(str[i]) && str[i] > 32)
				return (0);
			else if (ft_isdigit(str[i]))
				i++;
		}
	return (i);
}
