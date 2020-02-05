/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:38:27 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/13 19:37:08 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		fork_fct(t_cw *cw, t_proc *prc)
{
	int	i;
	int j;

	j = -1;
	if (create_process(cw, prc->player) == -1)
	{
		prc->pc = (prc->pc + 3) % 4096;
		return (-1);
	}
	while (++j < 16)
		cw->procs->regs[j] = prc->regs[j];
	i = get_hexa(cw->arena, prc->pc + 1, 2);
	cw->procs->ready = 1;
	cw->procs->carry = prc->carry;
	cw->procs->pc = absolute_arena(prc->pc + (i % IDX_MOD));
	cw->procs->key = cw->arena[cw->procs->pc];
	if (cw->procs->key >= 1 && cw->procs->key <= 16)
		cw->procs->waiting = cw->times[cw->procs->key - 1] - 1;
	else
		cw->procs->ready = 0;
	cw->procs->live = prc->live;
	prc->pc = (prc->pc + 3) % 4096;
	return (0);
}
