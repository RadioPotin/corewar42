/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:25:53 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/15 14:51:05 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	do_processus(t_cw *cw, t_pfct *pft)
{
	t_proc	*prc;

	prc = cw->procs;
	while (prc)
	{
		if (prc->waiting == 0)
		{
			if (prc->ready == 1)
				pft[prc->key - 1](cw, prc);
			else
				prc->pc = (prc->pc + 1) % 4096;
			set_key(cw, prc);
		}
		else
			prc->waiting--;
		prc = prc->next;
	}
}

static int	cp_opt(t_cw *cw)
{
	int		ret;
	int		cp;

	if (cw->cp - 1 == cw->cycles)
	{
		cp = 0;
		system("clear");
		ft_printf("CYCLE \033[33m%d\033[0m\n", cw->cycles);
		ft_hexdump(cw);
		while ((ret = getchar() - '0') != -38 && ret < 10 && ret >= 0)
			cp = cp * 10 + ret;
		if (ret == -21)
			return (-1);
		if (cp)
			cw->cp = cp + 1;
		else
			cw->cp++;
	}
	return (0);
}

static void	check_cycle(t_cw *cw)
{
	death_sentence(cw, cw->procs);
	cw->last_delta++;
	if (cw->nb_lives >= NBR_LIVE || cw->last_delta == MAX_CHECKS)
	{
		cw->last_delta = 0;
		cw->deltas++;
	}
	cw->nb_lives = 0;
	cw->to_die = CYCLE_TO_DIE - cw->deltas * CYCLE_DELTA;
}

int			loop_game(t_cw *cw)
{
	t_pfct	pft[16];

	init_p_key(pft);
	cw->to_die = CYCLE_TO_DIE - 1;
	while (cw->procs && CYCLE_TO_DIE - cw->deltas * CYCLE_DELTA > 0)
	{
		do_processus(cw, pft);
		if (cw->cycles == cw->dump)
		{
			ft_hexdump(cw);
			return (-1);
		}
		if (cw->cp && cp_opt(cw) == -1)
			return (-1);
		cw->cycles++;
		cw->to_die--;
		if (cw->to_die < 0)
			check_cycle(cw);
	}
	return (0);
}
