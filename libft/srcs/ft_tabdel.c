/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:13:51 by evogel            #+#    #+#             */
/*   Updated: 2018/12/07 11:02:24 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(int i, char ***tab)
{
	if (tab == NULL)
		return ;
	while (i >= 0)
	{
		ft_strclr((*tab)[i]);
		ft_strdel(&(*tab)[i]);
		i--;
	}
	free(*tab);
	tab = NULL;
}
