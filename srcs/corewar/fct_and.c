/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:37:00 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/14 09:41:57 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	misc_and(unsigned char *types, int *use, t_proc *prc)
{
	if ((types[0] == 1 && (use[0] < 1 || use[0] > 16)) ||
			(types[1] == 1 && (use[1] < 1 || use[1] > 16)))
		return (-1);
	if (use[2] < 1 || use[2] > 16)
		return (-1);
	use[0] = types[0] == 1 ? prc->regs[use[0] - 1] : use[0];
	use[1] = types[1] == 1 ? prc->regs[use[1] - 1] : use[1];
	prc->regs[use[2] - 1] = use[1] & use[0];
	prc->carry = prc->regs[use[2] - 1] == 0 ? 1 : 0;
	return (0);
}

int			and_fct(t_cw *cw, t_proc *prc)
{
	unsigned char	types[4];
	int				use[3];
	int				size;
	int				offset;

	if (get_arg(cw, prc, types) == -1)
		return (increment_pc(prc, types, 0, -1));
	if ((types[0] < 1 || types[0] > 3) || !(size = get_size(types[0], 0)))
		return (increment_pc(prc, types, 0, -1));
	use[0] = get_hexa(cw->arena, prc->pc + 2, size);
	use[0] = types[0] == 3 ? get_hexa(cw->arena, prc->pc + use[0] % IDX_MOD, 4)
			: use[0];
	offset = size;
	if ((types[1] < 1 || types[1] > 3) || !(size = get_size(types[1], 0)))
		return (increment_pc(prc, types, 0, -1));
	use[1] = get_hexa(cw->arena, prc->pc + offset + 2, size);
	use[1] = types[1] == 3 ? get_hexa(cw->arena, prc->pc + use[1] % IDX_MOD, 4)
			: use[1];
	offset += size;
	if ((types[2] != 1) || !(size = get_size(types[2], 0)))
		return (increment_pc(prc, types, 0, -1));
	use[2] = get_hexa(cw->arena, prc->pc + offset + 2, size);
	if (misc_and(types, use, prc) == -1)
		return (increment_pc(prc, types, 0, -1));
	return (increment_pc(prc, types, 0, 0));
}
