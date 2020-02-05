/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nb_of_target.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:58:33 by dapinto           #+#    #+#             */
/*   Updated: 2019/11/06 11:01:12 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_nb_of_target(char *str, char const *target)
{
	size_t	len;
	char	*tmp;
	int		nb;

	tmp = str;
	nb = 0;
	len = ft_strlen(target);
	while (tmp)
	{
		if ((tmp = ft_strstr(tmp, target)))
		{
			nb++;
			tmp += len;
		}
	}
	return (nb);
}
