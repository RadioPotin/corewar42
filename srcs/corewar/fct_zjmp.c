/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:56:06 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/13 16:35:57 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		zjmp_fct(t_cw *cw, t_proc *prc)
{
	int				use;

	if (prc->carry == 0)
	{
		prc->pc = (prc->pc + 3) % 4096;
		return (0);
	}
	use = (short int)get_hexa(cw->arena, prc->pc + 1, 2);
	prc->pc = absolute_arena(prc->pc + (use % IDX_MOD));
	return (0);
}
