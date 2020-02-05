/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conclude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:19:42 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/13 19:23:20 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		conclude_game(t_cw *cw)
{
	int		i;
	int		gagnant;
	t_play	*tmp;

	gagnant = 0;
	i = 0;
	while (i < cw->players)
	{
		if (cw->player[i].last_live >= gagnant)
		{
			tmp = &cw->player[i];
			gagnant = cw->player[i].last_live;
		}
		i++;
	}
	ft_printf("Contestant %d, \"%s\", has won!\n", tmp->number, tmp->name);
	return (0);
}
