/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:50:10 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/14 09:23:36 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	misc_sti(t_cw *cw, unsigned char *types, int *use, t_proc *prc)
{
	use[1] = types[1] == 1 ? prc->regs[use[1] - 1] : use[1];
	use[1] = types[1] == 3 ? get_hexa(cw->arena, prc->pc + use[1], 4) : use[1];
	use[2] = types[2] == 1 ? prc->regs[use[2] - 1] : use[2];
	use[2] = types[2] == 3 ? get_hexa(cw->arena, prc->pc + use[2], 4) : use[2];
	print_in_arena(cw, prc, prc->regs[use[0] - 1], (use[1] + use[2]) % IDX_MOD);
}

int			sti_fct(t_cw *cw, t_proc *prc)
{
	unsigned char	types[4];
	int				use[3];
	int				size;
	int				offset;

	if (get_arg(cw, prc, types) == -1)
		return (increment_pc(prc, types, 1, -1));
	if ((types[0] != 1) || !(size = get_size(types[0], 1)))
		return (increment_pc(prc, types, 1, -1));
	use[0] = get_hexa(cw->arena, prc->pc + 2, size);
	offset = size;
	if ((types[1] < 1 || types[1] > 3) || !(size = get_size(types[1], 1)))
		return (increment_pc(prc, types, 1, -1));
	use[1] = get_hexa(cw->arena, prc->pc + offset + 2, size);
	offset += size;
	if ((types[2] != 1 && types[2] != 2) || !(size = get_size(types[2], 1)))
		return (increment_pc(prc, types, 1, -1));
	use[2] = get_hexa(cw->arena, prc->pc + offset + 2, size);
	if (use[0] > 16 || use[0] < 1 ||
			(types[1] == 1 && (use[1] < 1 || use[1] > 16)))
		return (increment_pc(prc, types, 0, -1));
	if (types[2] == 1 && (use[2] > 16 || use[2] < 1))
		return (increment_pc(prc, types, 0, -1));
	misc_sti(cw, types, use, prc);
	return (increment_pc(prc, types, 1, 0));
}
