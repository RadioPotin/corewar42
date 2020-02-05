/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:46:36 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/13 19:46:14 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		lld_fct(t_cw *cw, t_proc *prc)
{
	unsigned char	types[4];
	int				use[2];
	int				size;
	int				offset;

	if (get_arg(cw, prc, types) == -1)
		return (increment_pc(prc, types, 0, -1));
	if ((types[0] != 2 && types[0] != 3) || !(size = get_size(types[0], 0)))
		return (increment_pc(prc, types, 0, -1));
	use[0] = get_hexa(cw->arena, prc->pc + 2, size);
	use[0] = types[0] == 3 ? get_hexa(cw->arena, prc->pc + use[0], 4) : use[0];
	offset = size;
	if (types[1] != 1 || !(size = get_size(types[1], 0)))
		return (increment_pc(prc, types, 0, -1));
	use[1] = get_hexa(cw->arena, prc->pc + offset + 2, size);
	if (use[1] > 16 || use[1] < 1)
		return (increment_pc(prc, types, 0, -1));
	prc->regs[use[1] - 1] = use[0];
	prc->carry = prc->regs[use[1] - 1] == 0 ? 1 : 0;
	return (increment_pc(prc, types, 0, 0));
}
