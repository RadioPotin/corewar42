/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:07:00 by dapinto           #+#    #+#             */
/*   Updated: 2019/07/18 13:23:45 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_inttabdel(int i, int ***tab)
{
	if (tab == NULL)
		return ;
	while (i >= 0)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i--;
	}
	free(*tab);
	tab = NULL;
}
