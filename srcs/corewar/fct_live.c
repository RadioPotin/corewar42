/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:45:56 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/13 19:48:36 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		live_fct(t_cw *cw, t_proc *prc)
{
	int		i;
	char	*champ;
	int		c_nb;
	int		cp;

	i = 0;
	cp = 0;
	prc->live = 1;
	c_nb = get_hexa(cw->arena, prc->pc + 1, 4);
	while (i < cw->players)
	{
		if (cw->player[i].number == c_nb)
		{
			cp = cw->player[i].number;
			champ = cw->player[i].name;
			cw->player[i].last_live = cw->cycles;
		}
		i++;
	}
	cw->nb_lives++;
	prc->pc = (prc->pc + 5) % 4096;
	if (!cw->no_live && cp && !cw->cp)
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
				c_nb, champ);
	return (0);
}
